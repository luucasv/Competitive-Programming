#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

ll calc(ll a, ll b){
	return (a + 1) * ((b*(b+1)) / 2) + (b + 1) * ((a*(a+1)) / 2);
}

int main(){
	ios::sync_with_stdio(0);
	int m, b;
	cin >> m >> b;
	ll x = 0, y = b*m;
	ll ans = calc(x, y);
	while(ans < calc(x+1, y - m)){
		x += 1;
		y -= m;
		ans = calc(x, y);
	}
	dbg(x _ y _ ans)
	cout << ans << endl;
	return 0;
}