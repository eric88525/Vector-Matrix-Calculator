#include"Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<std::vector<double>> data) :data(data)
{
	name = "";
	row = data.size();
	col = data[0].size();
}

Matrix::Matrix(const Matrix& t)
{
	row = t.row;
	col = t.col;
	name = t.name;
	data = t.data;
}

System::String^ Matrix::GetResult()
{

	System::String^ outputTemp = gcnew System::String(name.c_str()) + " = " + System::Environment::NewLine;
	outputTemp += "[";
	for (int r = 0; r < row; r++)
	{
		outputTemp += "[";
		for (int c = 0; c < col; c++) {
			System::String^ buff = data[r][c].ToString();
			outputTemp += buff;
			if (c != col - 1)
				outputTemp += ", ";
		}
		outputTemp += "],";
		if (r != row - 1)
			outputTemp += System::Environment::NewLine;
	}
	outputTemp += "]" + System::Environment::NewLine;
	return outputTemp;
}

const Matrix operator+(const Matrix& x, const Matrix& y)
{
	if (x.row != y.row || x.col != y.col)throw m_Rank_different;
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++) {
			data[i].push_back(x.data[i][j] + y.data[i][j]);
		}
	}
	return Matrix(data);
}

const Matrix operator-(const Matrix& x, const Matrix& y)
{
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row; i++) {
		for (int j = 0; j < x.col; j++) {
			data[i].push_back(x.data[i][j] - y.data[i][j]);
		}
	}
	return Matrix(data);
}

const Matrix operator*(const Matrix& x, const Matrix& y)
{
	if (x.col != y.row) {
		throw m_Rank_different;
	}
	std::vector<std::vector<double>> data(x.row);
	for (int i = 0; i < x.row; ++i) {
		for (int j = 0; j < y.col; ++j) {
			double sum = 0;
			for (int k = 0; k < x.col; ++k)
			{
				sum += x.data[i][k] * y.data[k][j];
			}
			data[i].push_back(sum);
		}
	}
	return Matrix(data);
}

const int Rank(Matrix  x)
{
	int row = 0, col = 0, fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			return row;
		if (x.data[row][row + fixP]) {
			if (row == x.row - 1)return row + 1;
			double temp = x.data[row][row + fixP];
			for (auto& piv : x.data[row]) {
				piv /= temp;
			}

			for (int eli = row + 1; eli < x.row; eli++) {
				double r1 = x.data[eli][row + fixP],
					r2 = x.data[row][row + fixP];
				for (int i = 0; i < x.col; i++) {
					x.data[eli][i] -= x.data[row][i] * r1 / r2;
					if (x.data[eli][i]<misRange && x.data[eli][i]>-misRange) {
						x.data[eli][i] = 0;
					}
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.data[row], x.data[chg]);
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
	return -1;
}

const Matrix Transpose(const Matrix& x)
{
	std::vector<std::vector<double>> data(x.col);
	for (int row = 0; row < x.row; row++) {
		for (int col = 0; col < x.col; col++) {
			data[col].push_back(x.data[row][col]);
		}

	}
	return Matrix(data);
}

const Matrix operator/(Matrix  x, Matrix  y)
{
	Matrix m;
	m = Inverse(x) * y;
	return m;
}

const double Determinants(Matrix  x)
{
	int row = 0, col = 0, fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			break;
		if (x.data[row][row + fixP]) {
			double temp = x.data[row][row + fixP];
			for (int eli = row + 1; eli < x.row; eli++) {
				double r1 = x.data[eli][row + fixP],
					r2 = x.data[row][row + fixP];
				for (int i = 0; i < x.col; i++) {
					x.data[eli][i] -= x.data[row][i] * r1 / r2;
					if (x.data[eli][i]<0.000000001 && x.data[eli][i]>-0.000000001) {
						x.data[eli][i] = 0;
					}
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.data[row], x.data[chg]);
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
	double det = 1;
	for (int row = 0; row < x.row; row++) {
		det *= x.data[row][row];
	}
	return det;
}

const Matrix Inverse(Matrix x)
{
	int rL = Rank(x);

	if (rL != x.row || x.row != x.col) {

		throw no_inverse;
	}
	std::vector<std::vector<double>> data(x.row);
	Matrix m(data);
	for (int row = 0; row < x.row; row++) {
		for (int col = 0; col < x.col; col++) {
			if (row == col)m.data[row].push_back(1);
			else m.data[row].push_back(0);
		}
	}
	m.col = x.row;
	m.row = x.row;
	//-------
	int row = 0, col = 0, fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			break;
		if (x.data[row][row + fixP]) {
			double temp = x.data[row][row + fixP];
			double ti = m.data[row][row + fixP];
			for (auto& piv : x.data[row]) {
				piv /= temp;
			}
			for (auto& pivi : m.data[row]) {
				pivi /= temp;
			}
			for (int eli = 0; eli < x.row; eli++) {
				if (eli != row) {
					double r1 = x.data[eli][row + fixP],
						r2 = x.data[row][row + fixP];
					for (int i = 0; i < x.col; i++) {
						x.data[eli][i] -= x.data[row][i] * r1 / r2;
						m.data[eli][i] -= m.data[row][i] * r1 / r2;
						if (abs(x.data[eli][i]) < misRange) {
							x.data[eli][i] = 0;
						}
					}
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.data[row], x.data[chg]);
					swap(m.data[row], m.data[chg]);
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

const Matrix Adj(const Matrix& x)
{
	Matrix result(x.data);
	for (int row = 0; row < x.row; row++) {
		for (int col = 0; col < x.col; col++) {

			std::vector<std::vector<double>>vbuff(x.row - 1);
			int ArowIndex = 0;
			for (int Arow = 0; Arow < x.row; Arow++) {
				for (int Acol = 0; Acol < x.col; Acol++) {
					if (Arow != row && Acol != col) {
						vbuff[ArowIndex].push_back(x.data[Arow][Acol]);
					}
				}
				if (Arow != row)ArowIndex++;
				if (ArowIndex == x.row - 1)break;
			}
			Matrix A(vbuff);
			double Adet = Determinants(A);
			result.data[row][col] = pow(-1, row + col + 2) * Adet;
		}
	}
	return Transpose(result);
}

const Matrix Pm(const Matrix& x, double& returnEv)
{
	std::vector<std::vector<double>> data(x.row);
	for (auto& i : data) {
		i.push_back(static_cast <double> (rand()) / static_cast <double> (RAND_MAX));
	}
	Matrix xx(data);
	double temp = 0, d = 0;
	do {
		xx = x * xx;
		temp = d;
		d = 0;
		for (int i = 0; i < xx.row; i++)
		{
			if (fabs(xx.data[i][0]) > fabs(d))
				d = xx.data[i][0];
		}
		for (auto& i : xx.data) {
			i[0] /= d;
		}
	} while (fabs(d - temp) > misRange);
	returnEv = d;
	return xx;
}

const Matrix Eigen(const Matrix& x, std::vector<double>& eigenValues)
{
	std::vector<std::vector<double>> eigenVectors;
	//std::vector<Matrix> result;

	if (x.data.size() == 1) {
		std::vector<std::vector<double>> tempVector;
		eigenValues.push_back(x.data[0][0]);
		tempVector[0].push_back(1);
		Matrix result(tempVector);
		return result;
	}
	else if (x.data.size() == 2) {

		std::vector<Matrix> M(2);
		std::vector<std::vector<double>> tempVector(2);
		double X03 = x.data[0][0] + x.data[1][1];
		double detX = Determinants(x);
		eigenValues.push_back((X03 + sqrt(pow(X03, 2) - 4 * detX)) / 2);
		eigenValues.push_back((X03 - sqrt(pow(X03, 2) - 4 * detX)) / 2);
		if (eigenValues[0] == 0 || eigenValues[1] == 0)throw eigen_cant_zero;
		for (int i = 0; i < 2; i++) {
			M[i] = x;
			M[i].data[0][0] -= eigenValues[i]; M[i].data[1][1] -= eigenValues[i];
			if (M[i].data[0][0]) {
				double v[2];
				v[0] = -M[i].data[0][1];
				v[1] = M[i].data[0][0];
				double normD = sqrt(v[0] * v[0] + v[1] * v[1]);
				v[0] /= normD; v[1] /= normD;
				if (abs(v[0]) < misRange) {
					v[0] = 0;
				}
				else if (abs(v[1]) < misRange) {
					v[1] = 0;
				}
				tempVector[i].push_back(v[0]);
				tempVector[i].push_back(v[1]);
			}
		}
		Matrix result(tempVector);
		result = Transpose(result);
		return result;
	}
	else if (x.data.size() == 3) {
		double a, b, c, d, Q, R;
		std::vector<Matrix> M(3);
		std::vector<std::vector<double>> tempVector(3);
		//--
		a = x.data[0][0] + x.data[1][1] + x.data[2][2];
		a *= -1;

		b = -1 * (x.data[2][2] * (x.data[0][0] + x.data[1][1]) + x.data[0][0] * x.data[1][1])
			+ (x.data[0][2] * x.data[2][0]) + (x.data[1][2] * x.data[2][1]) + (x.data[0][1] * x.data[1][0]);
		b *= -1;
		c = x.data[0][0] * x.data[1][1] * x.data[2][2]
			+ x.data[1][0] * x.data[2][1] * x.data[0][2] + x.data[0][1] * x.data[1][2] * x.data[2][0]
			- (x.data[0][2] * x.data[1][1] * x.data[2][0] + x.data[0][0] * x.data[1][2] * x.data[2][1] + x.data[1][0] * x.data[0][1] * x.data[2][2]);
		c *= -1;
		Q = (pow(a, 2) - 3 * b) / 9;
		R = (2 * a * a * a - 9 * a * b + 27 * c) / 54;
		//--
		if (Q * Q * Q > R * R) {
			double agl = acos(R / sqrt(Q * Q * Q));
			double qq = -2.0 * sqrt(Q);
			eigenValues.push_back(qq * cos(agl / 3) - a / 3);
			eigenValues.push_back(qq * cos(agl / 3 + 2 * M_PI / 3) - a / 3);
			eigenValues.push_back(qq * cos(agl / 3 - 2 * M_PI / 3) - a / 3);
		}
		/*else
		{
			double f, g, h, r, s, t, u;
			f = (3 * c / a - b * b / a * a) / 3;
			g = (2 * (b*b*b) / (a*a*a) - (9 * b*c) / (a*a) + (27 * d / a)) / 27;
			h = (g*g / 4) + (f*f*f / 27);
			r = -(g / 2) + sqrt(h);
			s = pow(r, 1 / 3);
			t = -(g / 2) - sqrt(h);
			u = pow(t, 1 / 3);
			eigenValues.push_back(s+u-(b/(3*a)));
			eigenValues.push_back( -(s+u)/2 -(b/3a) + ) );
		}*/
		if (eigenValues[0] == 0 || eigenValues[1] == 1 || eigenValues[2] == 2)throw eigen_cant_zero;
		for (int i = 0; i < 3; i++) {
			M[i] = x;
			M[i].data[0][0] -= eigenValues[i];
			M[i].data[1][1] -= eigenValues[i];
			M[i].data[2][2] -= eigenValues[i];
			M[i] = Rref(M[i])[0];
			if (M[i].data[0][0]) {
				double v[3], t;
				v[0] = (M[i].data[1][1] * M[i].data[0][2] - M[i].data[1][2] * M[i].data[0][1]) / M[i].data[0][0];
				v[1] = M[i].data[1][2];
				v[2] = -M[i].data[1][1];
				t = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
				v[0] /= t; v[1] /= t; v[2] /= t;
				for (int vv = 0; vv < 3; vv++) {
					if (abs(v[vv]) < misRange) {
						v[vv] = 0;
					}
					tempVector[vv].push_back(v[vv]);
				}
			}
		}
		Matrix result(tempVector);
		return result;

	}
	return Matrix();
}

const Matrix LeastSquare(const Matrix& x, const Matrix& y)
{
	Matrix a = Transpose(x) * x;
	Matrix b = Transpose(x) * y;
	return a / b;
}

const std::vector<Matrix>  Rref(Matrix  x)
{

	Matrix tempm(x.data);
	int fixP = 0;
	for (int row = 0; row < x.row; row++) {
		if ((row + fixP) > x.col - 1)
			break;
		if (x.data[row][row + fixP]) {
			if (row == x.row - 1)break;
			double temp = x.data[row][row + fixP];
			/*for (auto &piv : x.data[row]) {
				piv /= temp;
			}*/

			for (int eli = row + 1; eli < x.row; eli++) {
				double r1 = x.data[eli][row + fixP],
					r2 = x.data[row][row + fixP];
				for (int i = 0; i < x.col; i++) {
					x.data[eli][i] -= x.data[row][i] * r1 / r2;
					if (abs(x.data[eli][i]) < misRange) {
						x.data[eli][i] = 0;
					}
					x.data[eli][row + fixP] = 0;
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < x.row; chg++) {
				if (x.data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(x.data[row], x.data[chg]);
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
	//---------------------------
	int fixQ = 0;
	for (int row = 0; row < tempm.row; row++) {
		if ((row + fixQ) > tempm.col - 1)
			break;
		if (tempm.data[row][row + fixQ]) {
			if (row == tempm.row - 1) {
				tempm.data[row][row + fixQ] = 1;
				break;
			}
			double temp = tempm.data[row][row + fixQ];
			for (int i = 0; i < tempm.row; i++) {
				tempm.data[i][row] /= temp;
			}

			for (int eli = row + 1; eli < tempm.col; eli++) {
				double r1 = tempm.data[row + fixP][eli],
					r2 = tempm.data[row][row + fixP];
				for (int i = 0; i < tempm.row; i++) {
					tempm.data[i][eli] -= tempm.data[i][row] * r1 / r2;
					if (tempm.data[i][eli]<misRange && tempm.data[i][eli]>-misRange) {
						tempm.data[i][eli] = 0;
					}
				}
			}
			int zz = 0;
		}
		else {
			int chg;
			for (chg = row + 1; chg < tempm.row; chg++) {
				if (tempm.data[chg][row])
				{
					/*  Find non zero elements in the same column */
					swap(tempm.data[row], tempm.data[chg]);
					row--;
					break;
				}
			}
			if (chg == tempm.row) {
				fixQ++;
				row--;
			}
		}
	}
	return std::vector<Matrix>{x, tempm};
}
