#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;


//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;//pa - Pointer to a (указатель на переменную 'а')
	cout << a << endl;//¬ывод значени€ переменной 'а' на экран
	cout << &a << endl;//¬з€тие адреса переменной 'а' пр€мо при выводе
	cout << pa << endl;// ¬ывод адреса переменной 'а', хран€щегос€ в указателе 'ра'
	cout << *pa << endl;//–азименование указател€ 'ра', дл€ того чтобы получить значение по адресу

	int* pb;
	int b = 3;
	pb = &b;
	/*
	-------------------------
	int - int
	int* - ”казатель на 'int'
	double - double
	double* - ”казательна 'double'
	-------------------------
	*/

#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	//cout << main << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << arr + i << "\t"; - получим адреса значений массива
		cout << *(arr + i) << "\t"; //разыменовать вычисленный адрес
	}
	cout << endl;
}