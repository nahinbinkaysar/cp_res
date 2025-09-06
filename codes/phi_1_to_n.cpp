#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void phi_1_to_n(int n) {
	vector<int> phi(n+1);
	for (int i = 0; i <= n; i++) phi[i] = i;
	for (int i = 2; i <= n; i++) {
		if(phi[i] == i) {
			// i is a prime
			// i, 2i, 3i,... <= I am iterating over
			// those numbers where i is a prime factor
			for (int j = i; j <= n; j+=i) {
				phi[j] -= phi[j]/i;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		cout << i << " " << phi[i] << endl;
	}

}

int main()
{
	int n; cin >> n;
	phi_1_to_n(n);
}