

template<typename T>T** Allocate(T rows, int cols)
{
	//1) C������ ������ ����������:
	T** arr = new T * [rows];
	//2) ������� ������ ���������� �������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}