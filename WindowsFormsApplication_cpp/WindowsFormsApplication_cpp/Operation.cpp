#include "Operation.h"

int Calculator::TokenPriority(const Token& token)
{
	if (token == "+" || token == "-") {
		return 1;
	}
	else if (token == "*" || token == "/") {
		return 2;
	}
	else {
		return 0;
	}
}

/**
 * Converts an infix expression to postfix notation.
 *
 * @param str The infix expression to convert.
 * @return The equivalent postfix expression.
 */
std::vector<Token> Calculator::IntoPost(std::vector<Token> tokens)
{

	std::stack<Token> token_stack;  // The stack used for storing operators.
	std::vector<Token> postfix;  // The resulting postfix expression.

	// Iterate through each character in the input string.
	for (const auto&  token : tokens) {

		switch (token.GetType())
		{
		case TokenType::kOperator:
			if (token == "(") {
				token_stack.push(token);
			}
			else if (token == ")") {
				// Pop operators from the stack and append them to the postfix expression until '(' is encountered.
				while (!token_stack.empty() && token_stack.top() != "(") {
					postfix.push_back(token_stack.top());
					token_stack.pop();
				}
				if (!token_stack.empty() && token_stack.top() == "(") token_stack.pop();  // Remove the '(' from the stack.
				break;
			}
			else if (token == ",") {
				while (!token_stack.empty() && token_stack.top() != "(") {
					if (token_stack.top() != "(")
						postfix.push_back(token_stack.top());
					token_stack.pop();
				}
			}
			else {
				int pri = TokenPriority(token);
				while (!token_stack.empty() && TokenPriority(token_stack.top()) >= pri) {
					postfix.push_back(token_stack.top());
					token_stack.pop();
				}
				token_stack.push(token);  // Push the current operator onto the stack.	
			}
			break;
		case TokenType::kCommand:
			token_stack.push(token);
			break;
		case TokenType::kVector: case TokenType::kMatrix: case TokenType::kOperand:
			postfix.push_back(token);
			break;
		default:
			break;
		}
	}
	while (!token_stack.empty()) {
		postfix.push_back(token_stack.top());
		token_stack.pop();
	}
	return postfix;  // Return the converted postfix expression.
}

std::vector<Token> Calculator::Lex(std::string expression)
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

TokenType Calculator::GetTokenType(std::string operand)
{
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
