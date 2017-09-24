#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int mv = 211111, me = 2*mv;
int ant[me], to[me], adj[mv], d[mv];
int color[mv], vis[mv], vc[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b; adj[a] = z++, d[a]++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b; adj[a] = z++, d[a]++;
}

int sz;
int at;
void dfs(int u){
	vis[u] = 1;
	if(r[at].size() == sz)
		++at;
	r[at].push_back(u);
	int v;
	for(int i = adj[u]; i != -1; i = ant[i]){
		v = to[i];
		if(vis[v])
			continue;
		ok = 1;
		
		dfs(v);
	}
}



int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n, m, k;
	cin >> n >> m >> k;
	sz = (2*n + k - 1) / k;
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		if(conn(a, b))
			add(a, b);
	}
	dfs(0);
	return 0;
}