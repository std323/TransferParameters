

template<typename T>T** Allocate(T rows, int cols)
{
	//1) Cоздаем массив указателей:
	T** arr = new T * [rows];
	//2) Создаем строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}