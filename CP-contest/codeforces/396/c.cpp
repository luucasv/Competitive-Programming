#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll mod = ll(1e9) + 7;
const int ms = 1111, inf  = 11111;

ll memo1[ms][ms];
ll memo2[ms][ms];
int n;
string str;
int v[30];
int ma;
int acc[30][ms];

int count(int st, int ed){
	int ans = ms;
 	fr(val, 0, 26)
 		if(acc[val][ed] - (st ? acc[val][st-1] : 0))
 			ans = min(ans, v[val]);
 	return ans;
}

ll dp(int ls, int at){
	if(at - ls > count(ls, at-1))
		return 0;
	ma = max(ma, at - ls);
	if(at == n)
		return 1;

	ll &ans = memo1[ls][at];
	if(~ans) return ans;
	ans = dp(ls, at+1);
	ans = (ans + dp(at, at+1))%mod;
	return ans;
}

ll dp2(int ls, int at){
	if(at - ls > count(ls, at-1))
		return inf;
	ma = max(ma, at - ls);
	if(at == n)
		return 1;

	ll &ans = memo2[ls][at];
	if(~ans) return ans;
	ans = dp2(ls, at+1);
	ans = min(ans , dp2(at, at+1) + 1);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> str;
	fr(i, 0, n){
		str[i] -= 'a';
		acc[str[i]][i] = 1;
	}

	fr(i, 0, 26){
		fr(j, 1, n){
			acc[i][j] += acc[i][j-1];
		}
	}

	fr(i, 0, 26)
		cin >> v[i];


	ma = 1;

	memset(memo1, -1, sizeof memo1);
	memset(memo2, -1, sizeof memo2);
	cout << dp(0, 1) << endl;
	cout << ma << endl;
	cout << dp2(0, 1) << endl;

	return 0;
}