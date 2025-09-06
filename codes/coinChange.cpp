#include <iostream>
#include <vector>
using namespace std;
#define INF 1e8

vector<int> coins = {1, 3, 4};

int solve(int x) {
	if(x < 0) return INF;
	if(x == 0) return 0;
	int best = INF;
	for(auto c:coins) {
		best = min(best, solve(x-c)+1);
	}
	return best;
}

int main()
{
	int x; cin >> x;
	cout << solve(x) << endl;
	return 0;
}