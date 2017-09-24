/*
	Codeforces: 319C. Kalila and Dimna in the Logging Industry
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int calc(int d, int k, int l) {
	int x = (d + 2) >> 1, y = (d + 1) >> 1;
	return x * k + y * l - 1;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int lo = 0, hi = 1;
		while (calc(hi, l, r) < n) {
			lo = hi;
			hi <<= 1;
		}
		while (hi - lo > 0) {
			int m = (lo + hi) / 2;
			if (calc(m, l, r) < n) {
				lo = m + 1;
			} else {
				hi = m;
			}
		}
		printf("%d%c", lo, q == 0 ? '\n' : ' ');
	}
	return 0;
}