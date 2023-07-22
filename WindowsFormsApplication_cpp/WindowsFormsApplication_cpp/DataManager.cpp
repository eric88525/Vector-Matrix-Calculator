#include"DataManager.h"
#include "WindowsForm.h"



DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		int currentLoadVectorID = VectorCount(), currentLoadMatrixID = MatrixCount(), vector_dim, rows, cols;
		std::string tempSring;
		while (fin >> tempSring) {
			if (tempSring == "V") {
				std::vector<double> tempVectorData;
				fin >> vector_dim;
				for (int i = 0; i < vector_dim; i++) {
					double value;
					fin >> value;
					tempVectorData.push_back(value);
				}
				Vector tempVector;
				tempVector.name = "v[" + std::to_string(currentLoadVectorID++) + "]";
				tempVector.data = tempVectorData;
				Vectors.push_back(tempVector);
			}
			else if (tempSring == "M") {
				fin >> rows >> cols;
				std::vector<std::vector<double>> tempMatrixData(rows);
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						double value;
						fin >> value;
						tempMatrixData[i].push_back(value);
					}
				}
				Matrix tempMatrix;
				tempMatrix.name = "m[" + std::to_string(currentLoadMatrixID++) + "]";
				tempMatrix.data = tempMatrixData;
				tempMatrix.row = rows;
				tempMatrix.col = cols;
				Matrices.push_back(tempMatrix);
			}
		}
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}

Vector DataManager::GetVector(std::string name)
{
	for (auto v : Vectors) {
		if (v.name == name)
			return v;
	}
	return Vector();
}

std::vector<Matrix> DataManager::GetMatrices() {
	return Matrices;
}

Matrix DataManager::GetMatrix(std::string name)
{
	for (auto m : Matrices) {
		if (m.name == name)
			return m;
	}
	return Matrix();
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

int DataManager::VectorCount()
{
	return Vectors.size();
}

int DataManager::MatrixCount()
{
	return Matrices.size();
}

void DataManager::clear()
{
	Vectors.clear();
	Matrices.clear();
}


