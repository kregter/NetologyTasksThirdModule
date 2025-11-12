#include <iostream>
#include <iomanip>


void count_sort(int* arr, const int size)
{
	int* counts = new int[size];
	for (int i = 0; i < size; i++) {
		counts[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		counts[arr[i]] += 1;
	}

	int c = 0;
	for (int i = 0; i < size; i++) {
		while (counts[c] == 0) {
			c += 1;
		}
		arr[i] = c;
		counts[c] -= 1;
	}

	delete[] counts;
}

void print_arr(int* arr, const int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int arr_size_1 = 30;
	int arr_1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };

	int arr_size_2 = 40;
	int arr_2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };

	int arr_size_3 = 45;
	int arr_3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

	std::cout << "Исходный массив: ";
	print_arr(arr_1, arr_size_1);
	count_sort(arr_1, arr_size_1);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_1, arr_size_1);

	std::cout << "Исходный массив: ";
	print_arr(arr_2, arr_size_2);
	count_sort(arr_2, arr_size_2);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_2, arr_size_2);

	std::cout << "Исходный массив: ";
	print_arr(arr_3, arr_size_3);
	count_sort(arr_3, arr_size_3);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_3, arr_size_3);

	return 0;

}


