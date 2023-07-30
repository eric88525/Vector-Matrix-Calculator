#pragma once
#include "Command.h"
#include <set>

class Token;
class Caculation;

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
	friend class Caculation;

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

class Caculation {
	CommandFactory command_factory_;
public:

	Caculation(CommandFactory command_factory) :command_factory_(command_factory) {}
	Caculation() {};

	int TokenPriority(const  Token& token);
	/**
	 * Converts an infix expression to postfix notation.
	 *
	 * @param str The infix expression to convert.
	 * @return The equivalent postfix expression.
	 */
	std::vector<Token> IntoPost(std::vector<Token> tokens);
	std::vector<Token> Lex(std::string expression);

	inline bool IsCommand(const std::string& token) {
		return command_factory_.IsCommand(token);
	}

	TokenType GetTokenType(std::string operand);
};