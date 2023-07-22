#include "WindowsForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WindowsFormsApplication_cpp::WindowsForm windowsForm;
	Application::Run(% windowsForm);
}
int priority(std::string op) {
	switch (op[0]) {
	case '+': case '-': return 1;
	case '*': return 2;
	default:            return 0;
	}
}
/**
 * Converts an infix expression to postfix notation.
 *
 * @param str The infix expression to convert.
 * @return The equivalent postfix expression.
 */
std::vector<std::string> IntoPost(std::string str) {

	std::stack<std::string> op_stack;  // The stack used for storing operators.
	std::vector<std::string> postfix;  // The resulting postfix expression.

	std::string operand = "";

	// Iterate through each character in the input string.
	for (int i = 0; i < str.length(); i++) {

		std::string op = { str[i] };
		std::string var_name = "";

		switch (str[i]) {
		case '(':  // Push '(' onto the operator stack.
			op_stack.push(op);
			break;
		case '+': case '-': case '*':
			// Pop operators with higher or equal priority from the stack and append them to the postfix expression.
			while (!op_stack.empty() && priority(op_stack.top()) >= priority(op)) {
				postfix.push_back(op_stack.top());
				op_stack.pop();
			}
			op_stack.push(op);  // Push the current operator onto the stack.
			break;
		case ')':
			// Pop operators from the stack and append them to the postfix expression until '(' is encountered.
			while (op_stack.top() != "(") {
				postfix.push_back(op_stack.top());
				op_stack.pop();
			}
			if (op_stack.top() == "(") op_stack.pop();  // Remove the '(' from the stack.
			break;
		case 'v': case 'm':
			// Append operands directly to the postfix expression.
			var_name = str[i];
			while (str[++i] != ']') {
				var_name.push_back(str[i]); // variable name, e.g. v[5]
			}
			var_name.push_back(']');
			postfix.push_back(var_name);
			break;
		default:
			break;
		}
	}
	while (!op_stack.empty()) {
		postfix.push_back(op_stack.top());
		op_stack.pop();
	}

	return postfix;  // Return the converted postfix expression.
}

template <typename T>
T cal(std::string polynomial, std::unordered_map<std::string, T> v_lookup) {

	//if (vectors.size() == 0)throw Vectors_empty;

	std::vector<std::string> post = IntoPost(polynomial);
	std::stack<T> op_stk;

	for (auto const& op : post) {

		if (op.size() > 1) {
			op_stk.push(v_lookup[op]);
		}
		else {
			auto left = op_stk.top();
			op_stk.pop();
			auto right = op_stk.top();
			op_stk.pop();
			
			switch (op[0]){
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