#include <iostream>
#include <iomanip>

int fibonacci(const int num)
{
	if (num == 0)	return 0;
	if (num == 1)	return 1;
	if (num == 2)	return 1;
	return fibonacci(num - 1) + fibonacci(num - 2);
}


int main()
{
	setlocale(LC_ALL, "rus");

	int number_from_console = 0;
	std::cout << "Введите количество чисел последовательности Фибоначчи: " << std::endl;
	std::cin >> number_from_console;

	for (int i = 0; i < number_from_console; i++)
	{
		std::cout << fibonacci(i) << std::endl;
	}

	// Алгоритмическая сложность по времени O(2^n)
	// Алгоритмическая сложность по памяти O(1), так как новые переменные не заводятся

	return 0;

}


