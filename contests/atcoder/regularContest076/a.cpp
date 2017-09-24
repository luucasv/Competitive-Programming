#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

const ll mod = ll(1e9) + 7;

int main(){
	ios::sync_with_stdio(0);
	ll a, b;
	cin >> a >> b;
	ll ma, mb;
	ma = min(a, b), mb = max(a, b);
	if(mb - ma > 1){
		cout << 0 << endl;
		return 0;
	}
	else{
		ll ans = 1;
		fr(i, 0, ma){
			ans = (ans * (i+1))%mod;
		}
		fr(i, 0, mb){
			ans = (ans * (i+1))%mod;
		}
		if(ma == mb){
			ans = (ans*2)%mod;
		}
		cout << ans << endl;
	}
	return 0;
}