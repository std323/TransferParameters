

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	//1) Cоздаем новый массив нужного размера:
	T* buffer = new T[--n];
	//2) Копируем все элементы, кроме удаляемого, из исходного массива в новый:
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	// 3) Удаляем исходный массив:
	delete[] arr;
	//4) Возвращаем новый массив на место вызоыва:
	return buffer;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) Удаляем из памяти последнюю строку:
	delete[] arr[rows - 1];
	//2) Переопределяем массив указатедей:
	T** buffer = new T * [--rows] {};
	//3) Копируем адреса строк новый массив:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4) Удаляем исходный массив указателей:
	delete[] arr;
	//5) Возвращаем новый массив на место вызова:
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[] arr[0];
	T** buffer = new T * [--rows] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}