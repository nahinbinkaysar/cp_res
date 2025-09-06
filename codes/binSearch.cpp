#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(),x.end()
#define ll long long
#define gap ' '
#define endl '\n'
#define vi vector<int>
#define debug cout << "DEBUG: " << 

void solve()
{
	int n; cin >> n;
	vi a(n); for(auto &i:a) cin >> i;
	sort(all(a));
	int k; cin >> k;
	while(k--) {
		int x; cin >> x;
		int y; cin >> y;
		
		int L, R;

		// closest to the right
		int l = -1;
		int r = n;
		while(l + 1 < r) {
			int m = (l + r) / 2;
			if(a[m] < x) l = m;
			else r = m;
		}
		L = r + 1;

		// closest to the left
		l = -1;
		r = n;
		while(l + 1 < r) {
			int m = (l + r) / 2;
			if(a[m] <= y) l = m;
			else r = m;
		}
		R = l + 1;

		cout << R << gap << L<< endl;
		cout << R - L + 1 << gap;
	}
	cout << endl;
}

int main()
{
	// fast_cin();
	solve();
	return 0;
}