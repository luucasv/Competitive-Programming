#include <bits/stdc++.h>

#define scl(a) scanf("%lld", &a)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scs(s) scanf(" %s", s)
#define fr(a,b,c) for(int(a) = b; (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a, b) for(int a = adj[b]; ~a; a = ant[a])
#define pri(x) printf("%d\n", x)
#define cl(a, b) memset((a), (b), sizeof(a))
#define EPS 1e-9

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef unsigned int ui;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int minusinf = -0x3f3f3f3f;
const int inf  = 0x3f3f3f3f;


// ---------------------------- DINIC ------------------------------------------------
#define MAXN 120
#define MAXM 1100
#define add(a,b,c) to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
int to[MAXM], cap[MAXM], ant[MAXM], z;
int adj[MAXN], copy_adj[MAXN], fila[MAXN], level[MAXN];

//reset: memset(adj,-1,sizeof adj); z = 0;

int bfs(int source, int sink) {
	memset(level,-1,sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while (front < size) {
		v = fila[front++];
		for (int i = adj[v]; i != -1; i = ant[i]) {
			if (cap[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int v, int sink, int flow) {
	if (v == sink) return flow;
	int f;
	for (int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if (cap[i] && level[to[i]] == level[v]+1 && (f = dfs(to[i], sink, min(flow, cap[i])))) {
			cap[i]-=f, cap[i^1]+=f;
			return f;
		}
	}
	return 0;
}

int maxflow(int source, int sink) {
	int ret = 0, flow;
	while (bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while ((flow = dfs(source, sink, 1<<30))) ret += flow;
	}
	return ret;
}

//------------------------------- BCC - articulação - ponte ------------------------------
const int maxv = 100010, maxe = 100010;

int adj[maxv], ant[maxe], to[maxe];
int idx[maxv], low[maxv], comp[maxv];
int vis[maxv], par[maxv], art[maxv];

int z, bc, t;
stack<int> pilha;
vector<vector<int> >bcs;

inline void add(int a, int b){
    ant[z] = adj[a]; to[z] = b; adj[a] = z++;
}

void gera(int u){
	vector<int> cp;
	while(1){
		int v = pilha.top();
		pilha.pop();
		comp[v] = bc;
		cp.pb(v);
		if(u == v) break;
	}
	bcs.pb(cp);
}

void dfs(int u){
    int v;
    idx[u] = low[u] = t++;
    int cnt = 0;
    pilha.push(u);
    for(int i = adj[u]; ~i; i = ant[i]){
        v = to[i];
        if(idx[v] == -1){
        	cnt++;
        	par[v] = u;
        	dfs(v);
        	low[u] = min(low[u], low[v]);
        	
        	if(idx[u] < low[v]){
        		bridge[i] = bridge[i^1] = 1;
        	}
        	
        	if(idx[u] <= low[v]){
        		if(par[u] != -1) art[u] = 1;
        		pilha.push(u);
        		gera(v);
        		bc++;
        	}
        }
        else if(par[u] != v){
        	low[u] = min(low[u], idx[v]);
        }
    }
    
    if(par[u] == -1 && cnt > 1) art[u] = 1;
}

//----------------------------------- SCC - 2-sat ----------------------------------------

const int mv = 26*2*2, me = 222222;
int to[me], adj[mv], ant[me];
int cmp[mv], idx[mv], low[mv];
int vis[mv];
int z, cp, t;

stack<int> pilha;
vector<vector<int> >scc;


inline void add(int a, int b){
	ant[z] = adj[a]; to[z] = b; adj[a] = z++;
}

inline void add_or(int a, int b){
	if(a == b) add(a^1, a);
	else{
		add(a^1, b);
		add(b^1, a);
	}
}

void gera(int u){
	int v = -1;
	vector<int> vet;
	while(v != u){
		v = pilha.top();
		pilha.pop();
		vis[v] = 0;
		cmp[v] = cp;
		vet.pb(v);
	}
	scc.pb(vet);
}

void dfs(int u){
	int v;
	idx[u] = low[u] = t++;
	pilha.push(u);
	vis[u] = 1;
	fre(i, u){
		v = to[i];
		if(idx[v] == -1)
			dfs(v);
		if(vis[v])
			low[u] = min(low[u], low[v]);
	}
	if(low[u] == idx[u]){
		gera(u);
		cp++;
	}
}


bool is_sat(){
	cl(idx, -1);
	cl(vis, 0);
	cl(cmp, -1);
	t = cp = 0;
	fr(i, 0, mv){
		if(idx[i] == -1 && adj[i] != -1){
			while(!pilha.empty()) pilha.pop();
			dfs(i);
		}
	}
	bool sat = 1;
	fr(i, 0, mv){
		if(cmp[i] == cmp[i^1] && cmp[i] != -1) sat = 0;
		i++;
	}

	return sat;
}



//--------------------------------------------LCA---------------------------------------------------------

void dfs(int u){
	fre(i, u){
		int v = to[i];
		if(F[0][v] == -1){
			level[v] = level[u] + 1;
			F[0][v] = u;
			len[v] = 1+len[u];
			dist[v] = dist[u] + w[i];
			dfs(v);
		} 
	}
}

void lcapre(int n){
	fr(i, 1, 20) rp(j, n) F[i][j] = F[i-1][F[i-1][j]];
}

int lca(int u, int v){
	if(level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	rp(i, 20) if(d & (1 << i)) v = F[i][v];
	
	if(u == v) return u;
	for(int i = 19; ~i; --i){
		if(F[i][v] != F[i][u]){
			u = F[i][u];
			v = F[i][v];
		}
	}
	return F[0][v];
}