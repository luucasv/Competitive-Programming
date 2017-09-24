/*
	Codeforces: 321C. Ciel the Commander
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = int(1e5) + 100, me = 2*mv, mk = 511;
int ant[me], to[me], adj[mv], z;
int size[mv], maxDown[mv], go[mv];
bool cent[mv];

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
		if(to[i] == p || cent[to[i]])
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

int k;
int cnt[mk];

void ins(int u, int p, int size){
	if(size >= k)
		return;
	cnt[size]++;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]] || to[i] == p)
			continue;
		ins(to[i], u, size+1);
	}
}

ll calc(int u, int p, int size){
	if(size > k)
		return 0;
	ll ans = cnt[k - size];
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]] || to[i] == p)
			continue;
		ans += calc(to[i], u, size+1);
	}
	return ans;
}

ll solve(int u){
	u = getCentroid(u);
	cent[u] = true;
	memset(cnt, 0, k * sizeof(int));
	cnt[0] = 1;
	ll ans = 0;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]])
			continue;
		ans += calc(to[i], u, 1);
		ins(to[i], u, 1);
	}
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]])
			continue;
		ans += solve(to[i]);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n;
	cin >> n >> k;
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	cout << solve(0) << endl;
	return 0;
}