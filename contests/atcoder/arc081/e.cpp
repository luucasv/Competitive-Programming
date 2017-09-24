#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int ls[50];
int dp[211111], to[211111];
char go[211111];
int main(){
	ios::sync_with_stdio(0);
	string a;
	cin >> a;
	int n = a.size();
	fr(i, 0, 26){
		ls[i] = n+1;
	}
	dp[n] = 1;
	to[n] = n+1;
	go[n] = 'a';
	for(int i = n-1; i > -1; i--){
		dp[i] = n+200;
		ls[a[i] - 'a'] = i;
		fr(c, 0, 26){
			if(dp[ls[c]+1] + 1 < dp[i]){
				go[i] = 'a' + c;
				to[i] = ls[c]+1;
				dp[i] = dp[ls[c]+1] + 1;
			}
		}
	}
	int i = 0;
	while(i <= n){
		cout << go[i];
		i = to[i];
	}
	cout << endl;
	return 0;
}