#include "WindowsForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WindowsFormsApplication_cpp::WindowsForm windowsForm;
	Application::Run(%windowsForm);
}
int priority(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default:            return 0;
	}
}
/**
 * Converts an infix expression to postfix notation.
 *
 * @param str The infix expression to convert.
 * @return The equivalent postfix expression.
 */
std::string IntoPost(std::string str) {
	Vector v;  // TODO: Document the purpose of the 'Vector v' variable.
	std::string stack = "";  // The stack used for storing operators.
	std::string postfix = "";  // The resulting postfix expression.

	// Iterate through each character in the input string.
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':  // Push '(' onto the operator stack.
			stack.push_back(str[i]);
			break;
		case '+': case '-': case '*':
			// Pop operators with higher or equal priority from the stack and append them to the postfix expression.
			while (stack.length() && priority(stack[stack.length() - 1]) >= priority(str[i])) {
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			stack.push_back(str[i]);  // Push the current operator onto the stack.
			break;
		case ')':
			// Pop operators from the stack and append them to the postfix expression until '(' is encountered.
			while (stack[stack.length() - 1] != '(') {
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			if (stack[stack.length() - 1] == '(') stack.pop_back();  // Remove the '(' from the stack.
			break;
		case '$':
			// Append operands directly to the postfix expression.
			while (str[i] != ']') {
				postfix.push_back(str[i]);
				i++;
			}
			postfix.push_back(']');
			break;
		default:
			break;
		}
	}

	postfix += stack;  // Append any remaining operators in the stack to the postfix expression.

	// Remove any remaining parentheses from the postfix expression.
	for (int l = 0; l < postfix.length(); l++) {
		if (postfix[l] == '(' || postfix[l] == ')') postfix.erase(l, 1);
	}

	return postfix;  // Return the converted postfix expression.
}

Vector calV(std::string str, std::vector<Vector> vectors) {
	if (vectors.size() == 0)throw Vectors_empty;
	str = IntoPost(str);
	std::vector<Vector> stack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '$') {
			std::string vname = "";
			while (str[i] != ']')
			{
				if (str[i] != '[')
					vname.push_back(str[i]);
				i++;
			}
			stack.push_back(getV(vname, vectors));
		}
		else {
			if (str[i] == '+') {
				stack[stack.size() - 2] = stack[stack.size() - 2] + stack[stack.size() - 1];
			}
			else if (str[i] == '-') {
				stack[stack.size() - 2] = stack[stack.size() - 2] - stack[stack.size() - 1];
			}
			else if (str[i] == '*') {
				stack[stack.size() - 2] = stack[stack.size() - 2] * stack[stack.size() - 1];
			}
			stack.pop_back();
		}
	}
	return stack[0];
}

Matrix calM(std::string str, std::vector<Matrix> matrices)
{
	if (matrices.size() == 0)throw Matrices_empty;
	str = IntoPost(str);
	std::vector<Matrix> stack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '$') {
			std::string vname = "";
			while (str[i] != ']')
			{
				if (str[i] != '[')
					vname.push_back(str[i]);
				i++;
			}
			stack.push_back(getM(vname, matrices));
		}
		else {
			if (str[i] == '+') {
				stack[stack.size() - 2] = stack[stack.size() - 2] + stack[stack.size() - 1];
			}
			else if (str[i] == '-') {
				stack[stack.size() - 2] = stack[stack.size() - 2] - stack[stack.size() - 1];
			}
			else if (str[i] == '*') {
				stack[stack.size() - 2] = stack[stack.size() - 2] * stack[stack.size() - 1];
			}
			stack.pop_back();
		}
	}
	return stack[0];
}

Vector getV(std::string str, std::vector<Vector> vectors)
{
	for (auto i : vectors) {
		if (i.name == str)return i;
	}
	throw Vector_name_error;
}

Matrix getM(std::string str, std::vector<Matrix> matrices)
{
	for (auto i : matrices) {
		if (i.name == str)return i;
	}
	throw Matrix_name_error;
}
