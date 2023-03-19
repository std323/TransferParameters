#include"Print.h"

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ����e���� ������� ����� �������� ��������������:
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//cout << arr[i][j] << "\t";
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
}