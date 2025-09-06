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
		// O(logp) for binary exponentiation only once
		// O(n) + O(logp) = O(n)
		ll n = 10;
		vector<ll> fact(n + 1);
		vector<ll> ifact(n + 1);

		fact[0] = 1;

		for (ll i = 1; i <= n; i++) {
			fact[i] = (fact[i-1] * i) % p;
		}

		ifact[n] = binpow(fact[n], p-2, p);

		for (ll i = n-1; i >= 0; i--) {
			ifact[i] = ( ifact[i+1] % p * (i+1) ) % p; 
		}

		cout << nCr(8, 6, fact, ifact) << endl;

		return 0;
	}