// Solution to the Speed Limit problem on open.kattis.com
// Joseph Dempsey, 30/08/2019

#include <iostream>
#define SETS 10

// input: between 1 and 10 data sets
//	each with an integer n [1, 10] specifying a number of values
//	each set of values, s t, representing a speed and a time elapsed 

//	Algorithm:
//		take in n, keep for later
//			check n does not equal -1
//		take in s and t 'n' times
//		each time: the formula is: (t_i - t_(i-1)) * s
//			t0 and t1 used for simplicity
//			initially t0 = 0 (at the start of the loop)
//		at the end of the set, take the running total and print

int main() 
{
	int n = 0; 
	int s, t0, t1;
	int running_total;
	int results[SETS];
	int j = 0;

	while (n >= 0) 
	{
		// initial conditions
		std::cin >> n;
		t0 = 0;
		running_total = 0;

		for (int i = 0; i < n; ++i) 
		{
			std::cin >> s >> t1;
			running_total += ((t1 - t0) * s);
			t0 = t1;
		}

		//store result
		results[j] = running_total;
		++j;
	}

	// print result
	for (int i = 0; i < j-1; ++i) 
		std::cout << results[i] << " miles" << std::endl;
}