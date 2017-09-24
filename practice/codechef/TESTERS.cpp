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

const int mv = int(3e5) + 100, me = 2*mv, ms = int(1.6e6) + 100;
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

ll BIT[2][me];

void add(ll BIT[], int p, ll v){
	assert(p > 0 && p < me);
	while(p > 0){
		BIT[p] += v;
		p -= p&-p;
	}
}

ll sum(ll BIT[], int p, int m){
	assert(p > 0 && p < me);
	ll ans = 0;
	while(p < m){
		ans += BIT[p];
		p += p&-p;
	}
	return ans;
}

int s[ms], v[mv];
int sz;

void ins(int u, int p, int diff, int size){
	size++;
	diff += s[v[u]];
	add(BIT[0], diff, 1);
	add(BIT[1], diff, size);
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]] || to[i] == p)
			continue;
		ins(to[i], u, diff, size);
	}
}

ll calc(int u, int p, int diff, int size){
	diff += s[v[u]];
	size++;
	ll q = sum(BIT[0], sz - (diff - sz), 2*sz);
	ll ans = sum(BIT[1], sz - (diff - sz), 2*sz) + size * q;
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]] || to[i] == p)
			continue;
		ans += calc(to[i], u, diff, size);
	}
	return ans;
}

ll solve(int u){
	int sv = u;
	u = getCentroid(u);
	sz = max(size[sv] - size[u], maxDown[u]) + 10;

	cent[u] = true;
	memset(BIT[0], 0, 2 * sz * sizeof(ll));
	memset(BIT[1], 0, 2 * sz * sizeof(ll));
	
	add(BIT[0], sz + s[v[u]], 1);
	add(BIT[1], sz + s[v[u]], 1);
	
	ll ans = max(0, s[v[u]]);
	for(int i = adj[u]; i > -1; i = ant[i]){
		if(cent[to[i]])
			continue;
		ans += calc(to[i], u, sz, 0);
		ins(to[i], u, sz + s[v[u]], 1);
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
	fr(i, 1, ms){
		for(int j = i; j < ms; j += i){
			s[j] = 1 - s[j];
		}
		i++;
	}
	fr(i, 0, ms){
		if(s[i] == 0)
			s[i] = -1;
	}
	int n;
	cin >> n;
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	fr(i, 0, n)
		cin >> v[i];
	cout << solve(0) << endl;
	return 0;
}