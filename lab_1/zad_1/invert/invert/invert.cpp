#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const int NUM_ARGUMENT = 2;
const int MAX_MATRIX = 3;
typedef float Matrix3x3[MAX_MATRIX][MAX_MATRIX];

float DetMiniMatrix(int k, int m, Matrix3x3& matrix)
{
	if (k == 0)
	{
		if (m == 0)
		{
			return (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
		}
		else if (m == 1)
		{
			return (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
		}
		else
		{
			return (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
		}
	}
	else if (k == 1)
	{
		if (m == 0)
		{
			return (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
		}
		else if (m == 1)
		{
			return (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
		}
		else
		{
			return (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
		}
	}
	else
	{
		if (m == 0)
		{
			return (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
		}
		else if (m == 1)
		{
			return (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
		}
		else
		{
			return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
		}
	}
}

float DeterMatrix(Matrix3x3& matrix)
{
	float deter;

	deter = matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][0] * matrix[1][2] * matrix[2][1] -
		matrix[0][1] * matrix[1][0] * matrix[2][2];

	return deter;
}

bool ReadInputMatrix(Matrix3x3& matrix, string fileInName)
{
	ifstream fileInput(fileInName);

	if (!fileInput.is_open())
	{
		return false;
	}

	for (size_t i = 0; i < MAX_MATRIX; i++)
	{
		for (size_t j = 0; j < MAX_MATRIX; j++)
		{
			float number;
			fileInput >> number;
			matrix[i][j] = number;
		}
	}

	return true;
}

void MinorMatrix(Matrix3x3& matrix, Matrix3x3& minMatrix)
{
	for (size_t i = 0; i < MAX_MATRIX; i++)
	{
		for (size_t j = 0; j < MAX_MATRIX; j++)
		{
			if (((i == 0) && (j == 1)) || ((i == 2) && (j == 1)) || ((i == 1) && (j == 0)) || ((i == 1) && (j == 2)))
			{
				minMatrix[i][j] = -(DetMiniMatrix(i, j, matrix));
			}
			else
			{
				minMatrix[i][j] = DetMiniMatrix(i, j, matrix);
			}
		}
	}
}

bool InvertMatrix(Matrix3x3& matrix, Matrix3x3& matrixRes)
{
	float det = DeterMatrix(matrix);

	if (det == 0)
	{
		return false;
	}

	Matrix3x3 minorMatrix;

	MinorMatrix(matrix, minorMatrix);

	for (size_t i = 0; i < MAX_MATRIX; i++)
	{
		for (size_t j = 0; j < MAX_MATRIX; j++)
		{
			matrixRes[i][j] = minorMatrix[j][i] / det;
		}
	}

	return true;
}

void PrintMatrixResult(Matrix3x3& outMatrix)
{
	for (size_t i = 0; i < MAX_MATRIX; i++)
	{
		for (size_t j = 0; j < MAX_MATRIX; j++)
		{
			cout << fixed << setprecision(3) << outMatrix[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(int argc, char* argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		return 1;
	}

	string fileInputName = argv[1];

	if (fileInputName.empty())
	{
		return 1;
	}

	Matrix3x3 inputMatrix;

	if (!ReadInputMatrix(inputMatrix, fileInputName))
	{
		return 1;
	}

	Matrix3x3 resultMatrix;

	if (!InvertMatrix(inputMatrix, resultMatrix))
	{
		return 1;
	}

	PrintMatrixResult(resultMatrix);

	return 0;
}