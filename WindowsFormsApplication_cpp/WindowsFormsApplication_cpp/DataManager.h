#pragma once
#include"DotNetUtilities.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <numeric>
#include <math.h> 
#include <stdarg.h>
#define PI 3.14159265

//定義向量資料結構

struct Vector
{
	std::string Name="";
	std::vector<double> Data;
	Vector() {};
	Vector(std::vector<double> data);
	Vector(std::string name,std::vector<double> data);
	System::String^ getResult();
	friend const Vector operator+(const Vector &x, const Vector &y);
	friend const Vector operator-(const Vector &x, const Vector &y);
	friend const Vector operator*(const Vector &x, const Vector &y);
	friend const double norm(const Vector &x);
	friend const Vector normalization(const Vector &x);
	friend const Vector crossProduct(const Vector &x, const Vector &y);
	friend const Vector component(const Vector &x, const Vector &y);
	friend const Vector projection(const Vector &x, const Vector &y);
	friend const double area(const Vector &x, const Vector &y);
	friend const bool isParallel(const Vector &x, const Vector &y);
	friend const bool isOrthogonal(const Vector &x, const Vector &y);
	friend const double angle(const Vector &x, const Vector &y);
	friend const Vector pN(const Vector &x, const Vector &y);
	friend const bool isLI(const Vector &x, const Vector &y);
	friend const std::vector<Vector> orthonormalBasis(int count,Vector x...);
};
struct Matrix {
	std::string Name = "";
	std::vector<std::vector<double>> Data;
	int row;
	int col;
	Matrix();
	Matrix(std::vector<std::vector<double>> data);
	friend const Matrix operator+(const Matrix &x, const Matrix &y);
	friend const Matrix operator-(const Matrix &x, const Matrix &y);
	friend const Matrix operator*(const Matrix &x, const Matrix &y);
	friend const int rank(const Matrix &x);
	friend const Matrix transpose(const Matrix &x);
	friend const Matrix operator/(const Matrix &x, const Matrix &y);	//linear system
	friend const double determinants(const Matrix &x);
	friend const Matrix inverse(const Matrix &x);
	friend const Matrix Adj(const Matrix &x);
	friend const Matrix pm(const Matrix &x);
};

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	//存矩陣
	std::vector<Matrix> Matrices;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	//拿矩陣資料
	std::vector<Matrix> GetMatrix();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
};
