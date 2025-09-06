#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> findFactors(ll n) {
	vector<ll> factors;
	for (ll d = 1; d*d <= n; d++) {
		if(n % d == 0) {
			factors.push_back(d);
			if(n/d != d) {
				factors.push_back(n/d);
			}
		}
	}
	return factors;
}

int main()
{
	ll n; cin >> n;
	for(auto i:findFactors(n)) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}