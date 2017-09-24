
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, k;
int ma[2];
int dp[2][201][2][26 * 201];


int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	memset(dp, ~(0x3f), sizeof dp);
	dp[1][0][0][0] = 0;
	dp[1][0][1][0] = 0;
	dp[0][0][0][0] = 0;
	dp[0][0][1][0] = 0;
	fr(i, 0, n){
		ll a;
		cin >> a;
		int has[2] = {0, 0};
		while(a % 2 == 0){
			has[0]++;
			a /= 2;
		}
		while(a % 5 == 0){
			has[1]++;
			a /= 5;
		}
		// dbg(has[0] _ has[1])
		int o = min(has[0], has[1]);
		has[1] -= o;
		has[0] -= o;
		ma[0] += has[0];
		ma[1] += has[1];
		for(int c = min(k,i+1); c > 0; c--){
			fr(op, 0, 2){
				ma[op] = min(ma[op], 26 * 201 - 1);
				fr(q, 0, ma[op]+1){
					dp[i%2][c][op][q] = dp[1 - i%2][c][op][q];
					dp[i%2][c][op][q] = max(dp[i%2][c][op][q], dp[1 - i%2][c-1][op][q]);
					if(q - has[op] >= 0){
						dp[i%2][c][op][q] = max(dp[i%2][c][op][q], o + dp[1 - i%2][c-1][op][q - has[op]]);
					}
					if(has[op] - q >= 0){
						dp[i%2][c][op][q] = max(dp[i%2][c][op][q], o + has[op] - q + dp[1 - i%2][c-1][1 - op][has[op] - q]);
					}
					dp[i%2][c][op][q] = max(dp[i%2][c][op][q], o + has[1 - op] + dp[1 - i%2][c-1][op][q + has[1 - op]]);
					// dbg(i _ c _ op _ q _ dp[c][op][q])
				}
			}
		}
	}
	int ans = 0;
	fr(l, 0, 2){
		fr(i, 0, max(ma[l], ma[1-l])+1){
			ans = max(ans, max(dp[1][k][l][i], dp[0][k][l][i]));
		}
	}
	cout << ans << endl;
}