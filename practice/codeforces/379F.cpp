/*
	Codeforces: 379F. New Year Tree
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = int(5e5) * 2 + 10, me = 2*mv, mlog = 20;
const int inf = int(1e7);
int ant[me], to[me], prox[me], adj[mv], z;
int size[mv], maxDown[mv], go[mv];
int rk[mv];

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

void dfs(int u, int p){
	size[u] = 1;
	maxDown[u] = 0;
	go[u] = u;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(to[i] == p)
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
		if(to[i] == p)
			continue;
		setDist(to[i], u, level, d+1);
	}
}

void init(int u, int p = -1, int level = 1){
	u = getCentroid(u);
	par[u] = p;
	rk[u] = level;
	for(int i = adj[u]; i > -1; i = ant[i]){
		del(i);
		del(i^1);
		setDist(to[i], u, level, 1);
		init(to[i], u, level+1);
	}
}

ii save[mv][3];

int getAns(int u, int ls, int at){
	if(at < 0)
		return -inf;
	int d = dist[u][rk[at]], dto = 0;
	if(save[at][0].second == ls){
		dto = save[at][1].first;
	}
	else{
		dto = save[at][0].first;
	}
	int sum = d + dto;
	if(at > u){
		sum = 0;
	}
	return max(sum, getAns(u, at, par[at]));
}

void ins(int u, int ls, int at){
	if(at < 0)
		return;
	int d = dist[u][rk[at]];
	if(save[at][0].second == ls){
		save[at][0].first = max(d, save[at][0].first);
	}
	else if(save[at][1].second == ls){
		save[at][1].first = max(d, save[at][1].first);
		if(save[at][1] > save[at][0]){
			swap(save[at][1], save[at][0]);
		}
	}
	else{
		save[at][2] = ii(d, ls);
		if(save[at][2] > save[at][1]){
			swap(save[at][2], save[at][1]);
			if(save[at][1] > save[at][0]){
				swap(save[at][1], save[at][0]);
			}
		}
	}
	ins(u, at, par[at]);
}

int ans[mv];

int main(){
	// ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n = 4;
	save[0][0] = ii(0, 0);
	save[0][1] = ii(0, 0);
	fr(i, 1, n){
		save[i][0] = ii(0, i);
		save[i][1] = ii(0, i);
		add(0, i);
	}
	int q;
	scanf("%d", &q);
	fr(i, 0, q){
		int v;
		scanf("%d", &v);
		v--;
		save[n][0] = ii(0, n);
		save[n][1] = ii(0, n);
		add(v, n++);
		save[n][0] = ii(0, n);
		save[n][1] = ii(0, n);
		add(v, n++);
	}
	init(0);
	fr(i, 0, n){
		int id = max((i-4)/2, 0);
		if(id){
			ans[id] = max(ans[id], ans[id-1]);
		}
		int ma = getAns(i, i, i);
		ans[id] = max(ans[id], ma);
		ins(i, i, i);
	}
	fr(i, 0, q){
		printf("%d\n", ans[i]);
	}
	return 0;
}