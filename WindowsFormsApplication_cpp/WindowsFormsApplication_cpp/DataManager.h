#pragma once
#include"DotNetUtilities.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <numeric>
#include <math.h> 
#include <stdarg.h>
#include"Matrix.h"
#include"Vector.h"
#include<unordered_map>

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::unordered_map<std::string,Vector> vectors;
	//存矩陣
	std::unordered_map<std::string, Matrix> matrices;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadData();

	//取得向量資料
	std::unordered_map<std::string, Vector> GetVectors();
	Vector GetVector(std::string name);

	//拿矩陣資料
	std::unordered_map<std::string, Matrix> GetMatrices();
	Matrix GetMatrix(std::string name);
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);

	int VectorCount();
	int MatrixCount();
	void clear();
};
