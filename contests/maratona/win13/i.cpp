#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

int v[111111], ma[111111], mi[111111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n){
		cin >> v[i];
	}
	ma[0] = v[0];
	fr(i, 1, n){
		ma[i] = max(ma[i-1], v[i]);
	}
	
	mi[n-1] = v[n-1];
	for(int i = n-2; i > -1; --i){
		mi[i] = min(mi[i+1], v[i]);
	}
	int ans = 0;
	fr(i, 0, n){
		if(ma[i] <= v[i] && mi[i] >= v[i])
			++ans;
	}
	cout << ans << endl;
	return 0;
}
