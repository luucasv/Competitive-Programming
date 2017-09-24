#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = 111, mt = 25111;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

struct roller{
	int a, b, t;
};

ll memon[ms][mt], memoz[mt];

vector<roller> zeros, normal;

ll calc(roller a, ll k){
	k--;
	return a.a - k*k*a.b;
}


ll dpn(int at, ll t){
	if(t < 0)
		return -inf;
	if(t == 0 || at == normal.size())
		return 0;
	if(memon[at][t] != -1)
	 	return memon[at][t];
	
	ll ans = dpn(at+1, t), sum = 0;
	for(ll k = 1; calc(normal[at], k) > 0 && k*normal[at].t <= t; ++k){
		sum += calc(normal[at], k);
		ans = max(ans, sum + dpn(at+1, t - k*normal[at].t));
	}
	return memon[at][t] = ans;	 
}

ll dpz(ll t){
	if(t < 0)
		return -inf;
	if(memoz[t] != -1)
	 	return memoz[t];
	 ll ans = 0;
	 fr(i, 0, zeros.size())
	 	ans = max(ans, zeros[i].a + dpz(t - zeros[i].t));
	 return memoz[t] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memon, -1, sizeof memon);
	memset(memoz, -1, sizeof memoz);
	int n;
	cin >> n;
	fr(i, 0, n){
		roller a;
		cin >> a.a >> a.b >> a.t;
		if(a.b == 0)
			zeros.push_back(a);
		else
			normal.push_back(a);
	}
	int q;
	cin >> q;
	fr(i, 0, q){
		int t;
		cin >> t;
		ll ans = 0;
		fr(i, 0, t+1){
			ans = max(ans, dpn(0, i) + dpz(t - i));
		}
		cout << ans << endl;
	}
	return 0;
}
