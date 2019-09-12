// dec, oct, hex, setbase():
// #Sticky
int number = 23;

cout << number << " in octal is " << oct << number << endl;
cout << setbase(10) << number << " in hex is " << hex << number << endl;

// note: need to fix cout once you've changed it


// precision, setprecision()
// #Sticky
cout.precision();	// returns current precision
cout.precision(int)	// sets precision, or:
cout << setprecision(int);


// width, setw 
// #Non-sticky
cin.width(int);	// sets width
cin.width();	// returns the current setting
cin >> setw(2) >> number;