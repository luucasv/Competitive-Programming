#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int mv = 211111, me = 2*mv;
int ant[me], to[me], adj[mv];
int color[mv], vis[mv], vc[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b; adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b; adj[a] = z++;
}

int ans;

void dfs(int u, int par){
	vis[u] = 1;
	int v, at = 1;
	for(int i = adj[u]; i != -1; i = ant[i]){
		v = to[i];
		if(vis[v])
			continue;
		while(at == par || at == color[u])
			++at;
		color[v] = at++;
		dfs(v, color[u]);
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
		add(a-1, b-1);
	}
	color[0] = 1;
	dfs(0, -1);
	ans = 0;
	fr(i, 0, n){
		ans = max(ans, color[i]);
	}
	cout << ans << endl;
	fr(i, 0, n)
		cout << color[i] << " ";
	cout << endl;
	return 0;
}