#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

const ll mod = ll(1e9) + 7;
ll memo[32];

int sz, n;

string st, nm[1111];
ll v[1111];

ll dp(int at){
	if(at == st.size())
		return 1;
	if(memo[at] != -1)
		return memo[at];
	ll ans = 0;
	bool ok;
	fr(i, 0, n){
		ok = 1;
		fr(j, 0, nm[i].size()){
			if(at + j == st.size() || st[at+j] != nm[i][j]){
				ok = 0;
				break;
			}
		}
		if(ok){
			ans = (ans + v[i] * dp(at + nm[i].size()))%mod;
		}
	}
	return memo[at] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memo, -1, sizeof memo);
	cin >> n >> st;
	fr(i, 0, n)
		cin >> nm[i] >> v[i];
	cout << dp(0) << endl;
	return 0;
}
