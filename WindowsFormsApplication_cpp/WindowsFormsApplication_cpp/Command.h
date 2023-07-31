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
	NormCommand() {
		operand_count_ = 1;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class NormalizationCommand : public ICommand {
public:
	NormalizationCommand() {
		operand_count_ = 1;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class CrossProductCommand : public ICommand {
public:
	CrossProductCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class ComponentCommand : public ICommand {
public:
	ComponentCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class ProjectionCommand : public ICommand {
public:
	ProjectionCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class  AreaCommand : public ICommand {
public:
	AreaCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class AngleCommand : public ICommand {
public:
	AngleCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class PNCommand : public ICommand {
public:
	PNCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::Operand;
	}
	Vector operate(std::vector<Vector>& operands) override;
};

class ObCommand : public ICommand {
public:
	ObCommand() {
		operand_count_ = -1;
		return_type_ = ReturnType::String;
	}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class  IsParallelCommand : public ICommand {
public:
	IsParallelCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::String;
	}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class IsOrthogonalCommand : public ICommand {
public:
	IsOrthogonalCommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::String;
	}
	System::String^ ToString(std::vector<Vector>& operands) override;
};

class IsLICommand : public ICommand {
public:
	IsLICommand() {
		operand_count_ = 2;
		return_type_ = ReturnType::String;
	}
	System::String^ ToString(std::vector<Vector>& operands) override;
};
#pragma endregion


//#pragma region MatrixCommands
//class PrintmCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class RankCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class TransposeCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class SolveMCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class DeterminantsCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class InverseCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class AdjCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class PmCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class EigenCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class RrefCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//
//class LeastSquareCommand : public ICommand {
//public:
//	System::String^ ToString(std::vector<std::string>& operands, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup) override;
//};
//#pragma endregion



