#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(),x.end()
#define ll long long
#define gap ' '
#define endl '\n'
#define vi vector<int>
#define debug cout << "DEBUG: " << 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int generateRandomNumber(int l, int r) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(l, r);
	return dis(gen);
}

int main()
{
	double long money = 0;
	double long tries = 100000;
	double long win = 1000;
	double long lose = 0;
	for (int i = 0; i <= tries; i++) {
		int x = generateRandomNumber(0, 1);
		if(x == 1) money += win;
		else money += lose;
	}
	// cout << setprecision(10) << fixed; // set precision to 10 decimal places
	// now we will explain what does adding << fixed do
	// if we don't add fixed then the precision will be set to 10 decimal places
	// but the number will be in scientific notation
	// if we add fixed then the number will be in decimal notation
	// for example:
	cout << setprecision(10) << 1e-10 << endl;
	// output: 0.0000000001
	cout << setprecision(10) << fixed << 1e-10 << endl;
	// output: 0.0000000001
	// cout << "Average: " << money/tries << endl;
	return 0;
}