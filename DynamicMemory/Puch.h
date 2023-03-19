#pragma once

template<typename T>T* puch_back(T arr[], int& n, int value);
template<typename T>T* push_front(T arr[], int& n, int value);

template<typename T>T** push_row_back(T* arr[], int& rows, const int cols);
template<typename T>T** push_row_front(T* arr[], int& rows, const int cols);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);