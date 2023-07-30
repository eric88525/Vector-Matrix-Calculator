#include"DataManager.h"
#include "WindowsForm.h"


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
				double value;
				for (int i = 0; i < vector_dim; i++) {
					fin >> value;
					tempVectorData.push_back(value);
				}
				std::string v_name = "v[" + std::to_string(currentLoadVectorID++) + "]";
				Vector tempVector(v_name, tempVectorData);
				vectors[v_name] = tempVector;
			}
			else if (tempSring == "M") {
				fin >> rows >> cols;
				std::vector<std::vector<double>> tempMatrixData(rows);
				double value;
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						fin >> value;
						tempMatrixData[i].push_back(value);
					}
				}
				Matrix tempMatrix(tempMatrixData);
				tempMatrix.name = "m[" + std::to_string(currentLoadMatrixID++) + "]";
				tempMatrix.row = rows;
				tempMatrix.col = cols;
				matrices[tempMatrix.name] = tempMatrix;
			}
		}
		return true;
	}
}

std::unordered_map<std::string, Vector> DataManager::GetVectors()
{
	return vectors;
}

Vector DataManager::GetVector(std::string name)
{
	return vectors[name];
}

std::unordered_map<std::string, Matrix> DataManager::GetMatrices() {
	return matrices;
}

Matrix DataManager::GetMatrix(std::string name)
{
	return matrices[name];
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

int DataManager::VectorCount()
{
	return vectors.size();
}

int DataManager::MatrixCount()
{
	return matrices.size();
}

void DataManager::clear()
{
	vectors.clear();
	matrices.clear();
}


