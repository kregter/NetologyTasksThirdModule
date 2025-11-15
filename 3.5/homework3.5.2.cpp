#include <iostream>
#include <iomanip>

void print_arr(int* arr, const int size)
{
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void print_pyramide(int* pyramide, const int pyramid_size)
{
	std::cout << "Пирамида: " << std::endl;
	std::cout << 0 << " root " << pyramide[0] << std::endl;
	for (int i = 1; i < pyramid_size; i++)
	{
		std::cout << static_cast<int>(log2(i + 1));
		if (i % 2 == 0) {
			std::cout << " right(";
		}
		else {
			std::cout << " left(";
		}
		std::cout << pyramide[(i - 1) / 2] << ") " << pyramide[i] << std::endl;
	}
}

void current_location_func(int* pyramide, const int current_location)
{
	std::cout << "Вы находитесь здесь: ";
	if (current_location == 0) {
		std::cout << 0 << " root " << pyramide[current_location] << std::endl;
	}
	else {
		std::cout << static_cast<int>(log2(current_location + 1));
		if (current_location % 2 == 0) {
			std::cout << " right(";
		}
		else {
			std::cout << " left(";
		}
		std::cout << pyramide[(current_location - 1) / 2] << ") " << pyramide[current_location] << std::endl;
	}
}

void pyramide_travel(int* pyramide, const int pyramid_size)
{
	int current_location = 0;
	while (true) 
	{
		current_location_func(pyramide, current_location);
		std::string command{ 0 };
		std::cout << "Доступные команды: up, left, right, exit. Введите команду: ";
		std::cin >> command;
		if (command == "up") {
			if (current_location == 0)
			{
				std::cout << "Ошибка! Отсутствует родитель." << std::endl;
			}
			else {
				current_location = (current_location - 1) / 2;
				std::cout << "ОК" << std::endl;
			}
		}
		else if (command == "left") {
			if ((2 * current_location + 1) >= pyramid_size) {
				std::cout << "Ошибка! Отсутствует левый потомок." << std::endl;
			}
			else {
				current_location = 2 * current_location + 1;
				std::cout << "ОК" << std::endl;
			}
		}
		else if (command == "right") {
			if ((2 * current_location + 2) >= pyramid_size) {
				std::cout << "Ошибка! Отсутствует правый потомок." << std::endl;
			}
			else {
				current_location = 2 * current_location + 2;
				std::cout << "ОК" << std::endl;
			}
		}
		else if (command == "exit") {
			std::cout << "До свидания!" << std::endl;
			return;
		}
		else {
			std::cout << "Такой команды нет в списке, введите правильную команду!" << std::endl;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "rus");

	int pyramide[] = { 1, 3, 6, 5, 9, 8 };
	int pyramide_size = 6;

	print_arr(pyramide, pyramide_size);
	print_pyramide(pyramide, pyramide_size);

	pyramide_travel(pyramide, pyramide_size);

	return 0;

}


