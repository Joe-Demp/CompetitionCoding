// My implementation of QuickSort in C++
// Joseph Dempsey 08/09/2019

#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 100
#define MAX 100
using namespace std;

void quickSort(int array[], int start, int end);
int partition(int array[], int left, int right, int pindex);
void swap(int array[], int a, int b);

// Helper functions
void printArray(int array[], int left, int right);
void fillArray(int array[]);
bool sorted(int array[]);

// Test driver programme
int main()
{
	srand(time(NULL));

	int array[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		fillArray(array);
		// printArray(array, 0, SIZE - 1);
	
		quickSort(array, 0, SIZE - 1);
		// printArray(array, 0, SIZE - 1);
		if (sorted(array))
			cout << "array sorted" << endl;
		else cout << "array not sorted" << endl;
	}

	return 0;
}

/*
	end = index of the last element in the array
*/
void quickSort(int array[], int start, int end)
{
	if (start < end) {
		// partition
		int pivot_index = start + (rand() % (end - start + 1));
		int divide = partition(array, start, end, pivot_index);

		// quicksort left and right section
		quickSort(array, start, divide);
		quickSort(array, divide + 1, end);
	}
}

int partition(int array[], int left, int right, int pindex)
{
	// Check pindex is in range
	if (pindex >= left && pindex <= right) {
		int pivot = array[pindex];

		while (left <= right) {
			while (array[left] < pivot)
				left++;

			while (array[right] > pivot)
				right--;

			if (left <= right) {
				swap(array, left, right);
				left++;
				right--;
			}
		}

		return left - 1;
	} else return -1;
}

void swap(int array[], int a, int b)
{
	int hold = array[a];
	array[a] = array[b];
	array[b] = hold;
}

void printArray(int array[], int left, int right) {
	cout << "{";
	for (int i = left; i <= right; ++i)
		cout << array[i] << " ";
	cout << "}\n";
}
void fillArray(int array[]) {
	for (int i = 0; i < SIZE; ++i)
		array[i] = rand() % MAX;
}
bool sorted(int array[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (array[i] > array[i + 1])
			return false;
	return true;
}