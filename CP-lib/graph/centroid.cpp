#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(0) cerr << ">>> " << x << endl;
#define _ << " , " <<
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])

using namespace std;
typedef long long ll;

const int mv = int(2e5)+ 100, me = 2*mv;
int ant[me], to[me], adj[mv], prox[me], z;
inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z;
	prox[ant[z]] = z, prox[z] = -1; ++z;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z;
	prox[ant[z]] = z, prox[z] = -1; ++z;
}

inline void del(int i){
	if(prox[i] == -1)
		adj[to[i^1]] = ant[i];
	else
		ant[prox[i]] = ant[i];
	if(ant[i] != -1)
		prox[ant[i]] = prox[i];
}

int size[mv];
int max_down[mv], go[mv];
ll cnt[mv][10], size2[mv];

int n, k;

void dfs(int u, int p){
	size[u] = 1;
	max_down[u] = 0;
	go[u] = u;
	fre(i, u){
		int v = to[i];
		if(v == p)
			continue;
		dfs(v, u);
		size[u] += size[v];
		if(size[v] > max_down[u]){
			max_down[u] = size[v];
			go[u] = v;
		}
	}
}

int get_centroid(int u){
	dfs(u, u);
	int sz = size[u]/2;
	while(max_down[u] > sz)
		u = go[u];
	return u;
}

ll calc(int u, int p, int n, int d = 1){
	ll ans = 0;
	fre(i, u){
		if(to[i] == p) continue;
		ans += calc(to[i], u, n, d+1);
	}
	int a = (k - d%k)%k;
	ans += size2[n]*((d+k-1)/k) + cnt[n][a];
	return ans;
}

void ins(int u, int p, int n, int d = 1){
	fre(i, u){
		if(to[i] == p) continue;
		ins(to[i], u, n, d+1);
	}
	fr(j, 0, k){
		if(d > j)
			cnt[n][j] += (d-j+k-1)/k;
	}
	size2[n]++;
}

ll solve(int u){
	u = get_centroid(u);
	size2[u] = 1;
	ll ans = 0;
	fre(i, u){
		ans += calc(to[i], u, u);
		ins(to[i], u, u);
	}
	fre(i, u){
		del(i);
		del(i^1);
		ans += solve(to[i]);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	cin >> n >> k;
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	cout << solve(0) << endl;	
	
	return 0;
}