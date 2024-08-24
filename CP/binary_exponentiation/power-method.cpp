#include <iostream>

using namespace std;
#define M 1000000007

// O(logb)

int binExpUsingRecursion(int a, int b)
{
	if (b == 0)
		return 1;

	int res = binExpUsingRecursion(a, b / 2);

	if (b & 1)
	{
		return (a * ((res * 1LL * res) % M)) % M;
	}
	else
	{
		return (res * res) % M;
	}
}

int main()
{
	// For 2 ^ 15
	cout << binExpUsingRecursion(2, 15) << endl;

	return 0;
}

/*
Here M = 1000000007

IDEA :)
2^15 = 2 * 2^14
2^14 = 2^7 * 2^7
2^7 = 2 * 2^6
2^6 = 2^3 * 2^3
2^3 = 2 * 2^2
2^2 = 2^1 * 2^1
2^1 = 2 * 2^0

Complexity -> O(logb)
*/