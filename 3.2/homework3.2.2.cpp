#include <iostream>
#include <iomanip>

int* memory_array;

int fibonacci(const int num)
{
	if (num > 2) {
		if (memory_array[num] != 0)  return memory_array[num];
	}

	if (num == 0)	return 0;
	if (num == 1)	return 1;
	if (num == 2)	return 1;
	memory_array[num] = fibonacci(num - 1) + fibonacci(num - 2);

	return memory_array[num];
}


int main()
{
	setlocale(LC_ALL, "rus");


	int number_from_console = 0;
	std::cout << "Введите количество чисел последовательности Фибоначчи: " << std::endl;
	std::cin >> number_from_console;

	memory_array = new int[number_from_console];
	for (int i = 0; i < number_from_console; i++)
	{
		memory_array[i] = 0;
	}

	for (int i = 0; i < number_from_console; i++)
	{
		std::cout << fibonacci(i) << std::endl;
	}

	// Алгоритмическая сложность по времени O(2^n)
	// Алгоритмическая сложность по памяти O(1), так как новые переменные не заводятся
	delete[] memory_array;

	return 0;

}


