#pragma once
#include "Command.h"

class Token;
class Caculator;

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
	std::string value_;
	int index_;
	TokenType  type_;
public:
	friend class Caculator;

	Token() {};
	Token(std::string value) :value_(value), index_(0) {};
	Token(TokenType type, std::string value) : type_(type), value_(value), index_(0) {};

	void SetValue(std::string value) { value_ = value; }
	void SetIndex(int index) { index_ = index; }

	TokenType GetType() const { return type_; }
	std::string GetValue() const { return value_; }

	friend const bool operator==(const Token& x, const std::string value) {
		return x.value_ == value;
	}
	friend const bool operator!=(const Token& x, const std::string value) {
		return x.value_ != value;
	}
};

class Caculator {
	CommandFactory command_factory_;
public:

	Caculator(CommandFactory command_factory) :command_factory_(command_factory) {}
	Caculator() {};

	int TokenPriority(const  Token& token);
	std::vector<Token> IntoPost(std::vector<Token> tokens);
	std::vector<Token> Lex(std::string expression);

	inline bool IsCommand(const std::string& token) {
		return command_factory_.IsCommand(token);
	}

	TokenType GetTokenType(std::string operand);
	template<typename T>
	T caculate(std::vector<Token> post_tokens, const std::unordered_map<std::string, T>& symbol_table, System::String^& result_str);

};

template<typename T>
T Caculator::caculate(std::vector<Token> post_tokens, const std::unordered_map<std::string, T>& symbol_table, System::String^& result_str)
{
	std::stack<T> op_stk;

	for (const auto& token : post_tokens) {

		TokenType t_type = token.GetType();

		if (t_type == TokenType::kOperator)
		{
			std::vector<T> operands;
			T right = op_stk.top();
			op_stk.pop();
			T left = op_stk.top();
			op_stk.pop();

			switch (token.GetValue()[0]) {
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
				throw std::runtime_error("Invalid operator");
			}
		}
		else if (t_type == TokenType::kCommand)
		{
			auto cmd = command_factory_.CreateCommand(token.value_);
			std::vector<T> operands;
			for (int i = 0; i < cmd->operand_count_; i++) {
				operands.insert(operands.begin(), op_stk.top());
				op_stk.pop();
			}
			if (cmd->return_type_ == ReturnType::String) {
				result_str = cmd->ToString(operands);
				return T();
			}
			else if (cmd->return_type_ == ReturnType::Operand) {
				op_stk.push(cmd->operate(operands));
			}
		}
		else if (t_type == TokenType::kVector || t_type == TokenType::kMatrix) {
			op_stk.push(symbol_table.at(token.value_));
		}
	}

	if (op_stk.size() == 1) {
		return op_stk.top();
	}
	else {
		throw std::runtime_error("Not a valid operation");
	}
}

