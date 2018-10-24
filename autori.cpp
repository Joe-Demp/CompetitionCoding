#include <iostream>
#include <string>
using namespace std;

int main() {
	string inputStr, outputStr;
	int pos = 0;

	cin >> inputStr;

	if ( inputStr.size() > 0 )
	{
		outputStr += inputStr[ 0 ];		//	first character is always an initial

		//	while the find function still finds hyphens
		while( ( pos = inputStr.find( "-", pos ) ) != -1 ) 
			//	add the character after the hyphen to the string 
			outputStr += inputStr[ ++pos ];

		cout << outputStr;
	}

	return 0;
}	//	end main