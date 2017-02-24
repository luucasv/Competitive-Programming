#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int mv = 2*int(2e5) + 10, me = 2*mv;
int ant[me], to[me], adj[mv];
int comp[mv], low[mv], idx[mv], vis[mv];
int z, cp, t;

int r[mv];
vector<int> ad[mv];

stack<int> pilha;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}
inline void add_or(int a, int b){
	if(a == b)
		add(a^1, a);
	else{
		add(a^1, b);
		add(b^1, a);
	}
}

void gera(int u){
	int v = -1; 
	while(v != u){
		v = pilha.top();
		pilha.pop();
		vis[v] = 0;
		comp[v] = cp;
	}
}

void dfs(int u){
	int v;
	idx[u] = low[u] = t++;
	pilha.push(u);
	vis[u] = 1;
	for(int i = adj[u]; i != -1; i = ant[i]){
		v = to[i];
		if(idx[v] == -1)
			dfs(v);
		if(vis[v])
			low[u] = min(low[u], low[v]);
	}
	if(low[u] == idx[u]){
		cp++;
		gera(u);
	}
}

int n, m;

bool is_sat(){
	memset(idx, -1, sizeof idx);
	memset(vis, 0, sizeof vis);
	memset(comp, -1, sizeof comp);
	t = cp = 0;
	fr(i, 0, 2*m){
		if(idx[i] == -1 && adj[i] != -1){
			while(!pilha.empty())
				pilha.pop();
			dfs(i);
		}
	}
	bool sat = 1;
	fr(i, 0, 2*m){
		if(comp[i] == comp[i^1] && comp[i] != -1)
			sat = 0;
		i++;
	}
	return sat;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	memset(adj, -1, sizeof adj);
	fr(i, 0, n)
		cin >> r[i];
	fr(i, 0, m){
		int q, a;
		cin >> q;
		fr(j, 0, q){
			cin >> a;
			ad[a-1].push_back(i << 1);
		}
	}
	fr(i, 0, n){
		if(r[i] == 0){
			add(ad[i][0], ad[i][1]^1);
			add(ad[i][0]^1, ad[i][1]);
			add(ad[i][1], ad[i][0]^1);
			add(ad[i][1]^1, ad[i][0]);
		}
		else{
			add(ad[i][0], ad[i][1]);
			add(ad[i][0]^1, ad[i][1]^1);
			add(ad[i][1], ad[i][0]);
			add(ad[i][1]^1, ad[i][0]^1);
		}
	}

	puts(is_sat() ? "YES" : "NO");
	return 0;
}