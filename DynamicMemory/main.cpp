#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------\n"

int** Allocate(int rows, int cols);
void Clear(int** arr, int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* puch_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int** push_row_back(int* arr[], int rows, int cols);

int* insert(int arr[], int& n, int value, int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()

{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Ввдите значение добавляемого элемента: "; cin >> value;

	arr = puch_back(arr, n, value);
	Print(arr, n);

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого  элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1


	int rows, cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	Clear(arr, rows);
}

int** Allocate(int rows, int cols)
{
	//1) Cоздаем массив указателей:
	int** arr = new int* [rows];
	//2) Создаем строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
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

void FillRand(int** arr, const int rows, const int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//cout << arr[i][j] << "\t";
			cout << *(*(arr + i)+j) << "\t";
		}
		cout << endl;
	}
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

int* push_front(int arr[], int& n, int value)
{
	//1) Cоздаем новый массив нужного размера (на 1 элемент больше):
	int* buffer = new int[n + 1];
	//2) Копируем все содержимое из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Помещаем добавляемое значение в начало массива:
	buffer[0] = value;
	//5) После добавления элемента в начало массива, 
	//   количество его элементов увеличивается на 1:
	n++;
	//6) Возвращаем новый массив на место вызова:
	return buffer;
}

int** push_row_back(int* arr[], int rows, int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
	}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				buffer[i][j] = arr[i][j];
			}
		}
		Clear(arr, rows);
		
		rows++;
		return buffer;
	
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	//1) Cоздаем новый массив нужного размера:
	int* buffer = new int[--n];
	//2) Копируем все элементы, кроме удаляемого, из исходного массива в новый:
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	// 3) Удаляем исходный массив:
	delete[] arr;
	//4) Возвращаем новый массив на место вызоыва:
	return buffer;
}

int* insert(int arr[], int& n, int value, int index)
{
	if (index > n)return arr;
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}