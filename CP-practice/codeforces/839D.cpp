#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int ms = 2e5 + 100, mv = 1e6 + 30;

ll pot[ms], ans[mv];
int cnt[mv];

int main(){
	ios::sync_with_stdio(0);
	int n, ma = 0;
	cin >> n;
	pot[0] = 1;
	fr(i, 0, n){
		pot[i+1] = (2 * pot[i])%mod;
		
		int a;
		cin >> a;

		ma = max(ma, a);
		cnt[a]++;
	}
	ma++;
	ll res = 0;
	for(int i = ma-1; i > 1; i--){
		int s = 0;
		ll sub = 0;
		for(int j = i; j < ma; j += i){
			s += cnt[j];
			sub = (sub + ans[j])%mod;
		}
		if(s == 0)
			continue;
		ans[i] = (s * pot[s-1] - sub)%mod;
		ans[i] = (ans[i] + mod)%mod;
		res = (res + i * ans[i])%mod;
	}
	cout << res << endl;
	return 0;
}
