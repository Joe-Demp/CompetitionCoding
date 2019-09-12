// Stack code taken from fig 14.2 Deitel&Deitel

template<typename T>
class Stack
{
public:
	explicit Stack(int = 10);

	// destructor - to deal with dynamic memory
	~Stack()
	{
		delete [] stackPtr;
	}

	bool push(const T &);
	bool pop(T &);

	bool isEmpty() const
	{
		return top == -1;
	}

	bool isFull() const
	{
		return top == size - 1;
	}

private:
	int size;
	int top;
	T *stackPtr;
};

template<typename T>
Stack<T>::Stack(int s)
	: size(s > 0 ? s : 10),
		top(-1),
		stackPtr(new T[size])
{
	// empty constructor
}

template<typename T>
bool Stack<T>::push(const T &pushValue)
{
	if (!isFull())
	{
		stackPtr[++top] = pushValue;
		return true;
	}

	return false;
}

template<typename T>
bool Stack<T>::pop(T &popValue)
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--];
		return true;
	}

	return false;
}

// Note each method needs the template<..> heading

// e.g. a test function template
template<typename T>
void testStack(Stack<T> &theStack, T value, T increment, const string stackName)
{
	// work....
}
// Notice: compiler infers the type of T from the first argument in list
//	i.e. passing a Stack<int> => value, increment : int