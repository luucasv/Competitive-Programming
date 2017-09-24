#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int mv = int(1e5) + 20, me = 2*mv;
int ant[me], to[me], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;	
}

int go[mv], start[mv];
int mae[mv], level[mv];
int color[mv], pos[mv];
bool mk[mv];
int cnt, t;

int dfs(int u, int p){
	int maxDown = 0, size = 1;
	go[u] = -1;
	mae[u] = p;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(to[i] == p || mk[to[i]])
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
		pos[aux] = t++;
		mk[aux] = 1;
		color[aux] = cnt;
		aux = go[aux];
 	}
 	cnt++;
 	aux = u;
 	while(aux > -1){
 		for(int i = adj[aux]; i > -1; i = ant[i]){
 			if(mk[to[i]])
 				continue;
 			buildPath(to[i]);
 		}
 		aux = go[aux];
 	}
}


void build(){
	t = cnt = 0;
	t = 1;
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

int B1[mv], B2[mv];

void update(int B[], int p, int v){
	while(p <= mv){
		B[p] += v;
		p += p&-p;
	}
}

void update(int a, int b, int v){
	update(B1, a, v);
	update(B1, b+1, -v);
	update(B2, a, v * (a-1));
	update(B2, b+1, -v*b);
}

int query(int B[], int p){
	int ans = 0;
	while(p > 0){
		ans += B[p];
		p -= p&-p;
	}
	return ans;
}

int query(int p){
	return query(B1, p) * p - query(B2, p);
}

int query(int a, int b){
	return query(b) - query(a-1);
}

int add(int u, int v, int q){
	while(color[u] != color[v]){
		update(pos[start[color[v]]], pos[v], q);
		v = mae[start[color[v]]];
	}
	update(pos[u], pos[v], q);
}

int solve(int u, int v){
	int ans = 0;
	while(color[u] != color[v]){
		ans += query(pos[start[color[v]]], pos[v]);
		v = mae[start[color[v]]];
	}
	ans += query(pos[u], pos[v]);
	return ans;
}

int main(){
	// ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n, q;
	scanf("%d %d", &n, &q);
	fr(i, 1, n){
		int p;
		scanf("%d", &p);
		--p;
		add(i, p);
	}
	build();
	while(q--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a, --b, --c;
		int v[3] = {a, b, c};
		sort(v, v+3);
		int ans = 0;
		do{
			int l = lca(v[0], v[1]);
			add(l, v[0], 1);
			add(l, v[1], 1);
			update(pos[l], pos[l], -1);
			int l2 = lca(v[1], v[2]);
			int p = solve(l2, v[1]) + solve(l2, v[2]) - query(pos[l2], pos[l2]);
			ans = max(ans, p);
			add(l, v[0], -1);
			add(l, v[1], -1);
			update(pos[l], pos[l], +1);
		}while(next_permutation(v, v+3));
		printf("%d\n", ans);
	}

	return 0;
}