#include <iostream>
#include <cstdio>
using namespace std;

// https://www.youtube.com/watch?v=LGrE0siZ-ZA
// 1: Check if a number is even or odd
bool evenOdd(int x) {
	return x & 1;
}

// 2: Check if a number is a power of 2
bool powerOf2(int x) {
	return x && !(x & (x-1));
}

// 3: Playing with the kth bit
// (1<<k) = 2^k
// kth least significant bit
	// a: Check if kth bit is set
	bool checkKth(int x, int k) {
		return x & (1<<k);
	}
	// b: Toggle the kth bit
	void toggleKth(int &x, int k) {
		x = x ^ (1<<k);
	}
	// c: Set the kth bit
	void setKth(int &x, int k) {
		x = x | (1<<k);
	}
	// d: Unset the kth bit
	void unsetKth(int &x, int k) {
		x = x & ~(1<<k);
	}

int main()
{
	unsigned int n; cin >> n;

	// (evenOdd(n) == true) ? cout << "odd\n" : cout << "even\n"; 
	// (powerOf2(n) == true) ? cout << "power of 2\n" : cout << "not power of 2\n"; 
	
	// int k; cin >> k;
	// toggleKth(n, k);
	cout << ~n << endl;
	return 0;
}