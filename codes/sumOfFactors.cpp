#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

// sum of factors of a number

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

	ll N; cin >> N;
	vector<pair<ll, ll>> primeF = primeFactorization(N, spf);
	ll sum = 1;
	for (auto i:primeF) {
		ll p = i.first;
		ll k = i.second;
		// cout << p << " " << k << endl;
		ll sn = (pow(p, k+1) - 1) / (p - 1);
		sum *= sn;
	}
	cout << sum << endl;
	
	return 0;
}
