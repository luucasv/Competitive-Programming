#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;

int v[111111];
vector<int> vt;

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	fr(i, 0, n){
		cin >> v[i];
		if(v[i])
			vt.push_back(i);
	}
	int ans = 0;
	fr(i, 0, n){
		if(v[i])
			continue;
		auto st = lower_bound(vt.begin(), vt.end(), i-k), ed = upper_bound(vt.begin(), vt.end(), i+k);
		// dbg(*st _ *ed)
		if(ed - st <= 1)
			++ans;
	}
	cout << ans << endl;
}