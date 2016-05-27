// Laba4_Matricy.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>

using namespace std;


class Ring
{
public:
	int r;
	Ring(int a)
	{
		r = a%10;
	}
	Ring()
	{
		r = 0;
	}
	Ring operator+ (const Ring& a) //перегрузка оператора +
	{
		Ring result((a.r + r));
		return result;
	}
	Ring operator* (Ring& a) //перегрузка оператора *
	{
		Ring result((a.r*r));
		return result;
	};

	friend std::ostream& operator<< (std::ostream&, const Ring&);
    
	~Ring() {}
};
std::ostream& operator<< (std::ostream& c, const Ring& d) 
{
	c   << d.r<<'\t' ;
	return c;
}

class Matrix
{
	Ring **matrix1;
public:
	int m = 4;
	int n = 4;
	Matrix()
	{
		matrix1 = new Ring *[n];
		for (int i = 0; i<n; i++)
		{
			matrix1[i] = new Ring[m];
		}
	}
	void print_matrix() //печать матрицы
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix1[i][j] = rand() % 100 + 1;
				cout<<matrix1[i][j];

			}
			cout << endl;
		}
		
	}
	void Vivod_matrix()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << matrix1[i][j];
			cout << endl;
		}
	}

	Ring& index(int x, int y)//обращение по элементу
	{
		return matrix1[x][y];
	}
	Matrix(Ring** sum)
	{

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix1[i][j] = sum[i][j];
			}
		}
	}

	Matrix Matrix::operator < (Matrix&matrix2) //перегрузка оператора транспонировани€
	{
		Matrix sum(*this);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sum.matrix1[j][i] = matrix2.matrix1[i][j];
			}
		}
		return sum;


	}
	Matrix Matrix::operator+ (Matrix&matrix2) //перегрузка оператора +
	{
		Matrix sum(*this);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					sum.matrix1[i][j] = matrix2.matrix1[i][j]+ matrix1[i][j];
				}
			}
return sum;

	}
	
	Matrix Matrix::operator* (Matrix&matrix2)//перегрузка оператора *
	{

		Matrix sum(*this);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sum.matrix1[i][j] = 0;
				for (int k = 0; k < n; k++) {
					sum.matrix1[i][j] = sum.matrix1[i][j] + (matrix1[k][j] * matrix2.matrix1[i][k]);
				}
			}
		}

		return sum;
	}


	~Matrix() {}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Matrix mat1, mat2, mat3, mat4, mat5;
	cout << "ћатрица 1" << endl;
	mat1.print_matrix(); //печать матрицы
	cout << endl << "индексирование:" << mat1.index(0, 0); //обращение по элементу endl;
	cout << endl << "ћатрица 2"<<endl;
	mat2.print_matrix();
	cout << endl << "“ранспанированна€ матрица" << endl;
	mat5  < mat1;
	mat5.Vivod_matrix();
	cout << endl<<"ћатрица сложени€" << endl;
	mat3 = mat1 + mat2;
	mat3.Vivod_matrix();
	cout << endl<<"ћатрица умножени€" << endl;
	mat4 = mat1 * mat2;
	mat4.Vivod_matrix();
	cout << endl;
	system("PAUSE");
	return 0;
}