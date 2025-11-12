#include <iostream>
#include <iomanip>


void fill_dynamic_array(int* arr, const int logical_size, const int actual_size)
{
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << "Введите arr[" << i << "]: " << std::endl;
			std::cin >> arr[i];
		}
		else {
			arr[i] = 0;
		}
	}
}

void print_dynamic_array(int* arr, const int logical_size, const int actual_size)
{
	std::cout << "Динамический массив:";
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << " " << arr[i];
		}
		else {
			std::cout << " _";
		}
	}
	std::cout << std::endl;
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, const int append_to_arr) {
	if (logical_size < actual_size) {
		arr[logical_size] = append_to_arr;
		logical_size++;
	}
	else {
		int* temporary_array = new int[actual_size * 2];
		for (int i = 0; i < actual_size * 2; i++) {
			if (i < actual_size)	temporary_array[i] = arr[i];
			else					temporary_array[i] = 0;
		}
		delete[] arr;

		arr = temporary_array;
		arr[logical_size] = append_to_arr;
		logical_size++;
		actual_size = actual_size * 2;
	}
	
	return arr;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int actual_size = 0;
	int logical_size = 0;

	std::cout << "Введите фактический размер массива: " << std::endl;
	std::cin >> actual_size;

	std::cout << "Введите логический размер массива: " << std::endl;
	std::cin >> logical_size;

	if (logical_size > actual_size) {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
	}
	else {
		int* arr = new int[actual_size];
		fill_dynamic_array(arr, logical_size, actual_size);
		print_dynamic_array(arr, logical_size, actual_size);
		while (true) {
			int append_to_arr = 0;
			std::cout << "Введите элемент для добавления: " << std::endl;
			std::cin >> append_to_arr;
			if (append_to_arr == 0) {
				print_dynamic_array(arr, logical_size, actual_size);
				break;
			}
			else {
				arr = append_to_dynamic_array(arr, logical_size, actual_size, append_to_arr);
				print_dynamic_array(arr, logical_size, actual_size);
			}
		}
		delete[] arr;
	}

	return 0;

}


