#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// efficient prime factorization using spf

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
	isPrime[0] = false; // 0 not a prime
	isPrime[1] = false; // 1 not a prime
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

	vector<pair<ll, ll>> primeF = primeFactorization(120, spf);

	for(auto i:primeF) {
		cout << i.first << " " << i.second << endl;
	}
	
	return 0;
}