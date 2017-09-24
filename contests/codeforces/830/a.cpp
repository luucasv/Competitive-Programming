#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 1111;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;

long long int v[ms], c[2*ms];
long long int memo[ms][2*ms];
int n, k, p;

long long int calc(int i, int j){
	return llabs(v[i] - c[j]) + llabs(c[j] - p);
}

long long int dp(int i, int j){
	if(i == n)
		return 0;
	if(j == k)
		return inf;
	if(memo[i][j] != -1)
		return memo[i][j];
	return memo[i][j] = min(max(calc(i, j), dp(i+1, j+1)), dp(i, j+1));
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k >> p;
	fr(i, 0, n)
		cin >> v[i];
	fr(i, 0, k)
		cin >> c[i];
	sort(v, v+n);
	sort(c, c+k);
	memset(memo, -1, sizeof memo);
	cout << dp(0, 0) << endl;
	return 0;
}