#pragma once

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);

template<typename T>T** pop_col_back(T** arr, const int rows, int& cols);
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols);
