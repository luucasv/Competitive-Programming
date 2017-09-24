/*
	Spoj: QTREE2
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = 10000 + 100, me = 2*mv, mlog = 20;
int ant[me], to[me], adj[mv], z;
int w[me];

inline void add(int a, int b, int c){
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
}

int go[mv]; 
int start[mv], v[mv];
int mae[mv];
int level[mv], dist[mv];
int color[mv], pos[mv];
int mk[mv], step;
int cnt, t;

int dfs(int u, int p){
	int maxDown = 0, size = 1;
	go[u] = -1;
	mae[u] = p;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(to[i] == p || mk[to[i]] == step)
			continue;
		dist[to[i]] = dist[u] + w[i];
		level[to[i]] = level[u] + 1;
		int sz = dfs(to[i], u);
		size += sz;
		if(sz > maxDown){
			maxDown = sz;
			go[u] = to[i];
		}
	}
	return size;
}

void buildPath(int u = 0){
	start[cnt] = u;
	int aux = u;
	while(aux > -1){
		pos[aux] = t;
		v[t++] = aux;
		mk[aux] = step;
		color[aux] = cnt;
		aux = go[aux];
	}
	cnt++;
	aux = u;
	while(aux > -1){
		for(int i = adj[aux]; i > -1; i = ant[i]){
			if(mk[to[i]] == step)
				continue;
			buildPath(to[i]);
		}
		aux = go[aux];
	}
}

int up(int u){
	if(start[color[u]] != u)
		return start[color[u]];
	return mae[u];
}

int lca(int u, int v){
	while(color[u] != color[v]){
		if(mae[u] == u || level[up(u)] < level[up(v)])
			swap(u, v);
		u = up(u);
	}
	if(level[u] < level[v])
		return u;
	return v;
}

void build(){
	step++;
	t = cnt = 0;
	dfs(0, 0);
	buildPath();
}

int solve(int u, int vv, int k){
	while(color[u] != color[vv]){
		int st = pos[start[color[vv]]], ed = pos[vv];
		if(ed - st >= k){
			return v[ed - k];
		}
		else{
			k -= ed - st + 1;
		}
		vv = mae[start[color[vv]]];
	}
	return v[pos[vv] - k];
}

char cmd[10];

int main(){
	// ios::sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);

		memset(adj, -1, n * sizeof(int));
		z = 0;

		fr(i, 1, n){
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			add(a, b, c);
		}
		build();
		while(scanf(" %s", cmd), strcmp(cmd, "DONE") != 0){
			if(strcmp(cmd, "DIST") == 0){
				int u, v;
				scanf("%d %d", &u, &v);
				--u, --v;
				int l = lca(u, v);
				printf("%d\n", dist[u] + dist[v] - 2 * dist[l]);
			}
			else{
				int u, v, k;
				scanf("%d %d %d", &u, &v, &k);
				--u, --v, --k;
				int l = lca(u, v);
				int first = level[u] - level[l], second = level[v] - level[l], ans;
				if(first >= k){
					ans = solve(l, u, k);
				}
				else{
					// dbg(second - k + first)
					ans = solve(l, v, second - k + first);
				}
				printf("%d\n", ans + 1);
			}
		}
	}
	return 0;
}