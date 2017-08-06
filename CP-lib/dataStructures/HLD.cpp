/*
	Spoj: QTREE
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
int val[mv], mae[mv];
int level[mv], rep[mv];
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
		val[to[i]] = w[i];
		rep[i >> 1] = to[i];
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
		v[t++] = val[aux];
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

void build(){
	step++;
	t = cnt = 0;
	dfs(0, 0);
	buildPath();
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


int st[4 * mv];
class SegTree{
public:
	SegTree(int n):n(n){
		build(1, 0, n-1);
	}

	void update(int p, int v){
		update(1, 0, n-1, p, v);
	}

	int query(int i, int j){
		if(i > j)
			return 0;
		return query(1, 0, n-1, i, j);
	}
private:
	int n;

	inline int L(int x){
		return x << 1;
	}

	inline int R(int x){
		return L(x) + 1;
	}

	void build(int id, int l, int r){
		if(l == r){
			st[id] = v[l];
			return;
		}
		int m = (l + r)/2;
		build(L(id), l, m);
		build(R(id), m+1, r);
		st[id] = max(st[L(id)], st[R(id)]);
	}

	void update(int id, int l, int r, int p, int val){
		if(r < p || l > p){
			return;
		}
		if(l == r){
			st[id] = v[l] = val;
			return;
		}
		int m = (l + r)/2;
		update(L(id), l, m, p, val);
		update(R(id), m+1, r, p, val);
		st[id] = max(st[L(id)], st[R(id)]);
	}

	int query(int id, int l, int r, int i, int j){
		if(r < i || l > j){
			return 0;
		}
		if(i <= l && r <= j){
			return st[id];
		}
		int m = (l + r)/2;
		return max(	query(L(id), l, m, i, j), query(R(id), m+1, r, i, j));
	}
};

SegTree seg(1);

int solve(int u, int v){
	int ans = 0;
	while(color[u] != color[v]){
		ans = max(ans, seg.query(pos[start[color[v]]], pos[v]));
		v = mae[start[color[v]]];
	}
	return max(ans, seg.query(pos[u]+1, pos[v])); // u é o lca, e como é por aresta, n inclui o lca
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
		seg = SegTree(n);
		while(scanf(" %s", cmd), strcmp(cmd, "DONE") != 0){
			if(strcmp(cmd, "CHANGE") == 0){
				int i, ti;
				scanf("%d%d", &i, &ti);
				--i;
				seg.update(pos[rep[i]], ti);
			}
			else{
				int u, v;
				scanf("%d%d", &u, &v);
				--u, --v;
				int l = lca(u, v);
				printf("%d\n", max(solve(l, u), solve(l, v)));
			}
		}
	}
	return 0;
}