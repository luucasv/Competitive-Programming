#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int mv = 5e4 + 2, me = 1e6 + 30;
int ant[me], to[me], adj[mv], z;
inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int ans[mv], k;

void dfs(int u, int h = 0){
	ans[u] = h+1;
	int v;
	for(int i = adj[u]; i > -1; i = ant[i]){
		v = to[i];
		if(ans[v])
			continue;
		dfs(v, (h+1)%k);
	}
}

int main(){
	int n, m;
	cin >> n >> m >> k;
	memset(adj, -1, sizeof adj);
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	if(k == 1){
		if(m > 0){
			cout << -1 << endl;
		}
		else{
			fr(i, 0, n)
				cout << 1 << endl;
		}
	}
	else{
		fr(i, 0, n){
			if(!ans[i])
				dfs(i);
			cout << ans[i] << endl;
		}
	}
}