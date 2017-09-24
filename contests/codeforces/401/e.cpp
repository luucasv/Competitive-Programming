#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ii, ll> iii;
const int ms = 2111111;
ll BIT[ms];
iii v[ms];

void setv(int i, ll v){
	while(i < ms){
		BIT[i] = max(BIT[i], v);
		i += i&-i;
	}
}

ll getv(int i){
	ll ans = 0;
	while(i > 0){
		ans = max(ans, BIT[i]);
		i -= i&-i;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	map<int, int> mp;
	int n;
	cin >> n;
	fr(i, 0, n){
		cin >> v[i].X.Y >> v[i].X.X >> v[i].Y;
		mp[v[i].X.Y];
		mp[v[i].X.X];
	}

	int at = 0;
	for(auto &it : mp){
		it.Y = ++at;
	}

	fr(i, 0, n){
		v[i].X.Y = mp[v[i].X.Y];
		v[i].X.X = mp[v[i].X.X];
	}

	sort(v, v+n, greater<iii>());
	ll ans = 0;
	fr(i, 0, n){
		ll at = v[i].Y + getv(v[i].X.X - 1);
		setv(v[i].X.Y, at);
		ans = max(ans, at);
	}
	cout << ans << endl;
	return 0;
}