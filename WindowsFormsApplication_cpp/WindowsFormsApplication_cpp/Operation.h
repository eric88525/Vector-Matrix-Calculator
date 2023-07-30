#pragma once
#include "Command.h"
#include <set>

enum class TokenType
{
	kOperator,
	kCommand,
	kOperand,
	kVector,
	kMatrix
};


class Token {
private:
	TokenType  type_;
	std::string value_;
	Vector vector_data_;
	Matrix matrix_data_;
public:

	Token() {};
	Token(TokenType type, std::string value) : type_(type), value_(value) {};
	void SetValue(std::string value) { value_ = value; }
	void SetVector(Vector data) { vector_data_ = data; };
	void SetMatrix(Matrix data) { matrix_data_ = data; };
};

class Operation {

public:

	CommandFactory command_factory_;
	Operation(CommandFactory command_factory) :command_factory_(command_factory) {}

	int priority(std::string op) {

		switch (op[0]) {
		case '+': case '-': return 1;
		case '*': return 2;
		default:
			return 0; // variable
		}
	}
	/**
	 * Converts an infix expression to postfix notation.
	 *
	 * @param str The infix expression to convert.
	 * @return The equivalent postfix expression.
	 */
	std::vector<std::string> IntoPost(std::vector<std::string> tokens) {

		std::stack<std::string> op_stack;  // The stack used for storing operators.
		std::vector<std::string> postfix;  // The resulting postfix expression.

		std::string operand = "";

		// Iterate through each character in the input string.
		for (auto token : tokens) {

			if (token == "(") {
				op_stack.push(token);
			}
			else if (token == ")") {
				// Pop operators from the stack and append them to the postfix expression until '(' is encountered.
				while (!op_stack.empty() && op_stack.top() != "(") {
					postfix.push_back(op_stack.top());
					op_stack.pop();
				}
				if (!op_stack.empty() && op_stack.top() == "(") op_stack.pop();  // Remove the '(' from the stack.
				break;
			}
			else if (IsCommand(token)) {
				op_stack.push(token);
			}
			else {
				int pri = priority(token);

				if (pri == 0) {
					postfix.push_back(token);
				}
				else { // operator
					while (!op_stack.empty() && priority(op_stack.top()) >= pri) {
						postfix.push_back(op_stack.top());
						op_stack.pop();
					}
					op_stack.push(token);  // Push the current operator onto the stack.
				}
			}
		}
		while (!op_stack.empty()) {
			postfix.push_back(op_stack.top());
			op_stack.pop();
		}
		return postfix;  // Return the converted postfix expression.
	}
	std::vector<Token> Parse(std::string expression)
	{
		std::string operand = "";
		std::vector<Token> tokens;
		// Iterate through each character in the input string.
		for (int i = 0; i < expression.length(); i++) {
			std::string op = { expression[i] };
			switch (expression[i]) {
			case '(':case '+': case '-': case '*':case ')':case ',':
				if (operand.size()) {
					TokenType t_type = GetTokenType(operand);
					tokens.push_back(Token(t_type, operand));
				}
				tokens.push_back(Token(TokenType::kOperator, op));
				operand = "";
				break;
			case ' ':
				break;
			default:
				operand += expression[i];
				break;
			}
		}
		if (operand.size()) {
			TokenType t_type = GetTokenType(operand);
			tokens.push_back(Token(t_type, operand));
			operand = "";
		}
		return tokens;
	}

	inline bool IsCommand(const std::string& token) {
		return command_factory_.IsCommand(token);
	}

	TokenType GetTokenType(std::string operand) {

		TokenType t_type;
		if (operand[0] == 'v')
			t_type = TokenType::kVector;
		else if (operand[0] == 'm')
			t_type = TokenType::kMatrix;
		else if (IsCommand(operand))
			t_type = TokenType::kCommand;
		else
			t_type = TokenType::kOperand;

		return t_type;
	}
	template<typename T>
	T cal(std::string polynomial, const std::unordered_map<std::string, T>& symbol_table)
	{
		std::vector<std::string> post = IntoPost(polynomial);
		std::stack<T> op_stk;

		for (auto const& op : post) {

			if (op.size() > 1) {
				if (symbol_table.find(op) != symbol_table.end()) {
					T item = symbol_table.at(op);
					op_stk.push(item);
				}
				else {
					throw vector_name_error;
				}
			}
			else {
				auto left = op_stk.top();
				op_stk.pop();
				auto right = op_stk.top();
				op_stk.pop();

				switch (op[0]) {
				case '+':
					op_stk.push(left + right);
					break;
				case '-':
					op_stk.push(left - right);
					break;
				case '*':
					op_stk.push(left * right);
					break;
				default:
					throw op_error;
				}
			}
		}
		return op_stk.top();
	}
};