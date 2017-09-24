/*
	Codeforces: 319C. Kalila and Dimna in the Logging Industry
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ll p, n, x;
	cin >> p >> n >> x;
	--x;
	ll c = x / p;
	cout << min(c + x - c * p, c + 1 + min((c + 1) * p, n-1) - x) + 1 << endl;
	return 0;
}