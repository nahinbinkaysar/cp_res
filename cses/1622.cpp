#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(),x.end()
#define ll long long
#define gap ' '
#define endl '\n'
#define vi vector<int>
#define debug cout << "DEBUG: " <<

int factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

void solve()
{
	string a; cin >> a;
	int t = factorial(a.size());
	// cout << t << endl;
	set<string> s;
	for(int i=0, x=0; i<t; i++, x++) {
		next_permutation(all(a));
		// cout << i+1 << gap << a << endl;
		s.insert(a);
	}
	// cout << endl;
	// int p = 1;
	cout << s.size() << endl;
	for(auto i:s) {
		cout << i << endl;
		// cout << p << gap << i << endl;
		// p++;
	}
}

int main()
{
	solve();
	return 0;
}
