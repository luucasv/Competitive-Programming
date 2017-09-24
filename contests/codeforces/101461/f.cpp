#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef unsigned long long ull;
const int mv = 110, me = 10*mv;
int conn[60][60], step;
int ant[me], to[me], cap[me], scap[me];
int level[mv], adj[mv], copy_adj[mv], sadj[mv], fila[mv];
int z;

inline void add(int a, int b, int c){
	// dbg(a _ b _ c)
	ant[z] = adj[a], to[z] = b, cap[z] = c, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, cap[z] = 0, adj[a] = z++;
}

int bfs(int src, int sink){
	memset(level, -1, sizeof level);
	level[src] = 0;
	int front = 0, size = 0, v;
	fila[size++] = src;
	while(front < size){
		v = fila[front++];
		for(int i = adj[v]; i > -1; i = ant[i]){
			if(cap[i] && level[to[i]] == -1){
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int v, int sink, int flow){
	if(v == sink)
		return flow;
	int f;
	for(int &i = copy_adj[v]; i > -1; i = ant[i]){
		if(cap[i] && level[to[i]] == level[v] + 1 && (f = dfs(to[i], sink, min(flow, cap[i])))){
			cap[i] -= f;
			cap[i^1] += f;
			return f;
		}
	}
	return 0;
}

int maxflow(int src, int sink){
	int ret = 0, flow;
	while(bfs(src, sink)){
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(src, sink, 1 << 30))) 
			ret += flow;
	}
	return ret;
}

int main() {
	freopen ("cabletv.in","r+",stdin);
	freopen ("cabletv.out","w+",stdout);
	int n, m;
	while(scanf("%d %d", &n, &m) > 0){
		++step;
		if(n == 0){
			puts("0");
			continue;
		}
		memset(adj, -1, sizeof adj);
		z = 0;
		fr(i, 0, n){
			add(i << 1, (i << 1) + 1, 1);
		}
		int src = 2*n + 1 , sink = src + 1;
		fr(i, 0, m){
			int a, b;
			scanf(" (%d,%d)", &a, &b);
			conn[a][b] = conn[b][a] = step;
			add((a << 1) + 1, (b << 1), 1);
			add((b << 1) + 1, (a << 1), 1);
		}
		memcpy(scap, cap, sizeof cap);
		memcpy(sadj, adj, sizeof adj);
		int sz = z;
		int ans = n;
		fr(i, 0, n){
			fr(j, i+1, n){
				if(conn[i][j] == step)
					continue;
				memcpy(cap, scap, sizeof cap);
				memcpy(adj, sadj, sizeof adj);
				z = sz;
				add(src, (i << 1) + 1, n);
				add(j << 1, sink, n);
				ans = min(ans, (maxflow(src, sink)));
			}
		}
		printf("%d\n", ans);
	}
}