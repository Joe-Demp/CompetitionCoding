// Formatted IO
// to output char * pointers:
cout << static_cast<void *>(word);

// outputting chars
cout.put('A').put('\n');
// or
cout.put(65)	// prints 'A'

// input
cin.get();	// returns character received
cin.get(char* buffer, size_of_buffer);	// places character in buffer
cin.eof();	// true if the program attempts to read past the last character in the stream
cin.getline(char* buffer, size_of_buffer);

// istream member functions
ignore // reads and discards a specified number of characters (default 1)
	// or terminates upon encountering a designated delimiter (default EOF)
putback // places the previous character obtained by a get from an input stream back into that stream
	// e.g. scanning the stream for an input beginning with a certain character
peek // looks at but does not remove the next character from the istream


// Unformatted IO
cout.write(buffer, size);	// outputs the first 10 bytes of the buffer
cin.read(buffer, size);
cin.gcount();				// the number of characters read by the last input operation
