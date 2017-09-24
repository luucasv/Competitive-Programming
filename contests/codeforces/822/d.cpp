#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<
#define md(x) (((x) >= mod) ? (x)%mod : (x))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = int(5e6) + 2;
const ll inf = ll(2e18) + 200, mod = ll(1e9) + 7;

ll f[ms];

int main(){
	ios::sync_with_stdio(0);
	memset(f, 0x3f, sizeof f);
	f[1] = 0;
	fr(i, 2, ms){
		f[i] = min(f[i], (ll(i) * ll(i-1))/2);
		for(int j = i+i, q = 2; j < ms; j += i,++q){
			f[j] = min(f[j], f[i] + i*(ll(q) * (ll(q) - 1))/2);
		}
	}

	int t, l, r;
	cin >> t >> l >> r;
	ll ans = 0;
	ll p = 1;
	fr(i, l, r+1){
		ans = md(ans + p*md(f[i]));
		p = md(p*t);
	}
	cout << ans << endl;
	return 0;
}