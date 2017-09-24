/*
	Spoj: QTREE5
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = int(1e5) + 100, me = 2*mv, mlog = 20;
const int inf = int(1e7);
int ant[me], to[me], adj[mv], z;
int size[mv], maxDown[mv], go[mv];
int rk[mv];

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

void dfs(int u, int p){
	size[u] = 1;
	maxDown[u] = 0;
	go[u] = u;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(to[i] == p || rk[to[i]])
			continue;
		dfs(to[i], u);
		size[u] += size[to[i]];
		if(size[to[i]] > maxDown[u]){
			maxDown[u] = size[to[i]];
			go[u] = to[i];
		}
	}
}

int getCentroid(int u){
	dfs(u, u);
	int sz = size[u] / 2;
	while(maxDown[u] > sz){
		u = go[u];
	}
	return u;
}

int par[mv], dist[mv][mlog];

void setDist(int u, int p, int level, int d){
	dist[u][level] = d;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(rk[to[i]] || to[i] == p)
			continue;
		setDist(to[i], u, level, d+1);
	}
}

void init(int u, int p, int level = 1){
	u = getCentroid(u);
	par[u] = p;
	rk[u] = level;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(rk[to[i]])
			continue;
		setDist(to[i], u, level, 1);
		init(to[i], u, level+1);
	}
}

multiset<ii> nodes[mv];
bool color[mv];

void update(int u, int p, bool ins){
	if(p == -1){
		return;
	}
	int d = dist[u][rk[p]];
	if(ins){
		nodes[p].insert(ii(d, u));
	}
	else{
		nodes[p].erase(ii(d, u));
	}
	update(u, par[p], ins);
}

int getAns(int u, int p){
	if(p == -1){
		return inf;
	}

	int d = dist[u][rk[p]];
	int ans = inf;
	if(nodes[p].size()){
		ans = d + (nodes[p].begin()->first);
	}
	ans = min(ans, getAns(u, par[p]));
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n;
	cin >> n;
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	init(0, -1);
	int q;
	cin >> q;
	while(q--){
		int t, u;
		cin >> t >> u;
		--u;
		if(t){
			int ans = getAns(u, u);
			if(ans >= inf)
				ans = -1;
			cout << ans << endl;
		}
		else{
			color[u] = !color[u];
			update(u, u, color[u]);
		}
	}
	return 0;
}