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
		delete[] arr;
	}

	return 0;

}


