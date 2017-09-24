#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef pair<int, int> ii;
typedef unsigned long long ull;
const int mv = 21111, me = 2 * mv, ms = 511111; 

int ant[me], to[me], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int size[mv];
int maxDown[mv], go[mv];
int level[mv], par[mv];

void dfs(int u, int p){
	size[u] = 1;
	maxDown[u] = 0;
	go[u] = u;
	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(v == p || level[v])
			continue;
		dfs(v, u);
		size[u] += size[v];
		if(size[v] > maxDown[u]){
			maxDown[u] = size[v];
			go[u] = v;
		} 
	}
}

int getCentroid(int u){
	dfs(u, u);
	int sz = size[u] / 2;
	while(maxDown[u] > sz)
		u = go[u];
	return u;
}

int dist[mv][20];
vector<vector<ii>> has[mv];

void ins(int u, int p, int rt, int d){
	dist[u][level[rt]] = d;
	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(level[v] || p == v)
			continue;
		ins(v, u, rt, d+1);
	}
}

int buildTree(int u = 0, int lvl = 1){
	int sv = u;
	u = getCentroid(u);
	level[u] = lvl;
	has[u] = vector<vector<ii>>(size[sv] + 3, vector<ii>(2, ii(-1, -1)));
	par[u] = -1;

	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(level[v])
			continue;
		ins(v, u, u, 1);
		v = buildTree(v, lvl+1);
		par[v] = u;
	}
	return u;
}

void preprocess(int n){
	fr(i, 0, n){
		int u = i, ls = u, at = u;
		// dbg("going with" _ u)
		while(at > -1){
			int d = dist[u][level[at]];
			// dbg(at _ ls _ has[at][d][0].second _ has[at][d][1].second)
			if(!(has[at][d][0].second == ls) && !(has[at][d][1].second == ls)){
				if(has[at][d][0].second == -1){
					has[at][d][0] = ii(u, ls);
					// dbg("new dist" _ at _ u _ d)
				}
				else if(has[at][d][1].second == -1){
					has[at][d][1] = ii(u, ls);
					// dbg("new dist" _ at _ u _ d)
				}
			}
			ls = at;
			at = par[at];
		}
	}
}

int query(int u, int d){
	int at = u, ls = -1;
	while(at > -1){
		int nd = dist[u][level[at]];
		int need = d - nd;
		if(need >= 0 && need < has[at].size()){
			if(has[at][need][0].second != -1 && has[at][need][0].second != ls)
				return has[at][need][0].first;
			if(has[at][need][1].second != -1 && has[at][need][1].second != ls)
				return has[at][need][1].first;
		}
		ls = at;
		at = par[at];
	}
	return -1;
}

int main() {
	memset(adj, -1, sizeof adj);
	int n, q;
	scanf("%d %d", &n, &q);
	fr(i, 1, n){
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		add(a, b);
	}
	buildTree();
	preprocess(n);
	fr(i, 0, q){
		int v, d;
		scanf("%d %d", &v, &d);
		--v;
		printf("%d\n", query(v, d)+1);
	}
}