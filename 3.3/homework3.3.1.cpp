#include <iostream>
#include <iomanip>


void merge_sort(int* arr, const int size)
{
	if (size != 1) {
		int middle_size = size / 2;
		merge_sort(arr, middle_size);
		merge_sort(arr + middle_size, size - middle_size);

		int left_counter = 0;
		int right_counter = middle_size;
		int arr_counter = 0;

		int* merged_arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			merged_arr[i] = 0;
		}

		while ((left_counter < middle_size) || (right_counter < size))
		{
			if (left_counter == middle_size) {
				merged_arr[arr_counter] = arr[right_counter];
				right_counter++;
			}
			else if (right_counter == size) {
				merged_arr[arr_counter] = arr[left_counter];
				left_counter++;
			}
			else {
				if (arr[left_counter] <= arr[right_counter]) {
					merged_arr[arr_counter] = arr[left_counter];
					left_counter++;
				}
				else {
					merged_arr[arr_counter] = arr[right_counter];
					right_counter++;
				}
			}
			arr_counter++;
		}

		for (int i = 0; i < size; i++)
		{
			arr[i] = merged_arr[i];
		}
		delete[] merged_arr;
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
	merge_sort(arr_1, arr_size_1);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_1, arr_size_1);

	std::cout << "Исходный массив: ";
	print_arr(arr_2, arr_size_2);
	merge_sort(arr_2, arr_size_2);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_2, arr_size_2);

	std::cout << "Исходный массив: ";
	print_arr(arr_3, arr_size_3);
	merge_sort(arr_3, arr_size_3);
	std::cout << "Отсортированный массив: ";
	print_arr(arr_3, arr_size_3);

	return 0;

}


