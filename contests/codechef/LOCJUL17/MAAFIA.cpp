#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<
using namespace std;
typedef long long ll;
const int mv = int(1e5) + 100, me = 2*mv;

int ant[me], to[me], adj[mv], z;
inline void add(int u, int v){
	ant[z] = adj[u], to[z] = v, adj[u] = z++;
	swap(u, v);
	ant[z] = adj[u], to[z] = v, adj[u] = z++;
}

int par[mv], v[mv], dist[mv];
int K;
bool can(int d){
	queue<int> fila;
	memset(par, -1, sizeof par);
	fr(i, 0, K){
		fila.push(v[i]);
		dist[v[i]] = 0;
		par[v[i]] = i;
	}
	while(!fila.empty()){
		int u = fila.front();
		fila.pop();
		if(dist[u] >= d)
			break;
		for(int i = adj[u]; i > -1; i = ant[i]){
			if(par[to[i]] == -1){
				par[to[i]] = par[u];
				dist[to[i]] = dist[u] + 1;
				fila.push(to[i]);
			}
			else if(par[to[i]] != par[u])
				return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	K = k;
	memset(adj, -1, sizeof adj);
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		add(a-1, b-1);
	}
	fr(i, 0, k){
		cin >> v[i];
		--v[i];
	}
	int lo = 0, hi = n;
	while(hi - lo > 1){
		int md = (lo + hi) / 2;
		if(can(md))
			lo = md;
		else
			hi = md;
	}
	if(!can(hi))
		hi = lo;
	can(hi);
	int ans = 0;
	fr(i, 0, n)
		if(par[i] != -1)
			ans++;
	cout << ans << endl;
	return 0;
} 