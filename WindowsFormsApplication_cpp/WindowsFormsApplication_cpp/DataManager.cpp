#include"DataManager.h"

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
		fin >> tempSring;
		while (fin>>tempSring) {
			if (tempSring == "V") {
				std::vector<double> tempVectorData;
				fin >> getTimes;
				for (int i = 0; i < getTimes;i++) {
					double value;
					fin >> value;
					//double value = (double)strtod(tempSring.c_str(), NULL);
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
				tempMatrix.Name = "$v" + std::to_string(currentLoadVectorID++);
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
std::vector<Matrix> DataManager::GetMatrix(){
	return Matrices;
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

System::String^ Vector::getResult()
{
	System::String^ outputTemp = gcnew System::String(Name.c_str()) + " = ";
	outputTemp += "[";
	for (unsigned int j = 0; j < Data.size(); j++)
	{
		System::String^ buff = Data[j].ToString();
		
		if(buff->Length>8)buff = buff->Substring(0, 8);
		outputTemp += buff;
		if (j != Data.size() - 1)
			outputTemp += ",";
	}
	outputTemp += "]" + System::Environment::NewLine;
	return outputTemp;
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
	//return  Vector(vec.Data);
	return vec;
}

const Vector projection(const Vector & x, const  Vector & y)
{
	Vector vec;
	vec = component(x, y);
	vec = vec * normalization(y);
	return vec;
}

const double area(const Vector & x, const Vector & y)
{

	double c = norm(x);
	double a = component(x,y).Data[0];
	double b = sqrt(c*c - a * a);
	double area = norm(y)*b / 2;
	return area;
	
}



const Vector pN(const Vector & x, const Vector & y)
{
	return Vector();
}


const bool isParallel(const Vector & x, const Vector & y)
{
	if (x.Data.size() != y.Data.size())return false;
	double rate=-999;
	for (int i = 0; i < x.Data.size(); i++) {
		if (!(x.Data[i]==0 || y.Data[i]==0)) {
			if (rate==-999) {
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
	if (!isParallel(x,y)) {
		return true;
	}
	return false;
}

const std::vector<Vector> Ob(int count,Vector x ...)
{
	std::vector<Vector>list;
	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++) {
		Vector buff  = va_arg(ptr, Vector);
		list.push_back(buff);
	}
	list[0] = normalization(list[0]);
	for (int i = 0; i < list.size();i++) {
		for (int j = i-1; j >= 0;j--) {
			list[i] = list[i]-projection(list[i], list[j]);
		}
		list[i] = normalization(list[i]);
	}
	va_end(ptr);
	return list;
}


//----------------------------------------------------------------------matrix


Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<std::vector<double>> data):Data(data)
{
	Name = "";
	this->row = data.size();
	this->col = data[0].size();
}

const Matrix operator+(const Matrix & x, const Matrix & y)
{
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row;i++) {
		for (int j = 0; j < x.col;j++) {
			data[i].push_back(x.Data[i][j]+y.Data[i][j]);
		}
	}
	return Matrix(data);
}

const Matrix operator-(const Matrix & x, const Matrix & y)
{
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++) {
			data[i].push_back(x.Data[i][j] - y.Data[i][j]);
		}
	}
	return Matrix(data);
}

const Matrix operator*(const Matrix & x, const Matrix & y)
{
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row; ++i) {
		for (int j = 0; j < y.col; ++j) {
			double sum = 0;
			for (int k = 0; k < x.col; ++k)
			{
				sum+=x.Data[i][k] * y.Data[k][j];
			}
			data[i].push_back(sum);
		}
	}
	return Matrix(data);
}

const int rank( Matrix  x)
{
	int row, col,fixP=0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			return row;
		if ( x.Data[row][row+fixP]) {
			if (row == x.row - 1)return row+1;
			double temp = x.Data[row][row + fixP];
			for (auto &piv:x.Data[row]) {
				piv /=temp;
			}

			for (int eli = row+1; eli < x.row; eli++) {
				double r1 = x.Data[eli][row + fixP],
				r2 = x.Data[row][row + fixP];
				for (int i = 0; i < x.col;i++) {
					x.Data[eli][i] -=  x.Data[row][i] *r1 / r2 ;
					if (x.Data[eli][i]<0.000000001 && x.Data[eli][i]>-0.000000001) {
						x.Data[eli][i] = 0;
					}
 				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for ( chg = row + 1; chg < x.row; chg++) {
				if (x.Data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.Data[row], x.Data[chg]);
					row--;
					break;
				}
			}
			if (chg == x.row) {
				fixP++;
				row--;
			}
		}
	}

}

const Matrix transpose(const Matrix & x)
{
	std::vector<std::vector<double>> data(x.col);
	for (int row = 0; row < x.row; row++) {
		for (int col = 0; col < x.col; col++) {
			data[col].push_back(x.Data[row][col]);
		}

	}
	return Matrix(data);
}

const Matrix operator/( Matrix  x,  Matrix  y)
{
	Matrix m;
	m = inverse(x)*y;
	return m;
}

const double determinants(Matrix  x)
{
	int row, col, fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			break;
		if (x.Data[row][row + fixP]) {
			double temp = x.Data[row][row + fixP];
			for (int eli = row + 1; eli < x.row; eli++) {
				double r1 = x.Data[eli][row + fixP],
					r2 = x.Data[row][row + fixP];
				for (int i = 0; i < x.col; i++) {
					x.Data[eli][i] -= x.Data[row][i] * r1 / r2;
					if (x.Data[eli][i]<0.000000001 && x.Data[eli][i]>-0.000000001) {
						x.Data[eli][i] = 0;
					}
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.Data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.Data[row], x.Data[chg]);
					row--;
					break;
				}
			}
			if (chg == x.row) {
				fixP++;
				row--;
			}
		}
	}
	double det=1;
	for (int row = 0; row < x.row;row++) {
		det *= x.Data[row][row];
	}
	return det;
}

const Matrix inverse(Matrix x)
{
	int rL = rank(x);
	int error;
	if (rL<x.row) {
		error = 1;
		throw error;
	}
	std::vector<std::vector<double>> data(x.row);
	Matrix m(data);
	for (int row = 0; row < x.row; row++) {
		for (int col = 0; col < x.col; col++) {	
			if(row==col)m.Data[row].push_back(1);
			else m.Data[row].push_back(0);
		}
	}
	m.col = x.row;
	m.row = x.row;
	//-------
	int row, col, fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			break;
		if (x.Data[row][row + fixP]) {
			double temp = x.Data[row][row + fixP];
			double ti= m.Data[row][row + fixP];
			for (auto &piv : x.Data[row]) {
				piv /= temp;
			}
			for (auto &pivi : m.Data[row]) {
				pivi /= temp;
			}
			for (int eli =0; eli < x.row; eli++) {
				if (eli != row) {
					double r1 = x.Data[eli][row + fixP],
							r2 = x.Data[row][row + fixP];
					for (int i = 0; i < x.col; i++) {
						x.Data[eli][i] -= x.Data[row][i] * r1 / r2;
						m.Data[eli][i] -= m.Data[row][i] * r1 / r2;
						if (x.Data[eli][i]<0.000000001 && x.Data[eli][i]>-0.000000001) {
							x.Data[eli][i] = 0;
						}
					}
				}	
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.Data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.Data[row], x.Data[chg]);
					swap(m.Data[row], m.Data[chg]);
					row--;
					break;
				}
			}
			if (chg == x.row) {
				fixP++;
				row--;
			}
		}
	}
	//-------
	return m;
}
