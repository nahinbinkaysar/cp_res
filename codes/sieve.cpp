#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// find all prime numbers from 1 to n 

int main()
{
	// precomputation
	// sieve of Eratosthenes
	// O(nlog(logn))
	ll n; cin >> n;
	vector<bool> isPrime(n+1, true);
	isPrime[0] = false; // 0 not a prime
	isPrime[1] = false; // 1 not a prime
	for (ll i = 2; i <= n; i++) {
		if(isPrime[i]) {
			for (ll j = i*i; j <= n; j+=i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 0, cnt = 1; i <= n; i++) {
		if(isPrime[i]) cout << cnt++ << " " << i << endl;
	}
	
	return 0;
}