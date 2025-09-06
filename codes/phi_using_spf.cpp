#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int phi(int n) {
	int result = n;
	for (int i = 2; i*i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			result -= result/i;
		}
	}
	if(n > 1) result -= result/n;
	return result;
}

int phi(int n, vector<ll> &spf) {
	int result = n;
	while(n != 1) {
		int prime = spf[n];
		while(n % prime == 0) {
			n /= prime;
		}
		result -= result/prime;
	}
	return result;
}

int main()
{
	vector<bool> isPrime(1e6, true);
	vector<ll> spf(1e6, 1e9);
	for (ll i = 2; i < 1e6; i++) {
		if(isPrime[i]) {
			spf[i] = i;
			for (ll j = i*i; j < 1e6; j+=i) {
				isPrime[j] = false;
				spf[j] = min(spf[j], i);
			}
		}
	}

	int n; cin >> n;
	cout << phi(n) << endl; // O(n sqrt(n))
	cout << phi(n, spf) << endl; // O(nlogn)
	return 0;
}