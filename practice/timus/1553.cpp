/*
	Solving Timus 1553. Caves and Tunnels
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = 100000 + 100, me = 2*mv;
int ant[me], to[me], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int go[mv]; 
int start[mv], v[mv];
int mae[mv];
int level[mv];
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
		v[t++] = 0; // all start with 0
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
			v[l] += val;
			st[id] += val;
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

int solve(int u, int vv){
	int ans = 0;
	while(color[u] != color[vv]){
		ans = max(ans, seg.query(pos[start[color[vv]]], pos[vv]));
		vv = mae[start[color[vv]]];
	}
	return max(ans, seg.query(pos[u], pos[vv]));
}


int main(){
	int n, m;
	while(scanf("%d", &n) > 0){
		memset(adj, -1, n * sizeof(int));
		z = 0;

		fr(i, 1, n){
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			add(a, b);
		}

		build();
		seg = SegTree(n);
		scanf("%d", &m);
		while(m--){
			int a, b;
			char ch;
			scanf(" %c %d %d", &ch, &a, &b);
			if(ch == 'I'){
				--a;
				seg.update(pos[a], b);
			}
			else{
				--a, --b;
				int l = lca(a, b);
				printf("%d\n", max(solve(l, a), solve(l, b)));
			}
		}
	}
	return 0;
}