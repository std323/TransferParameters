#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* puch_back(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Ввдите значение добавляемого элемента: "; cin >> value;

	arr = puch_back(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = push_front(arr, n, value);
	Print(arr, n);

	int index = 0;
	cout << "Введите индекс элемента: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	


	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;//обращение к элементам массива через
		//арифметику указателей и оператор разыменования:
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элемeнтам массива через оператор индексирования:
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* puch_back(int arr[], int& n, int value)
{
	//1) Cоздаем новый массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем все содержимое исходного массива в новый:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес старого массива, адресом нового массива:
	arr = buffer;
	//5) Только после всего этого в массиве 'arr' появляется элемент, 
	//в который можно сохранить добавляемое значение:
	arr[n] = value;
	//6) После добавления элемента в массив, количество его элементов увеличивается на 1
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	arr[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	
	return buffer;
}
