#pragma once
#include<iostream>
#include<tuple>
//#include<bits/stdc++.h>


class Matrix{

	protected:

		double **A;
		int numRows, numCols;
		
	public:
		Matrix();
		Matrix(int rows, int cols);
		Matrix(const Matrix & obj); // custim copy ctor
		Matrix & operator= (const Matrix & obj);
		void initMatrix();

		
		
		
		void shape();
		Matrix transpose();

		~Matrix();
   		
		friend std::ostream& operator<<(std::ostream & os, const  Matrix & m);
		friend Matrix operator+( const Matrix &M, const Matrix & N);
		friend Matrix operator-(const Matrix &M, const Matrix &N);
		friend Matrix  operator*(const Matrix &M, const Matrix &N);
	
		friend Matrix operator*(const double & c, const Matrix &M);

		Matrix swapRows( int m, int n);
		Matrix scaleRow(double k, int m);
		Matrix subtractRows(int m, int n, double scalefac);

		Matrix gaussEli();

		friend Matrix gaussEli( Matrix & M);
		friend std::tuple<Matrix, Matrix, Matrix, Matrix> lu(Matrix & M);
		friend std::tuple<Matrix, Matrix, Matrix> luCrout(Matrix & M);
		friend Matrix cholesky(Matrix & M);
		static Matrix identity(int n);

		friend Matrix partialSwap(Matrix & M, int, int, int, int);

};


		
