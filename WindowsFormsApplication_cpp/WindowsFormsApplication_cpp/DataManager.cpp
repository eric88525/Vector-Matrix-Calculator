#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadVectorData()
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
		//標記當前讀取向量ID
		int currentLoadVectorID = 0;
		//定義向量資料暫存變數
		std::vector<double> tempVectorData;
		//定義讀取檔案字串暫存變數
		std::string tempSring;
		//從檔案讀取字串，解析掉向量總數
		fin >> tempSring;
		
		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (fin >> tempSring)
		{
			//從檔案讀取字串
			
			//解析到向量標記"V"
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//定義暫存向量資料結構
					Vector tempVector;
					//存入向量資料
					tempVector.Data = tempVectorData;
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//存入向量變數名稱
					tempVector.Name = vectorVariableTemp;
					//存入向量
					Vectors.push_back(tempVector);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					VectorVariableIndex++;
					//清除向量資料暫存
					tempVectorData.clear();
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadVectorID++;
				
				//從檔案讀取字串，解析掉向量維度
				fin >> tempSring;
			}
			else
			{
				//讀取向量資料，並將string轉為double
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//將向量資料存入暫存
				tempVectorData.push_back(value);
			}
			
		}
		//讀入輸入檔案中最後一個向量資訊
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//讀取成功回傳false
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}
void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}
//----------------------------------------------------------------------vector

Vector::Vector(std::vector<double> data)
{
	this->Data = data;
}

Vector::Vector(std::string name,std::vector<double> data) {
	this->Name = name;
	this->Data = data;
}


const Vector operator+(const Vector &x, const Vector &y) {
	int rankdiff;
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] + y.Data[i]);
		}
	}
	return Vector(data);
}

const Vector operator-(const Vector &x, const Vector &y) {
	int rankdiff;	
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}
	else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] - y.Data[i]);
		}
	}
	return Vector(data);
}


const Vector operator*(const Vector &x, const Vector &y) {
	
	int rankdiff;
	std::vector<double> data;
	if (x.Data.size()==1) {
		for (int i = 0; i < y.Data.size(); i++) {
			data.push_back(y.Data[i]*x.Data[0]);
		}
	}else if (y.Data.size()==1){
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] * y.Data[0]);
		}
	}else if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}else {
		double sum=0;
		for (int i = 0; i < x.Data.size(); i++) {
			sum+=y.Data[i] * x.Data[i];
		}
		data.push_back(sum);
	}
	return Vector(data);
}

const double norm(const Vector &x) {
	double sum = 0.0;
	std::vector<double> data;
	for (int i = 0; i < x.Data.size(); i++) {
		sum += std::abs(pow(x.Data[i], 2));
	}
	return sqrt(sum);
}
const Vector normalization(const Vector &x) {
	double sum = 0;
	std::vector<double>data;
	for (auto i: x.Data) {
		sum += i * i;
	}
	sum = sqrt(sum);
	data =x.Data;
	for (auto &i: data) {
		i /= sum;
	}
	return Vector(data);
}


const Vector crossProduct(const Vector & x, const Vector & y)
{
	double i = x.Data[1] * y.Data[2] - y.Data[1] * x.Data[2],
		j = x.Data[0] * y.Data[2] - y.Data[0] * x.Data[2],
		k = x.Data[0] * y.Data[1] - y.Data[0] * x.Data[1];
	std::vector<double>data = {i,j,k};
	return Vector(data);
}

const Vector component(  const Vector & x, const Vector & y)
{
	Vector vec;
	vec = x * y;
	double n;
	n = norm(y);
	vec.Data[0] /= n;
	return  Vector(vec.Data);
}

const Vector projection(const Vector & x, const  Vector & y)
{
	Vector vec;
	vec = component(x, y);
	vec = vec * normalization(y);
	return Vector(vec.Data);
}

const double area(const Vector & x, const Vector & y)
{
	/*Vector vec;
	vec = x * y;
	double db;
	db = norm(vec);
	db *= 0.5;
	return db;*/
	return 0.0;
}



const Vector pN(const Vector & x, const Vector & y)
{
	return Vector();
}


const bool isParallel(const Vector & x, const Vector & y)
{
	double rate=-999;
	for (int i = 0; i < x.Data.size(); i++) {
		if (!(x.Data[i]==0 || y.Data[i]==0)) {
			if (rate=-999) {
				rate = y.Data[i] / x.Data[i];
			}else if(x.Data[i]*rate!=y.Data[i]){
				return false;
			}
		}
	}
	if(rate!=-999)return true;
	else return false;
}

const bool isOrthogonal(const Vector & x, const Vector & y)
{
	double sum;
	for (int i = 0; i < x.Data.size();i++) {
		sum += x.Data[i] * y.Data[i];
	}
	if (!sum)return true;
	return false;
}

const double angle(const Vector & x, const Vector & y)
{
	Vector vec;
	double result;
	vec = x * y;
	for (auto &i:vec.Data) {
		i = i / (norm(x)*norm(y));
	}
	result = acos(vec.Data[0]) * 180.0 / PI;
	return result;
}

const bool isLI(const Vector & x, const Vector & y)
{
	return false;
}
