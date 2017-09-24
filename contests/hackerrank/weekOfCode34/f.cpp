#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define md(x) ((x)%mod)

using namespace std;

typedef long long ll;
const int mv = int(2e5) + 400, me = 2*mv, mlog = 20;
const int Q = 400;

int ant[me], to[me], adj[mv], z;

void add_edge(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

struct query{
	int l, r, lca, k, id;
	query(){}
	query(int l, int r, int lca, int k, int id):l(l), r(r), lca(lca), k(k), id(id){}
	bool operator<(query q){
		if(l / Q != q.l / Q){
			return l / Q < q.l / Q;
		}
		return r < q.r;
	}
};
int t, v[me];
int L[mlog][mv], level[mv];
int st[mv], ed[mv];
int c[mv];

void dfs(int u, int p){
	assert(u < mv);
	st[u] = t;
	v[t++] = u;
	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(v == p){
			continue;
		}
		level[v] = level[u] + 1;
		L[0][v] = u;
		dfs(v, u);
	}
	ed[u] = t;
	v[t++] = u;
}

void lcaPreprocess(int n){
	L[0][0] = 0;
	level[0] = 0;
	dfs(0, 0);
	fr(l, 1, mlog){
		fr(i, 0, n){
			L[l][i] = L[l-1][L[l-1][i]];
		}
	}
}

int lca(int u, int v){
	if(level[u] < level[v]){
		swap(u, v);
	}
	int diff = level[u] - level[v];
	fr(i, 0, mlog){
		if((diff >> i)&1){
			u = L[i][u];
		}
	}
	assert(level[u] == level[v]);
	if(u == v){
		return v;
	}
	for(int i = mlog -1; i > -1; i--){
		if(L[i][u] != L[i][v]){
			u = L[i][u];
			v = L[i][v];
		}
	}
	return L[0][u];
}

ll mapa[mv];
map<ll, int> mp;

int freq[mv], cnt[mv], cntV[mv];
int buck[Q], buckV[Q][mv];
int N;

int getAns(int k){
	int mfreq = -1;
	for(int i = Q - 1; i > -1; i--){
		if(buck[i] > k){
			for(int j = (i + 1) * Q - 1; j > -1; j--){
				if(cnt[j] > k){
					mfreq = j;
					break;
				}
				else{
					k -= cnt[j];
				}
			}
		}
		else{
			k -= buck[i];
		}
	}
	assert(mfreq != -1);
	for(int i = Q - 1; i > -1; i--){
		if(buckV[i][mfreq] > k){
			for(int j = (i + 1) * Q - 1; j > -1; j--){
				if(freq[j] + N == mfreq && k == 0){
					return j;
				}
				else if(freq[j]  + N == mfreq){
					k--;
				}
			}
		}
		else{
			k -= buckV[i][mfreq];
		}
	}
	assert(0);
}

void add(int val, int q){
	val = c[val];

	buck[(freq[val] + N) / Q]--;
	cnt[(freq[val] + N)]--;
	buckV[val/Q][(freq[val] + N)]--;

	freq[val] += q;
	
	buck[(freq[val] + N) / Q]++;
	cnt[(freq[val] + N)]++;
	buckV[val/Q][(freq[val] + N)]++;
}

void ins(int p){
	cntV[v[p]]++;
	if(cntV[v[p]] == 1){
		add(v[p], 1);
	}
	else if(cntV[v[p]] == 2){
		add(v[p], -1);
	}
	else{
		assert(0);
	}
}

void rem(int p){
	cntV[v[p]]--;
	if(cntV[v[p]] == 1){
		add(v[p], 1);
	}
	else if(cntV[v[p]] == 0){
		add(v[p], -1);
	}
	else{
		assert(0);
	}
}

query que[mv];
int ans[mv];

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n, qq;
	cin >> n >> qq;
	fr(i, 0, n){
		cin >> c[i];
		mp[c[i]];
	}
	int meuamigou = 1;
	for(auto &i:mp){
		i.second = meuamigou;
		mapa[meuamigou++] = i.first;
	}

	fr(i, 0, n){
		c[i] = mp[c[i]];
	}
	N = n;
	buck[N / Q] = n;
	cnt[N] = n;
	fr(i, 0, n){
		buckV[c[i]/Q][N]++;
	}
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add_edge(a, b);
	}
	lcaPreprocess(n);
	fr(i, 0, qq){
		int u, v, l, k;
		cin >> u >> v >> k;
		--u, --v, --k;
		if(st[v] < st[u]){
			swap(u, v);
		}
		l = lca(u, v);
		if(i == 2828 || i == 3370 || i == 42117 || i == 49488 || i == 48991){
			dbg(u _ v _ k _ l _ st[u] _ ed[u] _ st[v])
		}
		if(l == u){
			que[i] = query(st[u] + 1, st[v] + 1, l, k, i);
		}
		else{
			que[i] = query(ed[u], st[v] + 1, l, k, i);
		}
	}

	sort(que, que + qq);
	int l = 0, r = 0;
	fr(i, 0, qq){
		query q = que[i];
     	while (r < q.r) ins(r++);
		while (l > q.l) ins(--l);
    	while (l < q.l) rem(l++);
     	while (r > q.r) rem(--r);
		add(q.lca, 1);
		ans[q.id] = getAns(q.k);
		if(q.id == 2828 || i == 3370){
			dbg(c[0])
		}
		add(q.lca, -1);
		assert(ans[q.id] > 0);
	}
	fr(i, 0, qq){
		cout << mapa[ans[i]] << endl;
	}
	return 0;
}