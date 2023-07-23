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

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::unordered_map<std::string,Vector> vectors;
	//�s�x�}
	std::unordered_map<std::string, Matrix> matrices;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadData();

	//���o�V�q���
	std::unordered_map<std::string, Vector> GetVectors();
	Vector GetVector(std::string name);

	//���x�}���
	std::unordered_map<std::string, Matrix> GetMatrices();
	Matrix GetMatrix(std::string name);
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);

	int VectorCount();
	int MatrixCount();
	void clear();
};
