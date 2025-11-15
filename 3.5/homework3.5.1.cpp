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


int main()
{
	setlocale(LC_ALL, "rus");

	int pyramide1[] = { 1, 3, 6, 5, 9, 8 };
	int pyramide1_size = 6;

	int pyramide2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int pyramide2_size = 8;

	int pyramide3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int pyramide3_size = 10;

	print_arr(pyramide1, pyramide1_size);
	print_pyramide(pyramide1, pyramide1_size);

	print_arr(pyramide2, pyramide2_size);
	print_pyramide(pyramide2, pyramide2_size);

	print_arr(pyramide3, pyramide3_size);
	print_pyramide(pyramide3, pyramide3_size);

	return 0;

}


