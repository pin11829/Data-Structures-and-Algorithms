#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <new>
#include "matrix.h"

Matrix::Matrix(const int& r, const int& c) //constructor
{
	row = r;
	col = c;
	array = new double*[r];
	for(int i=0; i<r; i++){
		array[i] = new double[c];
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			array[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& rhs) //copy constructor
{
	row = rhs.row;
	col = rhs.col;
	array = new double*[row];
	for(int i=0; i<row; i++){
		array[i] = new double[col];
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			array[i][j] = rhs.array[i][j];
		}
	}
}

Matrix::~Matrix() //destructor
{
	for(int i=0; i<row; i++){
		delete [] array[i];
	}
	delete [] array;
}

double* & Matrix::operator [](const int& idx) const	// Enable the use of A[i][j] instead of A.array[i][j]
{
	return array[idx];
}

Matrix Matrix::operator =(const Matrix& rhs) // assignment operator
{
	if(this != &rhs){
		for(int i=0; i<row; i++){
			delete [] array[i];
		}
		delete [] array;
		row = rhs.row;
		col = rhs.col;
		array = new double*[row];
		for(int i=0; i<row; i++){
			array[i] = new double[col];
		}
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				array[i][j] = rhs.array[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator -() const
{
	Matrix new_array = *this;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			new_array.array[i][j] = array[i][j] * -1;
		}
	}
	return new_array;
}

Matrix Matrix::operator +() const
{
	Matrix new_array = *this;
	return new_array;
}

Matrix Matrix::operator -(const Matrix& rhs) const
{
	Matrix new_array = *this;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			new_array.array[i][j] -= rhs[i][j];
		}
	}
	return new_array;
}

Matrix Matrix::operator +(const Matrix& rhs) const
{
	Matrix new_array = *this;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			new_array.array[i][j] += rhs[i][j];
		}
	}
	return new_array;
}

Matrix Matrix::operator *(const Matrix& rhs) const
{
	Matrix mulM(row, rhs.col);
	for(int i=0; i<row; i++){
		for(int j=0; j<rhs.col; j++){
			for(int k=0; k<col; k++){
				mulM.array[i][j] += array[i][k] * rhs.array[k][j];
			}
		}
	}
	return mulM;
}

Matrix Matrix::operator /(const Matrix& rhs) const
{
	Matrix divM(row, rhs.col);
	divM = *this * rhs.inverse();
	return divM;
}

Matrix Matrix::inverse() const
{
	Matrix inverseM(row, col);
	Matrix extent(row, col*2);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			extent.array[i][j] = array[i][j];
		}
	}
	for(int i=0; i<row; i++){
		for(int j=col; j<col*2; j++){
			if(i==(j-col)){
				extent.array[i][j] = 1;
			}
			else{
				extent.array[i][j] = 0;
			}
		}
	}
	for(int i=0; i<row; i++){
		if(extent.array[i][i] == 0){
			for(int j=i; j<row; j++){
				if(extent.array[j][i] != 0){
					for(int k=0; k<col*2; k++){
						double temp;
						temp = extent.array[i][k];
						extent.array[i][k] = extent.array[j][k];
						extent.array[j][k] = temp;
					}
					break;
				}
				if(j==row){
					printf("Cannot inverse the matrix!");
					exit(0);
				}
			}
		}
		for(int j=col*2-1; j>=i; j--){
			extent.array[i][j] /= extent.array[i][i];
		}
		for(int k=0; k<row; k++){
			if(k != i){
				double temp = extent.array[k][i];
				for(int j=0; j<col*2; j++){
					extent.array[k][j] -= temp*extent.array[i][j];
				}
			}
		}
	}

	for(int i=0; i<row; i++){
		for(int j=col; j<col*2; j++){
			inverseM.array[i][j-col] = extent.array[i][j];
		}
	}
	return inverseM;
}

void Matrix::read(const char* fn)
{
	int r, c;
	FILE *fp = fopen(fn, "r");
	if(fp == NULL){
		printf("read file [%s] error\n", fn);
		exit(0);
	}
	fscanf(fp, "%d%d", &r, &c);
	Matrix tmp(r, c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			fscanf(fp, "%lf", &tmp.array[i][j]);
	fclose(fp);
	*this = tmp;
}

void Matrix::write(const char* fn)
{
	FILE *fp = fopen(fn, "w");
	if(fp == NULL){
		printf("write file [%s] error\n", fn);
		exit(0);
	}
	fprintf(fp, "%d %d\n", row, col);
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			fprintf(fp, "%lf%c", array[i][j], " \n"[j==col-1]);
	fclose(fp);
}

void Matrix::print() const
{
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			printf("%lf%c", array[i][j], " \n"[j==col-1]);
}
