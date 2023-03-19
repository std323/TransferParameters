

template<typename T>T* puch_back(T arr[], int& n, int value)
{
	//1) C������ ����� ������ ������� �������:
	T* buffer = new T[n + 1];
	//2) �������� ��� ���������� ��������� ������� � �����:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ����� ������� �������, ������� ������ �������:
	arr = buffer;
	//5) ������ ����� ����� ����� � ������� 'arr' ���������� �������, 
	//� ������� ����� ��������� ����������� ��������:
	arr[n] = value;
	//6) ����� ���������� �������� � ������, ���������� ��� ��������� ������������� �� 1
	n++;
	return arr;
}

template<typename T>T* push_front(T arr[], int& n, int value)
{
	//1) C������ ����� ������ ������� ������� (�� 1 ������� ������):
	T* buffer = new T[n + 1];
	//2) �������� ��� ���������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) �������� ����������� �������� � ������ �������:
	buffer[0] = value;
	//5) ����� ���������� �������� � ������ �������, 
	//   ���������� ��� ��������� ������������� �� 1:
	n++;
	//6) ���������� ����� ������ �� ����� ������:
	return buffer;
}
template<typename T>T** push_row_back(T* arr[], int& rows, const int cols)
{
	//1)�������������� ������ ����������:
	int** buffer = new int* [rows + 1] {};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ����� ������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) ������� ������ ������ ����������:
	delete[] arr;
	//4) ��������� ����� ������ � ����� ������ ����������:
	buffer[rows] = new int[cols] {};
	//5) ����� ���������� ������ ���������� ����� ������������� �� 1:
	rows++;
	//6) ���������� ����� ������ �� ����� ������:
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
