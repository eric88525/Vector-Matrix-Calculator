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


//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�s�x�}
	std::vector<Matrix> Matrices;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadData();

	//���o�V�q���
	std::vector<Vector> GetVectors();
	Vector GetVector(std::string name);

	//���x�}���
	std::vector<Matrix> GetMatrices();
	Matrix GetMatrix(std::string name);
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);

	int VectorCount();
	int MatrixCount();
	void clear();
};
