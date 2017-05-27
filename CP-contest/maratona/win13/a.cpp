#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

const int ms = 511, mt = 10*ms, inf = 0x3f3f3f3f;

int memo[ms][mt], used[ms][mt];
bool mk[ms];

int v[ms], ans[ms];
int t, n;

int dp(int at, int sum){
	if(sum > t)
		return -inf;
	if(at == n)
		return 0;
	if(memo[at][sum] != -1)
		return memo[at][sum];
	int a1 = dp(at+1, sum), a2 = v[at] + dp(at+1, sum + v[at]);
	if(a2 > a1){
		used[at][sum] = 1;
		a1 = a2;
	}
	return memo[at][sum] = a1;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memo, -1, sizeof memo);
	
	cin >> t >> n;
	fr(i, 0, n)
		cin >> v[i];
	dbg(dp(0, 0));
	int sum = 0, sum2 = 0;
	fr(i, 0, n){
		if(used[i][sum]){
			ans[i] = sum;
			sum += v[i];
		}
		else{
			ans[i] = sum2;
			sum2 += v[i];
		}
	}
	cout << ans[0];
	fr(i, 1, n)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
