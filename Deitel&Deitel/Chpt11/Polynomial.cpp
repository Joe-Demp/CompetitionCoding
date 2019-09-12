#include <iostream>
#include "Polynomial.h"
using namespace std;

ostream &operator<<(ostream &output, const Polynomial &pnomial)
{
	output << "(";
	for (int i = 0; i <= pnomial.max_index; ++i)
	{
		output << pnomial.poly[i];
		if (i != pnomial.max_index)
			output << ", ";
	}
	output << ")";
	return output;
}

Polynomial::Polynomial()
	: max_index(-1)
{
	for (int i = 0; i < MAX_DEGREE; ++i)
		poly[i] = 0;
}

void Polynomial::setCoefficient(int index, double coeff)
{
	//bounds check on the index
	if (index < MAX_DEGREE && index >= 0) {	
		poly[index] = coeff;

		// change max_index if setting the max_index coefficient to 0
		if (index == max_index && coeff == 0.0) {
			// find the next smallest max_index
			for (int i = max_index; i >= 0; --i)
				if (poly[i] != 0.0) {
					max_index = i;
					break;	// once the max index is found, no need to continue
				} 
				else if(i == 0) // if all coefficients are zero, then set max_index as -1 
					max_index = -1;
		} 
		//	or if index > max_index and coeff != 0
		else if (index > max_index && coeff != 0.0) {
			// set max_index to be the new index
			max_index = index;
		} 
		// index is less than the max_index, no problems		
	}
}

double Polynomial::getCoefficient(int index) const
{
	if (index < MAX_DEGREE && index >= 0) // if index in range
		return poly[index];

	else return 0;
}

Polynomial Polynomial::operator+(const Polynomial &p2) const
{
	// find the greater max_index
	int greater_max = this->max_index;
	if (p2.max_index > greater_max) 
		greater_max = p2.max_index;

	Polynomial result;
	for (int i = 0; i <= greater_max; ++i) { 
		double new_coefficient = this->getCoefficient(i) + p2.getCoefficient(i);
		result.setCoefficient(i, new_coefficient);
	}
	return result;
}

Polynomial Polynomial::operator-(const Polynomial &p2) const
{
	// create a copy of p2 with all of its coefficients negated
	//	add this to the copy
	Polynomial negated(p2);
	for (int i = 0; i <= negated.max_index; ++i) {
		double coeff = -1.0 * negated.getCoefficient(i);
		negated.setCoefficient(i, coeff);
	}
	return *this + negated;
}

Polynomial Polynomial::operator*(const Polynomial &p2) const
{
	Polynomial result;

	// multiply the coefficients, add the indices
	// if index > MAX_DEGREE, move on and ignore
	int nindex;
	double ncoeff, temp;
	for (int i = 0; i <= this->max_index; ++i) {
		for (int j = 0; j <= p2.max_index; ++j) {
			nindex = i + j;
			if (nindex < MAX_DEGREE) {
				ncoeff = this->poly[i] * p2.poly[j];
				temp = result.getCoefficient(nindex);
				result.setCoefficient(nindex, ncoeff + temp);
			}
			else 
				break;	// the inner loop can stop because nindex only gets bigger
		}
	}
	return result;
}