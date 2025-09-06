#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

// O(logN)

ll binpow_recursive(ll a, ll b) {
	if(b == 0) return 1;
	ll res = binpow_recursive(a, b/2);
	if(b % 2) 
		return res * res * a;
	else 
		return res * res;
}

ll binpow_iterative(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b & 1)
			res = res * a;
		a = a*a;
		b >>= 1;
	}
	return res;
}

// ll binpow(ll a, ll b, ll m) {
// 	ll res = 1;
// 	while(b > 0) {
// 		if(b & 1)
// 			res = res * a % m;
// 		a = a * a % m;
// 		b >>= 1;
// 	}
// 	return res;
// }

int main()
{
	ll a, b; cin >> a >> b;
	cout << binpow_recursive(a, b) << endl;
	cout << binpow_iterative(a, b) << endl;
	return 0;
}