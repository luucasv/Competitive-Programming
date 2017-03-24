/*
	Centroid used to solve Codeforces 790B (791D)
	> Doesn't build the tree <
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(0) cerr << ">>> " << x << endl;
#define _ << " , " <<
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define frec(a, b) for(int a = cadj[b]; a != -1; a = cant[a])

using namespace std;
typedef long long ll;

const int mv = int(2e5)+ 100, me = 2*mv;
int ant[me], to[me], adj[mv], z;
inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}


int vis[mv], cent_mark[mv], size[mv], step;
int max_down[mv], go[mv];
ll cnt[mv][10], size2[mv];

int n, k;

void dfs(int u){
	vis[u] = step;
	size[u] = 1;
	max_down[u] = 0;
	go[u] = u;
	fre(i, u){
		int v = to[i];
		if(vis[v] == step || cent_mark[v])
			continue;
		dfs(v);
		size[u] += size[v];
		if(size[v] > max_down[u]){
			max_down[u] = size[v];
			go[u] = v;
		}
	}
}

int get_centroid(int u){
	++step;	
	dfs(u);
	int sz = size[u]/2;
	while(max_down[u] > sz)
		u = go[u];
	return u;
}

ll calc(int u, int n, int d = 1){
	vis[u] = step;
	ll ans = 0;
	fre(i, u){
		if(cent_mark[to[i]] || vis[to[i]] == step) continue;
		ans += calc(to[i], n, d+1);
	}
	int a = (k - d%k)%k;
	dbg(u _ n _ size[n]*((d+k-1)/k) _ a _ cnt[n][a])
	ans += size2[n]*((d+k-1)/k) + cnt[n][a];
	return ans;
}

void ins(int u, int n, int d = 1){
	vis[u] = step;
	fre(i, u){
		if(cent_mark[to[i]] || vis[to[i]] == step) continue;
		ins(to[i], n, d+1);
	}
	fr(j, 0, k){
		if(d > j)
			cnt[n][j] += (d-j+k-1)/k;
	}
	size2[n]++;
}

ll solve(int u){
	u = get_centroid(u);
	cent_mark[u] = 1;
	size2[u] = 1;
	ll ans = 0;
	fre(i, u){
		if(cent_mark[to[i]]) continue;
		++step;
		ans += calc(to[i], u);
		++step;
		ins(to[i], u);
	}
	fre(i, u){
		if(cent_mark[to[i]]) continue;
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