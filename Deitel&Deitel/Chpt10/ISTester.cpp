#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main() 
{
	IntegerSet set1, set2;
	set1.printSet();

	if (set1.isEqualTo(set2))
		cout << "\nThe sets are equal\n";

	set1.insertElement(0);
	set1.insertElement(10);
	set1.insertElement(15);
	set1.insertElement(49);
	set1.insertElement(8);
	set1.insertElement(-1);
	set1.insertElement(10);

	set1.printSet();
	if (!set1.isEqualTo(set2))
		cout << "\nThe sets are not equal\n\n";

	IntegerSet set3(set1);
	cout << "set3 = "; set3.printSet();
	if (set3.isEqualTo(set1))
		cout << "\nset3 is equal to set1\n";

	cout << "deleting '10' from set3\n";
	set3.deleteElement(10);
	cout << "set3 = "; set3.printSet();
	if (!set3.isEqualTo(set1))
		cout << "\nset3 is not equal to set1\n\n";

	//UNION
	set2.insertElement(0);
	set2.insertElement(11);
	set2.insertElement(15);
	set2.insertElement(49);
	set2.insertElement(8);
	set2.insertElement(20);
	set2.insertElement(25);

	cout << "set2 = "; set2.printSet();
	IntegerSet oneUniontwo = set1.unionOfSets(set2);
	cout << "\nset1 UNION set2 = "; oneUniontwo.printSet();

	//INTERSECTION
	IntegerSet oneINTtwo = set1.intersectionOfSets(set2);
	cout << "\nset1 INTERSECTION set2 = "; oneINTtwo.printSet();

	//Overloaded constructor
	int testarray[] = {3, 14, 57, 99, 1000};
	IntegerSet set4(testarray, 5);
	cout << "\n\nset4 = "; set4.printSet();
}