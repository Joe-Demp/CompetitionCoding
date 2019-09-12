// function and class templates -> Generic Programming

// programmer writes function template, compiler generates function-template specializations
// e.g.
template<typename T>
void printArray(const T * const array, int count)
{
	for (int i = 0; i < count; ++i)
		cout << array[i] << " ";
	cout << endl;
}

// array could be an int, double or char array
// Need to be careful with using templates for user defined types r.e. overloaded operators etc.

// Overloading, as another template or as another function with different non-template arguments