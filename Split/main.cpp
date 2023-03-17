#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Container(int* arr, const int n, int& num_even, int& num_odd);
void Split(int* arr, int* even_arr, int* odd_arr, const int n);


void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	cout << "Исходный массив: \n" << endl;
	Print(arr, n);

	int num_even=0;
	int num_odd = 0;
	
	Container(arr, n, num_even, num_odd);
	
	int* even_arr = new int[num_even];
	int* odd_arr = new int[num_odd];
	
	Split(arr, even_arr, odd_arr, n);
	cout << "Массив четных элементов: \n" << endl;
	Print(even_arr, num_even);
	cout << "Массив нечетных элементов: \n" << endl;
	Print(odd_arr, num_odd);
	delete[] even_arr;
	delete[] odd_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;//обращение к элементам массива через
		//арифметику указателей и оператор разыменования
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
}
void Container(int* arr, const int n, int& num_even, int& num_odd)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			num_even++;
		}
		else
		{
			num_odd++;
		}
	}
}
void Split(int* arr, int* even_arr, int* odd_arr, const int n)
{
	int k = 0, l = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_arr[k] = arr[i];
			k++;
		}
		else
		{
			odd_arr[l] = arr[i];
			l++;
		}
	}
}