#include <iostream>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;

ll p = 1000000007;

ll binpow(ll a, ll b, ll m) {
	ll res = 1;
	while(b > 0) {
		if(b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

ll nCr(ll n, ll r, vector<ll> &fact, vector<ll> &ifact) {
	if (r > n) return 0;
	return (fact[n] * ifact[r] % p * ifact[n - r] % p) % p;
}


int main()
{
	// Given q queries (1 <= q <= 1e5) find out 
	// nCr such that [1 <= n <= 1e6] [0 <= r <= n]
	// under mod 1e9+7

	// precomputation
	// O(n) for loop
	// O(logp) for binary exponentiation
	// O(nlogp)
	vector<ll> fact(1e6+1);
	vector<ll> ifact(1e6+1);

	fact[0] = 1, ifact[0] = 1;

	for (ll i = 1; i <= 1e6; i++) {
		fact[i] = (fact[i-1] * i) % p;
		ifact[i] = binpow(fact[i], p-2, p);
	}


	ll n = 10, r = 5;
    cout << nCr(n, r, fact, ifact) << endl;

	return 0;
}