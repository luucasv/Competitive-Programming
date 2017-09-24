#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;


ll a[111111];
int n,k;

bool can(ll v){
	ll sv = v;
	ll ans = 0;
	ll ls = 0, carry = 0;
	ll has = 0;
	fr(i, 0, n){
		int sz = n - i;
		ll q = min((a[i] - ls), v / sz);
		if(ls&1)
			q = q - q%2;
		else
			q = q - 1 + q%2;
		q = max(q, 0LL);
		ls  += q;
		ans += ((q + carry) / 2)*sz;
		v -= q*sz;
		carry = (carry + q)%2;
		if(a[i]%2 == 0){
			++has;
		}
		// dbg('d' _ ans _ q)
	}
	has = min(has, v);
	ans += has;
	// dbg(sv _ ans)
	return ans >= k;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	fr(i, 0, n){
		cin >> a[i];
	}
	sort(a, a+n);
	ll lo = 0, hi = n * a[n-1];
	while(hi - lo > 1){
		ll m = (lo + hi) / 2;
		if(can(m))
			hi = m;
		else
			lo = m;
	}
	if(!can(lo))
		lo = hi;
	if(!can(lo))
		lo = -1;
	cout << lo << endl;
}