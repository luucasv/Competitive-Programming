#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
const int ms = 1 << 20, mv = 44;

int memo[ms];
ll adj[mv];
int sz, n;

bool isClique(ll mask){
	fr(i, 0, n){
		if((mask >> i)&1){
			if((adj[i] | mask) != (adj[i] | (1LL << i)))
				return false;
		}
	}
	return true;
}

int dp(int mask){
	int &ans = memo[mask];
	if(ans != -1)
		return ans;
	if(mask == 0)
		return ans = 0;
	if(isClique(mask))
		return ans = __builtin_popcount(mask);
	ans = 0;
	fr(i, 0, sz){
		if((mask >> i)&1){
			ans = max(ans, dp(mask & (~(1 << i))));
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memo, -1, sizeof memo);
	int k;
	cin >> n >> k;
	sz = n/2;
	int rt = n - sz;
	fr(i, 0, n){
		fr(j, 0, n){
			int a;
			cin >> a;
			adj[i] |= (ll(a) << j);
		}
	}
	int m = dp(((1LL << sz) - 1));
	fr(i, 1, 1 << rt){
		ll mask = ll(i) << sz;
		if(isClique(mask)){
			ll ad = ((1LL << sz) - 1);
			fr(k, sz, n){
				if((mask >> k)&1){
					ad &= adj[k];
				}
			}
			m = max(m, __builtin_popcount(i) + dp(ad));
		}
	}
	cout << fixed << setprecision(13) << ((m-1) * k * k) / (2.0 * m) << endl;
	return 0;
}
