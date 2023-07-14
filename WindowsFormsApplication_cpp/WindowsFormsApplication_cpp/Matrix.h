#pragma once
#include <vector>
#include <algorithm>
#include<math.h>
#include"Error.h"
#include<string>


#define M_PI 3.1415926
#define misRange 0.000000001
#define _USE_MATH_DEFINES 



// google naming style https://google.github.io/styleguide/cppguide.html#Naming
class Matrix {
public:
	std::string name = "";
	std::vector<std::vector<double>> data;
	int row;
	int col;
	Matrix();
	Matrix(std::vector<std::vector<double>> data);
	System::String^ GetResult();
	friend const Matrix operator+(const Matrix& x, const Matrix& y);
	friend const Matrix operator-(const Matrix& x, const Matrix& y);
	friend const Matrix operator*(const Matrix& x, const Matrix& y);
	friend const int Rank(Matrix x);
	friend const Matrix Transpose(const Matrix& x);
	friend const Matrix operator/(Matrix x, Matrix y);  // Linear system
	friend const double Determinants(Matrix x);
	friend const Matrix Inverse(Matrix x);
	friend const Matrix Adj(const Matrix& x);
	friend const Matrix Pm(const Matrix& x, double&);
	friend const Matrix Eigen(const Matrix& x, std::vector<double>&);
	friend const Matrix LeastSquare(const Matrix& x, const Matrix& y);
	friend const std::vector<Matrix> Rref(Matrix x);
};

