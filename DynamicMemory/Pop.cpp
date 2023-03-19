

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	//1) C������ ����� ������ ������� �������:
	T* buffer = new T[--n];
	//2) �������� ��� ��������, ����� ����������, �� ��������� ������� � �����:
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	// 3) ������� �������� ������:
	delete[] arr;
	//4) ���������� ����� ������ �� ����� �������:
	return buffer;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� �� ������ ��������� ������:
	delete[] arr[rows - 1];
	//2) �������������� ������ ����������:
	T** buffer = new T * [--rows] {};
	//3) �������� ������ ����� ����� ������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4) ������� �������� ������ ����������:
	delete[] arr;
	//5) ���������� ����� ������ �� ����� ������:
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