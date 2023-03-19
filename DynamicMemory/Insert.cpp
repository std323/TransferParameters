

template<typename T>T* insert(T arr[], int& n, int value, int index)
{
	if (index > n)return arr;
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}