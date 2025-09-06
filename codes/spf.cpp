#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// smallest prime factor

int main()
{
	// precomputation
	// sieve of Eratosthenes
	// O(nlog(logn))
	ll n; cin >> n;
	vector<bool> isPrime(n+1, true);
	isPrime[0] = false; // 0 not a prime
	isPrime[1] = false; // 1 not a prime
	vector<ll> spf(n+1);
	for (ll i = 0; i < n+1; i++) {
		spf[i] = i;
	}
	for (ll i = 2; i <= n; i++) {
		if(isPrime[i]) {
			for (ll j = i*i; j <= n; j+=i) {
				isPrime[j] = false;
				spf[j] = min(spf[j], i);
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		cout << i << " " << spf[i] << endl;
	}
	
	return 0;
}