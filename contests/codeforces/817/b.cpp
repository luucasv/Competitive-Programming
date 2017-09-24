#include <bits/stdc++.h>
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 
#define fr(a, b, c) for(int (a) = (b), __ = c; a < __; ++a)

using namespace std;
typedef long long ll;
const int ms = int(1e5) + 20, full = (1 << 3) - 1;
ll memo[ms][1 << 3];
int ma[4], v[ms];
int n;

ll dp(int at, int mask){
	if(mask == full)
		return 1;
	if(at == n)
		return 0;
	if(memo[at][mask] != -1)
		return memo[at][mask];
	ll ans = dp(at+1, mask);
	fr(i, 0, 3){
		if(ma[i] == v[at] && !((mask >> i)&1)){
			ans += dp(at+1, mask | (1 << i));
			break;
		}
	}
	return memo[at][mask] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memo, -1, sizeof memo);
	cin >> n;
	fr(i, 0, n){
		cin >> v[i];
	}
	int m[4] = {v[0], v[1], v[2]};
	sort(m, m+3);
	fr(i, 3, n){
		m[3] = v[i];
		sort(m, m + 4);
	}
	fr(i, 0, 3)
		ma[i] = m[i];
	cout << dp(0, 0) << endl;
	return 0;
}