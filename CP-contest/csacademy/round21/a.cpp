#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " _

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int ans = n/50;
	n%=50;
	ans += n/5;
	n%=5;
	ans += n;
	cout << ans << endl;
	return 0;
}