

template<typename T>T* puch_back(T arr[], int& n, int value)
{
	//1) Cоздаем новый массив нужного размера:
	T* buffer = new T[n + 1];
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

template<typename T>T* push_front(T arr[], int& n, int value)
{
	//1) Cоздаем новый массив нужного размера (на 1 элемент больше):
	T* buffer = new T[n + 1];
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
template<typename T>T** push_row_back(T* arr[], int& rows, const int cols)
{
	//1)Переопределяем массив указатедей:
	int** buffer = new int* [rows + 1] {};
	//2) Копируем адреса строк из исходного массива указателей в новый массив:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) Удаляем старый массив указателей:
	delete[] arr;
	//4) Добавляем новую строку в новый массив указателей:
	buffer[rows] = new int[cols] {};
	//5) После добавления строки количество строк увеличивается на 1:
	rows++;
	//6) Возвращаем новый массив на место вызова:
	return buffer;
}
template<typename T>T** push_row_front(T* arr[], int& rows, const int cols)
{
	T** buffer = new T * [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols++;
}
