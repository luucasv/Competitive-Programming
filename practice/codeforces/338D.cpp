/*
	Codeforces: 338D. GCD Table
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll gcd(ll x, ll y) {
	while(x) y %= x, swap(x,y);
	return y;
}

ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

pair<ll,ll> euclides(ll a, ll b) {
	if(!b) return pair<ll,ll>(1,0);
	if(!a) return pair<ll,ll>(0,1);
	pair<ll,ll> p = euclides(b%a,a);
	return pair<ll,ll>(p.second - p.first*(b/a), p.first);
}

ll inverse(ll x,ll mod) {
	pair<ll,ll> p = euclides(x,mod);
	return ((p.first % mod) + mod) % mod;
}

ll mul(ll a, ll b, ll m){
    ll q = (long double) a * (long double) b / (long double) m;
    ll r = a * b - q * m;

    return (r + 5 * m) % m;
}

ll chinese(ll r1, ll m1, ll r2, ll m2) {
	ll g = gcd(m1, m2);
	ll l = lcm(m1, m2);

	return (mul(r2 - r1, mul(inverse(m1, m2), m1/g, l), l) + r1) % l;
}


ll a[111111], b[111111];

int main(){
	ll n, m;	
	scanf("%lld %lld", &n, &m);
	int k;
	cin >> k;
	fr(i, 0, k)
		scanf("%lld", &b[i]);
	ll l = 1;
	fr(i, 0, k){
		ll g = gcd(l, b[i]), bn = b[i] / g;
		if(l > n / bn)
			l = 0;
		l *= bn;
	}
	if(l == 0){
		puts("NO");
		return 0;
	}
	ll md = b[0], r = 0;
	fr(i, 1, k){
		ll ri = ((-i)%b[i] + b[i])%b[i];
		ll g = gcd(b[i], md);
		if(abs(ri - r)%g != 0){
			puts("NO");
			return 0;
		}
		r = chinese(r, md, ri, b[i]);
		md = lcm(md, b[i]);
	}
	if(r == 0)
		r = md;
	ll c = r + k - 1;
	if(c > m){
		puts("NO");
		return 0;
	}
	for(ll i = r; i <= c; ++i)
		if(gcd(md, i) != b[i-r]){
			puts("NO");
			return 0;
		}
	if(l <= n && c <= m)
		puts("YES");
	else
		puts("NO");
}