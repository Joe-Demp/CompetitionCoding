/*
Issues: class not tested rigorously enough (no unit tests)
		Behaviour when encountering a multiplication overflow undefined
		e.g. potential for a zero polynomial returned from x^99 * x^99 or similar

Ideally, the class should be implemented with a dynamic data structure and iterators to navigate said structures
 would allow for Polynomials of any size
*/

#ifndef POLY_H
#define POLY_H

#include <iostream>

class Polynomial
{
	friend std::ostream &operator<<(std::ostream &, const Polynomial &);

	friend int testMaxIndex(Polynomial &);
public:
	static const int MAX_DEGREE = 100;

	Polynomial();	// initializes the zero Polynomial

	void setCoefficient(int, double);
	double getCoefficient(int) const;

	Polynomial operator+(const Polynomial &) const;
	Polynomial operator-(const Polynomial &) const;
	Polynomial operator*(const Polynomial &) const;

	Polynomial &operator+=(const Polynomial &p2) {
		*this = *this + p2;
		return *this;
	}
	Polynomial & operator-=(const Polynomial &p2) {
		*this = *this - p2;
		return *this;
	}
	Polynomial & operator*=(const Polynomial &p2) {
		*this = *this * p2;
		return *this;
	}
private:
	double poly[MAX_DEGREE];
	int max_index;				// helper for printing Polynomials
};

#endif