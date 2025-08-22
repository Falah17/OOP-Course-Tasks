//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include<iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;



// Matrix will be a template class that default to integer unless explicitly given a type

template <int row, int col, typename T = int>

class Matrix
{
	T** matrixPtr;    // matrixPtr will be pointing directly to the start of the matrix

	void buildMatrix()   	// build space for the matrix
	{
		matrixPtr = new T * [row];

		for (int i = 0; i < row; i++)
		{
			matrixPtr[i] = new T[col];
		}
	}

public:

	//defualt constructor - build a matrix and take a data and set all the cells to data 
	Matrix(T data = 0)
	{
		buildMatrix();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				matrixPtr[i][j] = data;
		}
	}


	//copy constructor -  build a matrix and set it cells to the appropriate value of otherMatrix ceels value
	Matrix(const Matrix& otherMatrix)
	{
		buildMatrix();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				matrixPtr[i][j] = otherMatrix.matrixPtr[i][j];
		}
	}


	//destructor, for manual de-allocation of memory
	~Matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] matrixPtr[i];

		delete[] matrixPtr;
	}



	//operator << - return the matrix in an orderly manner
	friend ostream& operator<<(ostream& os, const Matrix<row, col, T>& matrix)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				os << matrix.matrixPtr[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}


	//get identity matrix
	Matrix getIdentityMatrix()
	{
		int m;
		m = std::min(row, col);
		Matrix mat(0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((i <= m) && (j <= m) && (i == j))
				{
					mat.matrixPtr[i][j] = 1;
				}
			}

		}
		return mat;
	}


	//operator+   converts objects to matrix if needed
	friend Matrix<row, col, T> operator+(const Matrix<row, col, T>& matrix1, const Matrix<row, col, T>& matrix2)
	{
		Matrix matResult;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matResult.matrixPtr[i][j] = matrix1.matrixPtr[i][j] + matrix2.matrixPtr[i][j];
			}
		}
		return matResult;
	}


	// operator+ to handle +Matrix
	Matrix<row, col, T> operator+()
	{
		Matrix<row, col, T> mat = *this;

		return mat;
	}

	//Prefix Operator++ (++Matrix)
	Matrix<row, col, T>& operator++()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j]++;
			}
		}
		return *this;
	}

	//Postfix Operator++ (Matrix++) by the Prefix operator++ (++Matrix)
	Matrix<row, col, T> operator++(int)
	{
		Matrix<row, col, T> matBefore = *this;

		++(*this);

		return matBefore;
	}

	//operator-  similar to Operator+
	friend Matrix<row, col, T> operator-(const Matrix<row, col, T>& matrix1, const Matrix<row, col, T>& matrix2)
	{
		Matrix matResult;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matResult.matrixPtr[i][j] = matrix1.matrixPtr[i][j] - matrix2.matrixPtr[i][j];
			}
		}
		return matResult;
	}

	// Operator- to handle: -Matrix
	Matrix<row, col, T> operator-()
	{
		Matrix<row, col, T> mat = (*this);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mat.matrixPtr[i][j] = (mat.matrixPtr[i][j]) * (-1);
			}
		}

		return mat;
	}

	//Prefix Operator-- (--Matrix)
	Matrix<row, col, T>& operator--()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j]--;
			}
		}
		return *this;
	}

	//Postfix Operator-- (Matrix--) by the Prefix Operator-- (--Matrix)
	Matrix<row, col, T> operator--(int)
	{
		Matrix<row, col, T> matBefore = *this;
		for (int i = 0; i < row; i++)
		{
			Matrix<row, col, T> matBefore = *this;

			--(*this);

			return matBefore;
		}
		return matBefore;
	}



	// Operator*   who deals with (scalar * matrix)
	friend Matrix<row, col, T> operator*(const T& scalar, const Matrix<row, col, T>& matrix)
	{
		Matrix matResult;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matResult.matrixPtr[i][j] = matrix.matrixPtr[i][j] * scalar;
			}
		}
		return matResult;
	}

	//operator*  who deals with (matrix * scalar)
	friend Matrix<row, col, T> operator*(const Matrix<row, col, T>& matrix, const T& scalar)
	{
		Matrix matResult;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matResult.matrixPtr[i][j] = matrix.matrixPtr[i][j] * scalar;
			}
		}
		return matResult;
	}


	// method to get the main diagonal of the matrix and return array that contain it
	T* getDiag(int& num)
	{
		num = std::min(row, col);
		T* arrDiag = new T[num];
		for (int i = 0; i < num; i++)
		{
			arrDiag[i] = (*this)(i, i);
		}
		return arrDiag;
	}

	// Method to calculate the trace (sum of diagonal cells) of the Matrix ,using getDiag()
	explicit operator T()
	{
		int num;
		T* array = getDiag(num);
		int len = std::min(row, col);
		T sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += array[i];
		}
		return sum;
	}

	//operator()
	T& operator()(const int& row, const int& col) const
	{
		return this->matrixPtr[row][col];
	}

	// Operator= (matrix = otherMatrix)
	Matrix operator=(const Matrix<row, col, T>& otherMatrix)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j] = otherMatrix.matrixPtr[i][j];
			}
		}
		return *this;
	}


	//operator== bool operator that return if two matrices are not/equal (equal->true,notequal->false)
	friend bool operator==(const Matrix<row, col, T>& matrix1, const Matrix<row, col, T>& matrix2)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (abs(matrix1.matrixPtr[i][j] - matrix2.matrixPtr[i][j]) > DBL_EPSILON)
					return false;
			}
		}
		return true;
	}

	//operator!= bool operator that return if two matrices are not/equal (equal->false,notequal->true) , using the operator==
	friend bool operator!=(const Matrix<row, col, T>& matrix1, const Matrix<row, col, T>& matrix2)
	{
		if (matrix2 == matrix1)
			return false;
		return true;
	}


	//the bonus
	friend Matrix<row, col, T> operator*(const Matrix<row, col, T>& matrix1, const Matrix<row, col, T>& matrix2)
	{
		Matrix<row, col, T> matResult;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					matResult.matrixPtr[i][j] += matrix1.matrixPtr[i][k] * matrix2.matrixPtr[k][j];
				}
			}
		}
		return matResult;

	}

};



