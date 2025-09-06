#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int tree[2 * N];

void build() {
	for (int i = n - 1; i > 0; i--) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}
}

int query(int a, int b) {
	a+=n; b+=n;
	int s = 0;
	while(a <= b) {
		if(a%2 == 1) s+=tree[a++];
		if(b%2 == 0) s+=tree[b--];
		a /= 2; b /= 2;
	}
	return s;
}

void modify(int k, int x) {
	k += n;
	tree[k] = x;
	// tree[k] += x;
	for(k /= 2; k >= 1; k /= 2) {
		tree[k] = tree[2*k] + tree[2*k+1];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", tree + n + i);
		build();
	for(int i=0; i<16; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	modify(3, 1);
	for(int i=0; i<16; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	printf("%d\n", query(0, 1));
	return 0;
}