#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;

const int ms = int(1e6) + 100;

int a[ms], b[ms];
int ls[ms], ans[ms], fs[ms];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> b[i];
	fr(i, 0, n){
		if(ls[b[i]] == 0){
			fs[b[i]] = i - ls[b[i]];
		}
		ans[b[i]] = max(i - ls[b[i]], ans[b[i]]);
		ls[b[i]] = i+1;
	}
	int mi = 0x3f3f3f3f;
	fr(i, 0, int(1e5)+1){
		ans[i] = max(fs[i] + n - ls[i], ans[i]);
		mi = min(ans[i], mi);
	}
	cout << n + mi << endl;
	return 0;
}