#include <iostream>
#include <iomanip>

int counting_function(const int arr[], int start_point, int size_of_array)
{
	int start = 0;
	int end = size_of_array - 1;
	int mid = 0;

	if (start_point >= arr[size_of_array - 1]) {
		return 0;
	}

	while (start < end)
	{
		mid = (start + end) / 2;
		if (arr[mid] > start_point)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	mid = (start + end) / 2;
	return (size_of_array - mid);
}


int main()
{
	setlocale(LC_ALL, "rus");

	//task 1.8.1
	std::cout << "Введите точку отсчета: " << std::endl;
	int start_point = 0;
	std::cin >> start_point;
	const int size_of_array = 9;
	int arr[size_of_array] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	std::cout << "Количество элементов в массиве больших, чем " << start_point << ": " << counting_function(arr, start_point, size_of_array);


	return 0;

}


