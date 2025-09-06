#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> primeFactorization(ll n) {
	vector<ll> factorization;
	for (ll d = 2; d*d <= n; d++) {
		if(n % d == 0) {
			factorization.push_back(d);
			while(n % d == 0) n /= d;
		}
	}
	if(n > 1) factorization.push_back(n);
	return factorization;
}

int main()
{
	ll n; cin >> n;
	for(auto i:primeFactorization(n)) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}