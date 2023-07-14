#include"DataManager.h"
#include "WindowsForm.h"



DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{	
		int currentLoadVectorID = 0, currentLoadMatrixID = 0,getTimes,tempRows,tempCols;		
		std::string tempSring;
		while (fin>>tempSring) {
			if (tempSring == "V") {
				std::vector<double> tempVectorData;
				fin >> getTimes;
				for (int i = 0; i < getTimes;i++) {
					double value;
					fin >> value;
					tempVectorData.push_back(value);
				}
				Vector tempVector;
				tempVector.Name = "$v" + std::to_string(currentLoadVectorID++);
				tempVector.Data = tempVectorData;
				Vectors.push_back(tempVector);
			}
			else if (tempSring=="M") {	
				fin >> tempRows >> tempCols;
				std::vector<std::vector<double>> tempMatrixData(tempRows);
				for (int i = 0; i < tempRows;i++) {
					for (int j = 0; j < tempCols; j++) {
						double value;
						fin >> value;
						tempMatrixData[i].push_back(value);
					}
				}
				Matrix tempMatrix;
				tempMatrix.Name = "$m" + std::to_string(currentLoadMatrixID++);
				tempMatrix.Data = tempMatrixData;
				tempMatrix.row = tempRows;
				tempMatrix.col = tempCols;
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

std::vector<Matrix> DataManager::GetMatrices(){
	return Matrices;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}


