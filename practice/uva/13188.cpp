#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int inf = 0x3f3f3f3f, ms = 1111111;

const ll mod = ll(1e9) + 7;

/*
	soma(linha a, de b até c) = sum de (b <= k <= c) de ((a * (a - 1)) / 2 + k)
	(c - b + 1) * (a² - a + b + c) / 2

	resposta a partir da linha i até n é:
	sum de (i <= k <= n) de (soma(k, k - i + 1, k))


	i * (k² - k + 2k - i + 1) / 2
	i * (k² + k - i + 1) / 2

	ik² + k*i - i² + i / 2
	(k*i + k²*i + k⁰(-i² + i)) / 2
	resposta(i, n) = sum de (i <= k <= n) de ((k*i + k²*i + k⁰(-i² + i)) / 2)
	sum(k) * i + sum(k²)*i + sum(1)*(-i² + i) / 2
*/


ll fastExp(ll a, ll b){
	a %= mod;
	ll r = 1;
	for(; b; b >>= 1, a = (a*a)%mod){
		if(b&1){
			r = (r*a)%mod;
		}
	}
	return r;
}

ll sum1(ll l, ll r){
	return (r - l + 1)%mod;
}

ll sumk(ll i){
	return ((fastExp(i, 2) + i)%mod * fastExp(2, mod - 2))%mod;	
}

ll sumk(ll l, ll r){
	return (sumk(r) - sumk(l - 1) + mod) % mod;
}

ll sumk2(ll i){
	return ((2*fastExp(i, 3) + 3*fastExp(i, 2) + i)%mod * fastExp(6, mod - 2))%mod;	
}

ll sumk2(ll l, ll r){
	return (sumk2(r) - sumk2(l - 1) + mod) % mod;
}

ll solve(ll i, ll n){
	ll mi = i%mod;
	return ((sumk(i, n) * mi)%mod + (sumk2(i, n)*mi)%mod + (sum1(i, n)*(-fastExp(i, 2) + mi + mod))%mod)*fastExp(2, mod - 2) % mod;
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll h = n/2 + 1;
		cout << "Case #" << cas++ << ": " << solve(h, n) << endl;

	}
	return 0;
}