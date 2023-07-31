#include "Command.h"

int priority(std::string& op) {
	switch (op[0]) {
	case '+': case '-': return 1;
	case '*': return 2;
	default: return 0;
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

Vector DotCommand::operate(std::vector<Vector>& operands)
{
	return Dot(operands[0], operands[1]);
}
Vector NormCommand::operate(std::vector<Vector>& operands)
{
	return Norm(operands[0]);
}

Vector NormalizationCommand::operate(std::vector<Vector>& operands)
{
	return Normalization(operands[0]);
}

Vector CrossProductCommand::operate(std::vector<Vector>& operands)
{
	return CrossProduct(operands[0], operands[1]);
}

Vector ComponentCommand::operate(std::vector<Vector>& operands)
{
	return Component(operands[0], operands[1]);
}

Vector ProjectionCommand::operate(std::vector<Vector>& operands)
{
	return Projection(operands[0], operands[1]);
}

Vector AreaCommand::operate(std::vector<Vector>& operands)
{
	return Area(operands[0], operands[1]);
}
Vector AngleCommand::operate(std::vector<Vector>& operands)
{
	return Angle(operands[0], operands[1]);
}

Vector PNCommand::operate(std::vector<Vector>& operands)
{
	return PN(operands[0], operands[1]);
}

System::String^ ObCommand::ToString(std::vector<Vector>& operands)
{
	std::vector<Vector> varr;
	for (const auto& v : operands)
		varr.push_back(v);

	std::vector<Vector> op = Ob(varr);

	System::String^ result_str = "";

	for (Vector& i : op)
		result_str += i.GetResult();

	return result_str;
}

System::String^ IsParallelCommand::ToString(std::vector<Vector>& operands)
{
	return IsParallel(operands[0], operands[1]) ? "Yes" : "No";
}

System::String^ IsOrthogonalCommand::ToString(std::vector<Vector>& operands)
{
	return IsOrthogonal(operands[0], operands[1]) ? "Yes" : "No";
}

System::String^ IsLICommand::ToString(std::vector<Vector>& operands)
{
	return IsLI(operands[0], operands[1]) ? "Yes" : "No";
}


//System::String^ EigenCommand::ToString(std::vector<std::string>& operands, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
//{
//	std::vector<double> eigenValues;
//	Matrix result = cal<Matrix>(operands[0], m_lookup);
//	result = Eigen(result, eigenValues);
//	System::String^ output_temp = "";
//	output_temp += "v =" + NL + result.GetResult() + NL + "d =" + NL;
//
//	for (int i = 0; i < eigenValues.size(); i++) {
//		for (int j = 0; j < eigenValues.size(); j++) {
//			output_temp += (i == j ? eigenValues[i] : 0);
//			output_temp += "\t";
//		}
//		output_temp += NL;
//	}
//	return output_temp;
//}

//System::String^ RrefCommand::ToString(std::vector<std::string>& operands, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
//{
//	Matrix result = cal<Matrix>(operands[0], m_lookup);
//	std::vector<Matrix> rref = Rref(result);
//	System::String^ output_temp = "";
//	output_temp += rref[1].GetResult() + NL;
//	output_temp += rref[0].GetResult() + NL;
//	return output_temp;
//}
//
//System::String^ LeastSquareCommand::ToString(std::vector<std::string>& operands, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
//{
//	Matrix result = LeastSquare(cal<Matrix>(operands[0], m_lookup), cal<Matrix>(operands[1], m_lookup));
//	return result.GetResult();
//}

System::String^ EigenCommand::ToString(std::vector<Matrix>& operands)
{
	std::vector<double> eigenValues;
	Matrix result = Eigen(operands[0], eigenValues);
	System::String^ output_temp = "";
	output_temp += "v =" + NL + result.GetResult() + NL + "d =" + NL;

	for (int i = 0; i < eigenValues.size(); i++) {
		for (int j = 0; j < eigenValues.size(); j++) {
			output_temp += (i == j ? eigenValues[i] : 0);
			output_temp += "\t";
		}
		output_temp += NL;
	}
	return output_temp;
}

System::String^ RankCommand::ToString(std::vector<Matrix>& operands)
{
	return "" + Rank(operands[0]);
}

Matrix TransposeCommand::operate(std::vector<Matrix>& operands)
{
	return Transpose(operands[0]);
}

Matrix SolveMCommand::operate(std::vector<Matrix>& operands)
{
	return Solve(operands[0], operands[1]);
}

Matrix DeterminantsCommand::operate(std::vector<Matrix>& operands)
{
	return Determinants(operands[0]);
}

Matrix InverseCommand::operate(std::vector<Matrix>& operands)
{
	return Inverse(operands[0]);
}

Matrix AdjCommand::operate(std::vector<Matrix>& operands)
{
	return Adj(operands[0]);
}

System::String^ PmCommand::ToString(std::vector<Matrix>& operands)
{
	double db = 0;
	Matrix result = Pm(operands[0], db);
	return "v = " + NL + result.GetResult() + NL + "d = " + NL + db;
}

System::String^ RrefCommand::ToString(std::vector<Matrix>& operands)
{
	std::vector<Matrix> rref = Rref(operands[0]);
	System::String^ output_temp = "";
	output_temp += rref[1].GetResult() + NL;
	output_temp += rref[0].GetResult() + NL;
	return output_temp;
}


System::String^ LeastSquareCommand::ToString(std::vector<Matrix>& operands)
{
	Matrix result = LeastSquare(operands[0], operands[1]);
	return result.GetResult();
}
