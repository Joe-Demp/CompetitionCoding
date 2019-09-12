#include <iostream>
#include "Polynomial.h"
using namespace std;

int testMaxIndex(Polynomial &p) { return p.max_index; }

int main() {
	Polynomial p1, p2, p3, p4;

	// TEST empty Polynomial
	cout << "p1.max_index = " << testMaxIndex(p1) << endl;
	cout << "adding coefficients..." << endl;

	p1.setCoefficient(0, 1);
	p1.setCoefficient(1, 1);
	p1.setCoefficient(2, 1);
	p1.setCoefficient(3, 1);
	p1.setCoefficient(4, 1);

	// TEST polynomial with coefficients
	cout << "p1 = " << p1 << endl;
	cout << "p1.max_index = " << testMaxIndex(p1) << endl;

	// TEST changing max_index
	p1.setCoefficient(2, 0);
	p1.setCoefficient(4, 0);
	cout << "\np1 = " << p1 << endl;
	cout << "p1.max_index = " << testMaxIndex(p1) << endl;

	p1.setCoefficient(10, 3.5);
	cout << "\np1 = " << p1 << endl;
	cout << "p1.max_index = " << testMaxIndex(p1) << endl;

	// Test overloaded + operator
	p3 = p1 + p2;
	cout << "\np3 = p1 + p2 = " << p3 << endl;
	cout << "p3.max_index = " << testMaxIndex(p3) << endl;

	// Test overloaded - operator
	p2.setCoefficient(0, 5);
	p2.setCoefficient(1, -13);
	p2.setCoefficient(2, -7);
	p2.setCoefficient(3, 2);

	p4.setCoefficient(0, -24);
	p4.setCoefficient(1, -10);
	p4.setCoefficient(2, 2);
	p4.setCoefficient(3, 5);
	cout << "\np2 = " << p2 << endl;
	cout << "\np4 = " << p4 << endl;
	cout << "p4 - p2 = " << p4 - p2 << endl;

	// TEST assignment operator
	Polynomial p5 = p4;
	cout << "\np5 = " << p5 << endl;
	cout << "p5.max_index = " << testMaxIndex(p5) << endl;

	// TEST Multiplication operator
	Polynomial p6;
	p6.setCoefficient(0, 1);
	p6.setCoefficient(1, -15);
	p6.setCoefficient(2, 13);
	cout << "\np6 = " << p6 << endl;
	cout << "p7 = p5 * p6" << endl;
	Polynomial p7 = p5 * p6;
	cout << "p7 = " << p7 << endl;
	cout << "p7.max_index = " << testMaxIndex(p7) << endl;

	// Test += operator
	p7 += p4;
	cout << "\np7 += p4" << endl;
	cout << "p7 = " << p7 << endl;
}
