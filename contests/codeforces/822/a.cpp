#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	int f = min(a, b);
	ll ans = 1;
	fr(i, 0, f)
		ans *= (i+1);
	cout << ans << endl;
	return 0;
}