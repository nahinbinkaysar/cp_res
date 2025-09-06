#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// given Q queries find out the number of divisors of X

// sieve precomputation // O(Nlog(logN))
// N = 1e6
// query O(Q)
// primeFactorization O(logX)
// overall
//   O(Nlog(logN)) + O(Q) * O(logX)
// = O(Nlog(logN) + QlogX)
// = O(Xlog(logX) + QlogX), X is the largest number (maybe equal to N)

vector<pair<ll, ll>> primeFactorization(ll x, vector<ll> &spf) {
	// O(logx)
	vector<pair<ll, ll>> ans;
	while(x != 1) {
		ll prime = spf[x];
		ll cnt = 0;
		while(x%prime == 0) {
			cnt++;
			x = x/prime;
		}
		ans.push_back({prime, cnt});
	}
	return ans;
}

int main()
{
	// precomputation
	// sieve of Eratosthenes for spf
	// O(nlog(logn))
	ll maxN = 1e6;
	vector<bool> isPrime(maxN, true);
	vector<ll> spf(maxN, 1e9);
	for (ll i = 2; i < maxN; i++) {
		if(isPrime[i]) {
			spf[i] = i;
			for (ll j = i*i; j < maxN; j+=i) {
				isPrime[j] = false;
				spf[j] = min(spf[j], i);
			}
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int X; cin >> X;
		vector<pair<ll, ll>> primeF = primeFactorization(X, spf);
		ll factors = 1;
		for(auto i:primeF) {
			factors *= (i.second + 1);
		}
		cout << factors << endl;
	}
	
	return 0;
}