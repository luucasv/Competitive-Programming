#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll mod = ll(1e9) + 9;
const int ms = 511;


ll dp[3][ms][ms];
ii v[2*ms];

int cnt[2*ms];

int n, k;
/*
ll memo[2*ms][ms][ms];
ll dp(int i, int d, int vi){
	if(i == n && (i - d - vi - vi - d) > 0)
		return 0;
		
	if(i == n && vi - d == k)
		return 1;
	
	if(i == n)
		return 0;
	
	if(memo[i][d][vi] != -1)
		return memo[i][d][vi];
		
	ll ans = dp(i + 1, d,  vi);
	
	//dbg(a _ b  _ cnt[i] - vi _ i - cnt[i] - d)
			
	if(v[i].Y == 1 && (i - cnt[i] - d - vi) > 0){
		ans = (ans + (i - cnt[i] - d - vi)* dp(i+1, d, vi+1) )%mod;
	}
	if(v[i].Y == 2 && (cnt[i] - vi - d) > 0){
		ans = (ans + (cnt[i] - vi - d) * dp(i+1, d+1, vi))%mod;
	}
	return memo[i][d][vi] = ans;
}
/**/
int main(){

		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);


	ios::sync_with_stdio(0);
	//memset(memo, -1, sizeof memo);
	cin >> n >> k;
	fr(i, 0, n){
		cin >> v[i].X;
		v[i].Y = 1;
	}
	fr(i, 0, n){
		cin >> v[n+i].X;
		v[n+i].Y = 2;
	}
	
	n <<= 1;
	
	sort(v, v+n);
	fr(i, 0, n)
		cnt[i+1] = (v[i].Y == 1);
	fr(i, 1, n)
		cnt[i] += cnt[i-1];
	

	fr(d, 0, n/2 + 1){
		fr(vi, 0, n/2 + 1){
			if((n - d - vi - vi - d) > 0)
				dp[n&1][d][vi] = 0;				
			else if(vi - d == k)
				dp[n&1][d][vi] = 1;
			else 
				dp[n&1][d][vi] = 0;
		}
	}

	for(int i = n - 1; i > -1; --i){
		fr(d, 0, n/2 + 1){
			fr(vi, 0, n/2 + 1){
				ll ans = dp[(1+i)&1][d][vi];
				if(v[i].Y == 1 && (i - cnt[i] - d - vi) > 0){
					ans = (ans + (i - cnt[i] - d - vi)* dp[(i+1)&1][d][vi+1])%mod;
				}
				if(v[i].Y == 2 && (cnt[i] - vi - d) > 0){
					ans = (ans + (cnt[i] - vi - d) * dp[(i+1)&1][d+1][vi])%mod;
				}
				dp[i&1][d][vi] = ans;
			}
		}
	}
	
	cout << dp[0][0][0] << endl;
	return 0;
}