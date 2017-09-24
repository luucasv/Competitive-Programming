/*
	Spoj: GOT
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = 100000 + 100, me = 2*mv, mlog = 20;
int ant[me], to[me], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int go[mv]; 
int start[mv], v[mv];
int val[mv], mae[mv];
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

vector<int> st[4 * mv];
class RangeTree{
public:
	RangeTree(int n):n(n){
		build(1, 0, n-1);
	}

	bool query(int i, int j, int val){
		if(i > j)
			return false;
		return query(1, 0, n-1, i, j, val);
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
			st[id] = vector<int>(1, v[l]);
			return;
		}
		int m = (l + r)/2;
		build(L(id), l, m);
		build(R(id), m+1, r);
		st[id].resize(st[L(id)].size() + st[R(id)].size());
		merge(st[L(id)].begin(), st[L(id)].end(), st[R(id)].begin(), st[R(id)].end(), st[id].begin());
	}

	bool query(int id, int l, int r, int i, int j, int val){
		if(r < i || l > j){
			return false;
		}
		if(i <= l && r <= j){
			return binary_search(st[id].begin(), st[id].end(), val);
		}
		int m = (l + r)/2;
		return query(L(id), l, m, i, j, val) || query(R(id), m+1, r, i, j, val);
	}
};

RangeTree seg(1);

bool solve(int u, int v, int val){
	bool ans = 0;
	while(color[u] != color[v]){
		ans = ans || seg.query(pos[start[color[v]]], pos[v], val);
		v = mae[start[color[v]]];
	}
	return ans || seg.query(pos[u], pos[v], val);
}


int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) > 0){
		memset(adj, -1, n * sizeof(int));
		z = 0;
		fr(i, 0, n)
			scanf("%d", val + i);

		fr(i, 1, n){
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			add(a, b);
		}
		build();
		seg = RangeTree(n);
		while(m--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			int l = lca(a, b);
			bool ans = solve(l, a, c) || solve(l, b, c);
			if(ans)
				puts("Find");
			else
				puts("NotFind");
		}
	}
	return 0;
}