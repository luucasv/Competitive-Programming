#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;
const int inf = int(1e7);

string s;
int nx[111111], memo[111111];
int ls[500];

int dp(int i){
	if(i == -1)
		return inf;
	if(i+1 == s.size())
		return 0;
	if(memo[i] != -1)
		return memo[i];
	return memo[i] = min(abs(s[i] - s[i+1]) + dp(i+1), dp(nx[i]));
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		memset(memo, -1, sizeof memo);
		memset(ls, -1, sizeof ls);
		cin >> s;
		for(int i = int(s.size()) - 1; i > -1; i--){
			nx[i] = ls[s[i]];
			ls[s[i]] = i;
		}
		cout << dp(0) << endl;
	}
	return 0;
} 