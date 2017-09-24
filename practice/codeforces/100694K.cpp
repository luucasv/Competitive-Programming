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

const ld EPS = 1e-10;

int main(){
	// ios::sync_with_stdio(0);
	int lsa, lsb, aa, bb;
	int n;
	scanf("%d", &n);
	scanf("%d %d", &aa, &bb);
	lsa = max(aa, bb);
	lsb = min(aa, bb);
	int ans = 1;
	ld lo = 0, up = 1;
	fr(i, 1, n) {
		int ata, atb;
		scanf("%d %d", &aa, &bb);
		ata = max(aa, bb);
		atb = min(aa, bb);
		int d1 = lsa - lsb, d2 = ata - atb, d = d2 - d1;
		if (d == 0) {
			if(lsa < ata && lsb < atb)
				ans = 0;
		} else if (d > 0) {
			// cout << "up " << (lsb - atb) / ld(d) << endl;
			up = min(up, (lsb - atb) / ld(d));
		} else {
			// cout << "lo " << (lsb - atb) / ld(d) << endl;
			lo = max(lo, (lsb - atb) / ld(d));
		}
		lsa = ata;
		lsb = atb;
	}
	if (ans && (fabs(lo - up) < EPS || lo < up)) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}