#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const ll mod = ll(1e9) + 9LL;
const int mv = 5111, me = 2*mv;

int ant[me], to[me], w[me], adj[mv], z;
int vis[mv], step;
ll fat[mv], sum[mv][mv], comb[mv][mv];

inline void add(int a, int b, int c){
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++; 
	swap(a, b);
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
}

ll dfs(int u, ll dist, int level){
	vis[u] = step;

	ll ret = (sum[level][level]*dist)%mod;
	fre(i, u){
		if(vis[to[i]] != step)
			ret = (ret + dfs(to[i], (dist + w[i])%mod, level+1))%mod;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n;
	cin >> n;

	fr(i, 1, n){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		add(a, b, c);
	}

	fat[0] = 1;
	comb[0][0] = 1;
	fr(i, 1, n+5){
		fat[i] = (ll(i)*fat[i-1])%mod;
		comb[i][0] = 1, comb[i][i] = 1;
		fr(j, 1, i){
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
		}
	}
	
	fr(i, 0, n){
		ll s = (fat[i]*fat[n-i-1])%mod;
		fr(j, 0, n){
			sum[i][j] = (s*comb[n-j-1][n-i-1])%mod;
		}
	}

	for(int i = n-2; i > -1; --i){
		fr(j, 0, n)
			sum[i][j] = (sum[i+1][j] + sum[i][j])%mod;
	}

	ll ans = 0;
	fr(u, 0, n){
		++step;
		ans = (ans + dfs(u, 0, 0))%mod;		
	}
	cout << ans << endl;
	return 0;
}