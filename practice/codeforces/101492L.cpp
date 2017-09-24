#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int ms = 101, sigma = 26, mt = 1000001;

char dp[mt][ms];
int n, m;
string p, t;

int main(){
	int k;
	cin >> m >> n >> k;
	cin >> p >> t;
	char res = 50;
	memset(dp, 0x3f, sizeof dp);
	fr(i, 0, n){
		dp[i][0] = 0;
		fr(j, 0, m){
			if(t[i] == p[j]){
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			}
			dp[i+1][j] = min(dp[i+1][j], char(dp[i][j] + 1));
			dp[i+1][j+1] = min(dp[i+1][j+1], char(dp[i][j] + 1));
			dp[i][j+1] = min(dp[i][j+1], char(dp[i][j] + 1));
		}
		res = min(res, dp[i][m]);
	}
	res = min(res, dp[n][m]);
	cout << (res > k ? "N" : "S") << endl;
	return 0;
}