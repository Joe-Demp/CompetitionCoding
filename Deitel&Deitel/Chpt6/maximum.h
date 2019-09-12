// Deitel & Deitel Chpt 6 pg 237

template<typename T>
T maximum(T v1, T v2, T v3) 
{
	T max = v1;

	if (v2 > max)
		max = v2;

	if (v3 > max)
		max = v3;

	return max;
}