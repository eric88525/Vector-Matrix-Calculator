#include "Command.h"

int priority(std::string &op) {
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


System::String^ PrintvCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector result = cal<Vector>(params[0], v_lookup);
	return result.GetResult();
}

System::String^ NormCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector result = Norm(cal<Vector>(params[0], v_lookup));
	return result.GetResult();
}

System::String^ NormalizationCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector result = cal<Vector>(params[0], v_lookup);
	result = Normalization(result);
	return result.GetResult();
}

System::String^ CrossProductCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector result = CrossProduct(left, right);
	return result.GetResult();
}

System::String^ ComponentCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector result = Component(left, right);
	return result.GetResult();
}

System::String^ ProjectionCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector result = Projection(left, right);
	return result.GetResult();
}

System::String^ AreaCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector area = Area(left, right);
	return area.GetResult();
}

System::String^ IsParallelCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	return IsParallel(left, right) ? "Yes" : "No" + NL;

}

System::String^ IsOrthogonalCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	return IsOrthogonal(left, right) ? "Yes" : "No" + NL;
}

System::String^ AngleCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector result = Angle(left, right);
	return "theta = " + result.GetResult() + NL;
}

System::String^ PNCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	Vector result = PN(left, right);
	return result.GetResult();
}

System::String^ IsLICommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	Vector left = cal<Vector>(params[0], v_lookup);
	Vector right = cal<Vector>(params[1], v_lookup);
	return IsLI(left, right) ? "Yes" : "No" + NL;
}

System::String^ ObCommand::ToString(std::vector<std::string>& params, const std::unordered_map <std::string, Vector>& v_lookup, const std::unordered_map <std::string, Matrix>& m_lookup)
{
	std::vector<Vector> varr;
	for (int i = 0; i < params.size(); i++) {
		varr.push_back(cal<Vector>(params[i], v_lookup));
	}
	std::vector<Vector> op = Ob(varr);

	System::String^ result_str = "";
	for (Vector& i : op) {
		result_str += i.GetResult();
	}
	return result_str;
}

System::String^ PrintmCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	return result.GetResult();
}

System::String^ RankCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	return Rank(result) + NL;
}

System::String^ TransposeCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = Transpose(cal<Matrix>(params[0], m_lookup));
	return result.GetResult();
}

System::String^ SolveMCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix left = cal<Matrix>(params[0], m_lookup);
	Matrix right = cal<Matrix>(params[1], m_lookup);
	Matrix result = left / right;
	return result.GetResult();
}

System::String^ DeterminantsCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup) / cal<Matrix>(params[1], m_lookup);
	double db = Determinants(result);
	return db + NL;
}

System::String^ InverseCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	result = Inverse(result);
	return result.GetResult();
}

System::String^ AdjCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	result = Adj(result);
	return result.GetResult();
}

System::String^ PmCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	double db = 0;
	result = Pm(result, db);
	return "v = " + NL + result.GetResult() + NL + "d = " + NL + db + NL;
}

System::String^ EigenCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	std::vector<double> eigenValues;
	Matrix result = cal<Matrix>(params[0], m_lookup);
	result = Eigen(result, eigenValues);
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

System::String^ RrefCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = cal<Matrix>(params[0], m_lookup);
	std::vector<Matrix> rref = Rref(result);
	System::String^ output_temp = "";
	output_temp += rref[1].GetResult() + NL;
	output_temp += rref[0].GetResult() + NL;
	return output_temp;
}

System::String^ LeastSquareCommand::ToString(std::vector<std::string>& params, const std::unordered_map<std::string, Vector>& v_lookup, const std::unordered_map<std::string, Matrix>& m_lookup)
{
	Matrix result = LeastSquare(cal<Matrix>(params[0], m_lookup), cal<Matrix>(params[1], m_lookup));
	return result.GetResult();
}

