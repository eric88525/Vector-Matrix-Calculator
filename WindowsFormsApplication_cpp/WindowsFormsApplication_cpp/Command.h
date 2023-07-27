#pragma once

#include "DataManager.h"
#include <vector>
#include <stack>
#define NL System::Environment::NewLine


int priority(std::string op);
std::vector<std::string> IntoPost(std::string str);

template<typename T>
T cal(std::string polynomial,  const std::unordered_map<std::string, T> &symbol_table)
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


class ICommand {
protected:
public:
	ICommand() {}
	virtual System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) = 0;
};

class CommandFactory {
	std::unordered_map<std::string, std::shared_ptr<ICommand>> command_map;
public:
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
};


#pragma region VectorCommands
class PrintvCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class NormCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class NormalizationCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class CrossProductCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class ComponentCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class ProjectionCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class  AreatCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class  IsParallelCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class IsOrthogonalCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class AngleCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class PNCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class IsLICommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};

class ObCommand : public ICommand {
public:
	System::String^ Execute(std::vector<std::string>& params, const std::unordered_map <std::string, Vector> &v_lookup, const std::unordered_map <std::string, Matrix> &m_lookup) override;
};
#pragma endregion


#pragma region MatrixCommands

#pragma endregion



