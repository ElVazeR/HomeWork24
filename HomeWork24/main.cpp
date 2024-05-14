#include <iostream>
#include <cstdlib>
#include <ctime>
// Вывод массива в консоль.

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
// Заполнение массива случайными числами.
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void resize_arr(T*& arr, int& length, int new_length) {
	if (new_length <= 0){
		delete[] arr;
		arr = nullptr;
		std::cout << "Массив удалён\n";
		return;
	}
	T* tmp = new T[new_length];
	for (int i = 0; i < new_length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	length = new_length;
}



int main() {
	setlocale(LC_ALL, "Russian");

	// ЗАДАЧА 1.
	std::cout << "Задача 1.\n Введите размеры массивов -> ";
	int n, m;
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 10, 21);
	fill_arr(B, m, 23, 50);
	std::cout << "Первый массив:\n";
	print_arr(A, n);
	std::cout << "Второй массив:\n";
	print_arr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n; i++) 
		C[i] = A[i];
	
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	std::cout << "Скрещенный массив:\n";
	print_arr(C, n + m);
	delete[] A;
	delete[] B;

	// ЗАДАЧА 2.
	std::cout << "Задача 2.\n Введите размер массива -> ";
	int size;
	std::cin >> size;
	int* d_arr = new int[size];
	fill_arr(d_arr, size, 10, 21);
	print_arr(d_arr, size);
	std::cout << "Введите новый размер массива -> ";
	int new_size;
	std::cin >> new_size;
	resize_arr(d_arr, size, new_size);
	std::cout << "Итоговый массив:\n";
	print_arr(d_arr, size);








	return 0;
}