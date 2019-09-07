// Solution to the Egypt problem on open.kattis.com
// Joseph Dempsey, 06/09/2019

#include <iostream>

void sort(int* array) {
	int min, temp;
	for (int i = 0; i < 3; ++i) {
		min = i;
		for (int j = i + 1; j < 3; ++j) 
			if (array[j] < array[min])
				min = j;
		
		if (i != min) {
			//std::cout << "swap!" << std::endl;
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

bool allZero(int* array) {
	bool result = true;
	for (int i = 0; i < 3; ++i)
		if (array[i] != 0)
			result = false;

	return result;
}

void printArray(int* array) {
	for (int i = 0; i < 3; ++i)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main() {
	int numbers[3];
	int a, b, c;

	do {
		std::cin >> numbers[0] >> numbers[1] >> numbers[2];
		if (allZero(numbers))
			break;

		sort(numbers);
		c = numbers[2] * numbers[2];
		b = numbers[1] * numbers[1];
		a = numbers[0] * numbers[0];

		if (c == (b + a))
			std::cout << "right" << std::endl;
		else 
			std::cout << "wrong" << std::endl;
		
	} while (1);
}