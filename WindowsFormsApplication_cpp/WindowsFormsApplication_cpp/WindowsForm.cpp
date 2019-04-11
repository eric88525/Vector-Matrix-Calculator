#include "WindowsForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
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
std::string IntoPost(std::string str) {
	Vector v;
	std::string stack = "";
	std::string postfix = "";
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':     // 運算子堆疊 	
			stack.push_back(str[i]);
			break;
		case '+': case '-': case '*':

			while (stack.length() && priority(stack[stack.length() - 1]) >= priority(str[i])) {
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			stack.push_back(str[i]); // 存入堆疊 
			break;
		case ')':
			while (stack[stack.length() - 1] != '(') { // 遇 ) 輸出至 ( 
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			if (stack[stack.length() - 1] == '(') stack.pop_back();
			break;
		case '$':  // 運算元直接輸出 
			while (str[i] != ']')
			{
				postfix.push_back(str[i]);
				i++;
			}
			postfix.push_back(']');
			break;
		default:
			break;
		}
	}
	postfix += stack;
	for (int l = 0; l < postfix.length(); l++) {
		if (postfix[l] == '(' || postfix[l] == ')')postfix.erase(l, 1);
	}
	return postfix;
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
	return Matrix();
}

Vector getV(std::string str, std::vector<Vector> vectors)
{
	for (auto i : vectors) {
		if (i.Name == str)return i;
	}
	
	throw Vector_name_error;
	return Vector();
}

Matrix getM(std::string str, std::vector<Matrix> matrices)
{
	for (auto i : matrices) {
		if (i.Name == str)return i;
	}
	throw Matrix_name_error;
	return Matrix();
}
