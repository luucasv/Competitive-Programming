#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define fs first
#define sd second

#define X fs.fs
#define Y fs.sd
#define Z sd

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

#define L(x) (x << 1)
#define R(x) ((x << 1) + 1)

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

const int mv = 111111, me = 2*mv;

int ant[me], to[me], adj[mv], vis[mv];
int z;

void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

vector<ii> st[4*mv];
vector<ll> sum[4*mv];
ii v[mv], v2[mv];
ll ans[mv];
int t, sta[mv], edd[mv];

void build(int id, int l, int r){
	if(l == r){
		st[id].pb(v2[l]);
		sum[id].pb(v2[l].sd);
		return;
	}
	
	int md = (l+r)/2;
	build(L(id), l, md);
	build(R(id), md+1, r);
	
	int tam = st[L(id)].size() + st[R(id)].size();
	st[id].assign(tam, ii(0, 0));
	sum[id].resize(tam, 0);
	merge(all(st[L(id)]), all(st[R(id)]), st[id].begin() );
	ll acc = 0;
	fr(i, 0, st[id].size()){
		acc += st[id][i].sd;
		sum[id][i] = acc;
	}
}

ll query(int id, int l, int r, int i, int j, int rk){
	if(l > j || r < i)
		return 0;
	
	if(l == r){
		if(st[id][0].fs < rk)
			return sum[id][0];
		else
			return 0;
	}
	
	if(l >= i && r <= j){
		int p = upper_bound(all(st[id]), ii(rk, -1)) - st[id].begin();
		--p;
		if(p == -1)
			return 0;
		else
			return sum[id][p];
	}
	int md = (l + r)/2;
	ll a = query(L(id), l, md, i, j, rk), b = query(R(id), md+1, r, i, j, rk);
	return a+b;
}

void dfs(int u){
	v2[t] = v[u];
	sta[u] = t++;
	fre(i, u){
		int k = to[i];
		if(sta[k] == -1){
			dfs(k);
			if(v[k].fs >= v[u].fs)
				ans[u] += v[k].sd;
		}
	}
	edd[u] = t-1;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	memset(sta, -1, sizeof sta);
	int n;
	cin >> n;
	int root;
	fr(i, 0, n){
		int a, b, c;
		cin >> a >> b >> c;
		if(a != -1){
			add(i, a-1);
		}
		else{
			root = i;
		}
		v[i] = ii(b, c);
	}
	
	dfs(root);
	
	build(1, 0, n-1);
	
	fr(i, 0, n){
		cout << query(1, 0, n-1, sta[i], edd[i], v[i].fs) << endl;
	}
	return 0;
}