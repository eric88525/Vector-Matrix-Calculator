#pragma once

#include "DataManager.h"
#include <vector>
#include <stack>
#define NL System::Environment::NewLine


enum class ReturnType {
	Operand,
	String
};

class ICommand {
protected:

public:
	int operand_count_;
	ReturnType return_type_;
	ICommand() {}
	ICommand(int operand_count, ReturnType return_type) :operand_count_(operand_count), return_type_(return_type) {}

	virtual System::String^ ToString(std::vector<Vector>& operands) {
		return "";
	};
	virtual System::String^ ToString(std::vector<Matrix>& operands) {
		return "";
	}
	virtual  Vector operate(std::vector<Vector>& operands) {
		return Vector();
	}
	virtual Matrix operate(std::vector<Matrix>& operands) {
		return Matrix();
	}
};

class CommandFactory {
	std::unordered_map<std::string, std::shared_ptr<ICommand>> command_map;
public:
	CommandFactory() {};
	CommandFactory(const CommandFactory& t) :command_map(t.command_map) {}
	// Register a command with the factory
	void RegisterCommand(const std::string& command_name, std::shared_ptr<ICommand> command) {
		command_map[command_name] = command;
	}
	// Create a command based on the given command name
	std::shared_ptr<ICommand> CreateCommand(const std::string& command_name) {
		auto it = command_map.find(command_name);
		if (it != command_map.end()) {
			return it->second;
		}
		// Throw an exception or return nullptr if the command is not found
		// You can decide on the behavior based on your use case.
		// For simplicity, I'll return nullptr here.
		return nullptr;
	}
	bool IsCommand(const std::string& str) { return command_map.count(str); }
};


#pragma region VectorCommands
class DotCommand : public ICommand {
public:
	DotCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class NormCommand : public ICommand {
public:
	NormCommand() :ICommand(1, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class NormalizationCommand : public ICommand {
public:
	NormalizationCommand() : ICommand(1, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class CrossProductCommand : public ICommand {
public:
	CrossProductCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class ComponentCommand : public ICommand {
public:
	ComponentCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class ProjectionCommand : public ICommand {
public:
	ProjectionCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class  AreaCommand : public ICommand {
public:
	AreaCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class AngleCommand : public ICommand {
public:
	AngleCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class PNCommand : public ICommand {
public:
	PNCommand() : ICommand(2, ReturnType::Operand) {}
	Vector operate(std::vector<Vector>& operands) override;
};

class ObCommand : public ICommand {
public:
	ObCommand() : ICommand(-1, ReturnType::String) {}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class  IsParallelCommand : public ICommand {
public:
	IsParallelCommand() : ICommand(2, ReturnType::String) {}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class IsOrthogonalCommand : public ICommand {
public:
	IsOrthogonalCommand() : ICommand(2, ReturnType::String) {}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class IsLICommand : public ICommand {
public:
	IsLICommand() : ICommand(2, ReturnType::String) {}
	System::String^ ToString(std::vector<Vector>& operands) override;
};
#pragma endregion


#pragma region MatrixCommands
class EigenCommand :public ICommand {
public:
	EigenCommand():ICommand(1, ReturnType::String) {}
	System::String^ ToString(std::vector<Matrix>& operands) override;
};

class RankCommand : public ICommand {
public:
	RankCommand(): ICommand(1, ReturnType::String){}
	System::String^ ToString(std::vector<Matrix>& operands) override;
};

class TransposeCommand : public ICommand {
public:
	TransposeCommand():ICommand(1, ReturnType::Operand) {}
	Matrix operate(std::vector<Matrix>& operands) override;
};

class SolveMCommand : public ICommand {
public:
	SolveMCommand() :ICommand(2, ReturnType::Operand) {}
	Matrix operate(std::vector<Matrix>& operands) override;
};

class DeterminantsCommand : public ICommand {
public:
	DeterminantsCommand():ICommand(1, ReturnType::Operand) {}
	Matrix operate(std::vector<Matrix>& operands) override;
};

class InverseCommand : public ICommand {
public:
	InverseCommand() :ICommand(1, ReturnType::Operand) {}
	Matrix operate(std::vector<Matrix>& operands) override;
};

class AdjCommand : public ICommand {
public:
	AdjCommand() :ICommand(1, ReturnType::Operand) {}
	Matrix operate(std::vector<Matrix>& operands) override;
};

class PmCommand : public ICommand {
public:
	PmCommand() :ICommand(1, ReturnType::String) {}
	System::String^ ToString(std::vector<Matrix>& operands) override;
};

class RrefCommand : public ICommand {
public:
	RrefCommand() :ICommand(1, ReturnType::String) {}
	System::String^ ToString(std::vector<Matrix>& operands) override;
};

class LeastSquareCommand : public ICommand {
public:
	LeastSquareCommand() :ICommand(2, ReturnType::String) {}
	System::String^ ToString(std::vector<Matrix>& operands) override;
};
#pragma endregion



