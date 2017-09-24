#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;
const ll mod = ll(1e9) + 7;

int n;
string s[2];
ll memo[60][60][8][8];

ll dp(int i, int j, int mi, int mj){
	if(i == j && i == n)
		return 1;
	ll &ans = memo[i][j][mi][mj];
	if(ans != -1)
		return ans;
	ans = 0;
	if(i == j && s[0][i] == s[1][j]){
		fr(k, 0, 3){
			if(!((mi >> k)&1) && !((mj >> k)&1)){
				ans += dp(i+1, j+1, 1 << k, 1 << k);
				ans %= mod;
			}
		}
	}
	else if(i == j){
		fr(k, 0, 3){
			if(!((mi >> k)&1)){
				ans += dp(i+2, j, 1 << k, mj | (1 << k));
				ans %= mod;
			}
		}
	}
	else{
		fr(k, 0, 3){
			if(!((mj >> k)&1)){
				ans += dp(i, j+2, mi, (1 << k));
				ans %= mod;
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> s[0] >> s[1];
	memset(memo, -1, sizeof memo);
	cout << dp(0, 0, 0, 0) << endl;
	return 0;
}