#pragma once
#include <vector>
#include <algorithm>
#include<math.h>
#include"Error.h"
#include<string>


#define misRange 0.000000001
#define _USE_MATH_DEFINES 
#define M_PI       3.14159265358979323846


// google naming style https://google.github.io/styleguide/cppguide.html#Naming
class Matrix {
	std::string name_;
	std::vector<std::vector<double>> data_;
	size_t row;
	size_t col;
public:

	Matrix() {};
	Matrix(std::vector<std::vector<double>> data) :data_(data), row(data.size()), col(data[0].size()) {};
	Matrix(std::string name, std::vector<std::vector<double>> data) :name_(name), data_(data), row(data.size()), col(data[0].size()) {};
	Matrix(const Matrix& t) :row(t.row), col(t.col), data_(t.data_) {};
	Matrix(double v) : row(1), col(1) {
		data_.push_back(std::vector<double>(1, v));
	}
	System::String^ GetResult();

	friend const Matrix operator+(const Matrix& x, const Matrix& y);
	friend const Matrix operator-(const Matrix& x, const Matrix& y);
	friend const Matrix operator*(const Matrix& x, const Matrix& y);
	
	friend const Matrix MatMul(const Matrix& x, const Matrix& y);
	friend const Matrix Rank(Matrix x);
	friend const Matrix Transpose(const Matrix& x);
	friend const Matrix Solve(const Matrix& x, const Matrix& y);
	friend const Matrix Determinants(const Matrix &x);
	friend const Matrix Inverse(const Matrix &x);
	friend const Matrix Adj(const Matrix& x);
	friend const Matrix PowerMethod(const Matrix& x, double&);
	friend const Matrix Eigen(const Matrix& x, std::vector<double>&);
	friend const Matrix LeastSquare(const Matrix& x, const Matrix& y);
	friend const std::vector<Matrix> Rref(Matrix x);

	size_t GetRow() const { return row; };
	size_t GetCol() const { return col; }
	bool IsConstant() const { return row == 1 && col == 1; };
};

