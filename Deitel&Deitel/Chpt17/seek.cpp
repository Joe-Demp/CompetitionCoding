// move the pointer to the nth byte of fileObject
fileObject.seekg(n);
// equivalently
fileObject.seekg(n, ios::beg);

// move the pointer n bytes forward in fileObject
fileObject.seekg(n, ios::cur);

// move the pointer n bytes back from the end of fileObject
fileObject.seekg(n, ios::end);

// if n = 0, pointer sent to the end of the file

// Same for ostream function seekp();