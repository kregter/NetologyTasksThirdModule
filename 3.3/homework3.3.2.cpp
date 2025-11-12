#include <iostream>
#include <iomanip>


int pivoting(int* arr, const int size)
{
	int pi = size / 2;
	int left = 0;
	int right = size - 1;
	int pivot = arr[pi];
	while (true)
	{
		while (arr[left] < pivot)	left++;
		while (arr[right] > pivot)	right--;
		if (left >= right) {
			return left;
		}
		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

void quick_sort(int* arr, const int size)
{
	if (size > 1) {
		int border = pivoting(arr, size);
		quick_sort(arr, border);
		quick_sort(arr + border, size - border);
	}
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

	int arr_size_1 = 10;
	int arr_1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };

	int arr_size_2 = 15;
	int arr_2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };

	int arr_size_3 = 18;
	int arr_3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив: ";
	print_arr(arr_1, arr_size_1);
	quick_sort(arr_1, arr_size_1);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_1, arr_size_1);

	std::cout << "Исходный массив: ";
	print_arr(arr_2, arr_size_2);
	quick_sort(arr_2, arr_size_2);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_2, arr_size_2);

	std::cout << "Исходный массив: ";
	print_arr(arr_3, arr_size_3);
	quick_sort(arr_3, arr_size_3);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_3, arr_size_3);

	return 0;

}


