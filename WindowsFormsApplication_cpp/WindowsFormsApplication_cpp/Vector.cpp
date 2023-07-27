#include"Vector.h"

System::String^ Vector::GetResult()
{
	System::String^ outputTemp = "";
	outputTemp += "[";
	for (unsigned int j = 0; j < data.size(); j++)
	{
		System::String^ buff = data[j].ToString();

		//if (buff->Length > 8)buff = buff->Substring(0, 8);
		outputTemp += buff;
		if (j != data.size() - 1)
			outputTemp += ", ";
	}
	outputTemp += "]" + System::Environment::NewLine;
	return outputTemp;
}


const Vector operator+(const Vector &x, const Vector &y) {
	
	std::vector<double> data;
	if (x.data.size() != y.data.size()) {
		throw v_rankdiff;
	}
	else {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] + y.data[i]);
		}
	}
	return Vector(data);
}

const Vector operator-(const Vector &x, const Vector &y) {
	std::vector<double> data;
	if (x.data.size() != y.data.size()) {
		throw v_rankdiff;
	}
	else {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] - y.data[i]);
		}
	}
	return Vector(data);
}


const Vector operator*(const Vector &x, const Vector &y) {

	std::vector<double> data;
	if (x.data.size() == 1) {
		for (int i = 0; i < y.data.size(); i++) {
			data.push_back(y.data[i] * x.data[0]);
		}
	}
	else if (y.data.size() == 1) {
		for (int i = 0; i < x.data.size(); i++) {
			data.push_back(x.data[i] * y.data[0]);
		}
	}
	else if (x.data.size() != y.data.size()) {
		throw v_rankdiff;
	}
	else {
		double sum = 0;
		for (int i = 0; i < x.data.size(); i++) {
			sum += y.data[i] * x.data[i];
		}
		data.push_back(sum);
	}
	return Vector(data);
}

const double Norm(const Vector &x) {
	double sum = 0.0;
	std::vector<double> data;
	for (int i = 0; i < x.data.size(); i++) {
		sum += std::abs(pow(x.data[i], 2));
	}
	return sqrt(sum);
}
const Vector Normalization(const Vector &x) {
	double sum = 0;
	std::vector<double>data;
	for (auto i : x.data) {
		sum += i * i;
	}
	sum = sqrt(sum);
	data = x.data;
	for (auto &i : data) {
		i /= sum;
	}
	return Vector(data);
}


const Vector CrossProduct(const Vector & x, const Vector & y)
{
	double i = x.data[1] * y.data[2] - y.data[1] * x.data[2],
		j = y.data[0] * x.data[2] - x.data[0] * y.data[2],
		k = x.data[0] * y.data[1] - y.data[0] * x.data[1];
	std::vector<double>data = { i,j,k };
	return Vector(data);
}

const Vector Component(const Vector & x, const Vector & y)
{
	Vector vec;
	vec = x * y;
	double n;
	n = Norm(y);
	vec.data[0] /= n;
	//return  Vector(vec.data);
	return vec;
}

const Vector Projection(const Vector & x, const  Vector & y)
{
	Vector vec;
	vec = Component(x, y);
	vec = vec * Normalization(y);
	return vec;
}

const double Area(const Vector & x, const Vector & y)
{
	// for eval: https://onlinemschool.com/math/assistance/vector/triangle_area/
	double c = Norm(x);
	double a = Component(x, y).data[0];
	double b = sqrt(c*c - a * a);
	double result = Norm(y)*b / 2;
	return result;

}
const Vector PN(const Vector & x, const Vector & y)
{
	return CrossProduct(x, y);
}
const bool IsParallel(const Vector & x, const Vector & y)
{
	if (x.data.size() != y.data.size())return false;
	double rate = -8763.30678;
	for (int i = 0; i < x.data.size(); i++) {
		if (!(x.data[i] == 0 || y.data[i] == 0)) {
			if (rate == -8763.30678) {
				rate = y.data[i] / x.data[i];
			}
			else if ((abs(rate*x.data[i] - y.data[i]) > misRange)) {
				return false;
			}
		}
	}
	if (rate != -8763.30678)return true;
	else return false;
}

const bool IsOrthogonal(const Vector & x, const Vector & y)
{
	double sum=0;
	for (int i = 0; i < x.data.size(); i++) {
		sum += x.data[i] * y.data[i];
	}
	if (!sum)return true;
	return false;
}

const double Angle(const Vector & x, const Vector & y)
{
	Vector vec;
	double result;
	vec = x * y;
	for (auto &i : vec.data) {
		i = i / (Norm(x)*Norm(y));
	}
	result = acos(vec.data[0]) * 180.0 / PI;
	return result;
}

const bool IsLI(const Vector & x, const Vector & y)
{
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
	//va_end(ptr);
	return list;
}