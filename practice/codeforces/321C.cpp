/*
	Codeforces: 321C. Ciel the Commander
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int mv = int(1e5) + 100, me = 2*mv;
int ant[me], to[me], adj[mv], z;
int size[mv], maxDown[mv], go[mv];
char ans[mv];

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
		if(to[i] == p || ans[to[i]] != 0)
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

void solve(int u, char rank = 'A'){
	u = getCentroid(u);
	ans[u] = rank;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(ans[to[i]] != 0)
			continue;
		solve(to[i], rank+1);
	}
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
	solve(0);
	cout << ans[0];
	fr(i, 1, n)
		cout << ' ' << ans[i];
	cout << endl;
	return 0;
}