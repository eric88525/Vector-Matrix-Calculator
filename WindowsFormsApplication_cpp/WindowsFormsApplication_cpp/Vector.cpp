#include"Vector.h"

System::String^ Vector::GetResult()
{
	System::String^ outputTemp = "";
	outputTemp += "[";
	for (unsigned int j = 0; j < data.size(); j++)
	{
		System::String^ buff = data[j].ToString();
		outputTemp += buff;
		if (j != data.size() - 1)
			outputTemp += ", ";
	}
	outputTemp += "]" + System::Environment::NewLine;
	return outputTemp;
}


const Vector operator+(const Vector& x, const Vector& y) {

	std::vector<double> data;
	if (x.IsConstant()) {
		for (int i = 0; i < y.data.size(); i++) {
			data.push_back(y.data[i] + x.data[0]);
		}
	}
	else if (y.IsConstant()) {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] + y.data[0]);
		}
	}

	if (x.GetDim() != y.GetDim()) {
		throw std::invalid_argument("Error: Vectors must have the same dimensions for the '+' operator.");
	}
	else {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] + y.data[i]);
		}
	}
	return Vector(data);
}

const Vector operator-(const Vector& x, const Vector& y) {

	std::vector<double> data;
	if (x.IsConstant()) {
		for (int i = 0; i < y.data.size(); i++) {
			data.push_back(y.data[i] - x.data[0]);
		}
	}
	else if (y.IsConstant()) {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] - y.data[0]);
		}
	}
	else if (x.GetDim() != y.GetDim()) {
		throw std::invalid_argument("Error: Vectors must have the same dimensions for the '-' operator.");
	}
	else {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] - y.data[i]);
		}
	}
	return Vector(data);
}


const Vector operator*(const Vector& x, const Vector& y) {

	std::vector<double> data;
	if (x.IsConstant()) {
		for (int i = 0; i < y.data.size(); i++) {
			data.push_back(y.data[i] * x.data[0]);
		}
	}
	else if (y.IsConstant()) {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] * y.data[0]);
		}
	}
	else if (x.GetDim() != y.GetDim()) {
		throw std::invalid_argument("Error: Vectors must have the same dimensions or one of the vectors must be 1D for the '*' operator.");
	}
	else {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(y.data[i] * x.data[i]);
		}
	}
	return Vector(data);
}

const Vector Dot(const Vector& x, const Vector& y)
{
	if (x.GetDim() != y.GetDim())
		throw std::invalid_argument("Error: The dot product requires two vectors with the same dimensions.");

	double sum = 0;
	for (int i = 0; i < x.data.size(); i++) {
		sum += y.data[i] * x.data[i];
	}
	return Vector(sum);
}

const Vector Norm(const Vector& x) {
	double sum = 0.0;
	for (int i = 0; i < x.data.size(); i++) {
		sum += std::abs(pow(x.data[i], 2));
	}
	return Vector(sqrt(sum));
}
const Vector Normalization(const Vector& x) {
	double sum = 0;
	std::vector<double>data;
	for (auto i : x.data) {
		sum += i * i;
	}
	sum = sqrt(sum);
	data = x.data;
	for (auto& i : data) {
		i /= sum;
	}
	return Vector(data);
}

const Vector CrossProduct(const Vector& x, const Vector& y)
{
	if (x.GetDim() != 3 || y.GetDim() != 3) {
		throw std::invalid_argument("Error: The cross product requires two 3-dimensional vectors.");
	}
	double i = x.data[1] * y.data[2] - y.data[1] * x.data[2];
	double j = y.data[0] * x.data[2] - x.data[0] * y.data[2];
	double k = x.data[0] * y.data[1] - y.data[0] * x.data[1];
	std::vector<double> data = { i, j, k };
	return Vector(data);
}

const Vector Component(const Vector& x, const Vector& y)
{
	Vector vec;
	vec = Dot(x, y);
	double n = Norm(y).data[0];
	vec.data[0] /= n;
	return vec;
}

const Vector Projection(const Vector& x, const  Vector& y)
{
	Vector vec;
	vec = Component(x, y);
	vec = vec * Normalization(y);
	return vec;
}

const Vector Area(const Vector& x, const Vector& y)
{
	// for eval: https://onlinemschool.com/math/assistance/vector/triangle_area/
	if (x.GetDim() != y.GetDim())
		throw std::invalid_argument("Error: The area calculation requires two vectors with the same dimensions (either 2D or 3D).");

	if (x.GetDim() == 2) {
		double result = abs(x.data[0] * y.data[1] - x.data[1] * y.data[0]);
		return Vector(result);
	}
	else if (x.GetDim() == 3) {
		double c = Norm(x).data[0];
		double a = Component(x, y).data[0];
		double b = sqrt(c * c - a * a);
		double result = (Norm(y).data[0]) * b / 2;
		return Vector(result);
	}
	else {
		throw std::invalid_argument("Error: The area calculation requires two vectors with the same dimensions (either 2D or 3D).");
	}
}

const Vector PN(const Vector& x, const Vector& y)
{
	return CrossProduct(x, y);
}

const bool IsParallel(const Vector& x, const Vector& y)
{
	if (x.GetDim() != y.GetDim())
		return false;

	double rate = -8763.30678;
	for (int i = 0; i < x.data.size(); i++) {
		if (!(x.data[i] == 0 || y.data[i] == 0)) {
			if (rate == -8763.30678) {
				rate = y.data[i] / x.data[i];
			}
			else if ((abs(rate * x.data[i] - y.data[i]) > misRange)) {
				return false;
			}
		}
	}
	if (rate != -8763.30678)
		return true;
	else return false;
}

const bool IsOrthogonal(const Vector& x, const Vector& y)
{
	double sum = 0;
	for (int i = 0; i < x.data.size(); i++) {
		sum += x.data[i] * y.data[i];
	}
	if (!sum)return true;
	return false;
}

/*
  Calculates the angle in degrees between two vectors x and y.

  This function implements the formula to find the angle between two vectors
  using the dot product and the norms of the vectors. The formula used can be
  found at: https://mathsathome.com/angle-between-two-vectors/

  @param x The first vector.
  @param y The second vector.

  @return A Vector object containing the angle between the two input vectors in degrees.

  @remarks
  - The input vectors (x and y) are expected to be of the same dimension.
*/
const Vector Angle(const Vector& x, const Vector& y)
{

	if (x.GetDim() != y.GetDim())
		throw std::invalid_argument("Error: The angle calculation requires two vectors with the same dimensions.");

	Vector vec;       // Variable to store the dot product of x and y
	double result;    // Variable to store the final result in degrees

	// Calculate the dot product of x and y and store it in 'vec'
	vec = Dot(x, y);

	// Normalize the dot product by dividing it by the product of the magnitudes of x and y
	for (auto& i : vec.data) {
		i = i / ((Norm(x).data[0]) * (Norm(y).data[0]));
	}

	// Calculate the angle in radians using the arccosine function and convert it to degrees
	result = acos(vec.data[0]) * 180.0 / PI;

	// Create a new Vector object containing the angle and return it
	return Vector(result);
}


const bool IsLI(const Vector& x, const Vector& y)
{
	if (x.GetDim() != y.GetDim())
		std::invalid_argument("Error: The isli calculation requires two vectors with the same dimensions.");
	return !IsParallel(x, y);
}

const std::vector<Vector> Ob(std::vector<Vector>list)
{
	list[0] = Normalization(list[0]);
	for (int i = 0; i < list.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			list[i] = list[i] - Projection(list[i], list[j]);
		}
		list[i] = Normalization(list[i]);
	}
	return list;
}