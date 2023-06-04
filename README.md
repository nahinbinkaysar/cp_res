# Today I learnt

## Mod the answer




    int res = 1;
	int mod = 1e7+13;
	for(int i = 1; i <= 13; i++) {
		res = res * i;
	}
	cout << res % mod << endl; //wrong ans, int out of bound

Good solution

    int res = 1;
	int mod = 1e7+13;
	for(int i = 1; i <= 13; i++) {
		res = res * i % mod;
	}
	cout << res << endl; // 7012714