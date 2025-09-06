#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// given Q queries find out the number of divisors of X

// precalculation O(NlogN)
// N = 1e6
// query O(Q)
// overall
//   O(NlogN) + O(Q)
// = O(NlogN + Q)
// = O(XlogX), X is the largest number (maybe equal to N)

int main()
{
	vector<int> factors(1e6+1, 0);
	for (int i = 1; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j+=i) {
			factors[j]++;
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int X; cin >> X;
		cout << factors[X] << endl;
	}
	
	
	return 0;
}