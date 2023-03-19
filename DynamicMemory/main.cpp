#include"stdafx.h"
#include"Constants.h"
#include"FillRand.h"
#include"Allocate.cpp"
#include"Clear.cpp"
#include"Print.cpp"
#include"Puch.cpp"
#include"Insert.cpp"
#include"Pop.cpp"

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
	//cout << "Memory allocated, pess any key to add row" << endl;
	//system("PAUSE");
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << delimiter << endl;
	cout << "Добавление строки в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
		
	cout << delimiter << endl;
	cout << "Удаление строки в конце массива: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Удаление строки в начале массива: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Добавление столбца в конце массива: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Добавление столбца в начале массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Удаление столбца с конца массива: " << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Удаление столбца в начале массива: " << endl;
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
}








