//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include "Matrix.h"
#include<iostream>

using std::cout;
using std::endl;
using std::ostream;

// MatrixContainer will be a template class that default to integer unless explicitly given a type
template <int row, int col, typename T = int>


class MatrixContainer
{
	// The private qualities of the container will be an integer for the quantity contained, and a list of T type matrices
	int matrixQuantity;
	int dynamicsize;
	Matrix<row, col, T>* matrixList;

public:

	// default constructor
	MatrixContainer()
	{
		this->matrixQuantity = 0;
		this->dynamicsize = 1;
		this->matrixList = NULL;
	}

	// destructor
	~MatrixContainer()
	{
		delete[]  this->matrixList;
	}

	//add a matrix to the container
	void addMatrix(Matrix<row, col, T> newMat)
	{

		if (this->dynamicsize - 1 == this->matrixQuantity)
		{
			this->dynamicsize *= 2;
		}
		Matrix<row, col, T>* newMatrixList = new Matrix<row, col, T>[this->dynamicsize];

		for (int i = 0; i < this->matrixQuantity; i++)
		{
			newMatrixList[i] = this->matrixList[i];
		}
		newMatrixList[this->matrixQuantity] = newMat;
		delete[]this->matrixList;
		this->matrixList = newMatrixList;
		this->matrixQuantity++;
	}

	//removing the last matrix from the container
	void removeLastMatrix()
	{
		if (this->dynamicsize >= 4 * (this->matrixQuantity - 1))
		{
			this->dynamicsize = this->dynamicsize / 2;
		}
		Matrix<row, col, T>* newMatrixList = new Matrix<row, col, T>[this->dynamicsize];

		for (int i = 0; i < this->matrixQuantity - 1; i++)
		{
			newMatrixList[i] = this->matrixList[i];
		}
		delete[]this->matrixList;
		this->matrixList = newMatrixList;
		this->matrixQuantity--;
	}

	//operator << - printing all the matrices in the container by printing each matrix by using Operator<< of Matrix class
	friend ostream& operator<<(ostream& os, const MatrixContainer<row, col, T>& container)
	{
		os << "There are " << container.matrixQuantity << " matrices in the container. The matrices:" << endl;

		for (int i = 0; i < (container.matrixQuantity); i++)
		{
			os << container.matrixList[i] << endl;
		}

		return os;
	}

	// Return a new matrix that is the sum of two given matrices in the container
	Matrix<row, col, T> addMatricesAtIndexes(const int& i, const int& j)
	{
		return matrixList[i] + matrixList[j];
	}

	// Return a new matrix that is the multiplication of a given matrix in the container with scalar
	Matrix<row, col, T> mulMatAtIndexByScalar(const int& i, const T& scalar)
	{
		return matrixList[i] * scalar;
	}

	// return the amount of matrices in the container
	int size()
	{
		return this->matrixQuantity;
	}

	//return the size of the dynamic array
	int limit()
	{
		return this->dynamicsize;
	}
};