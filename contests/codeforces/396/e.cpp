#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define cfre(a, b) for(int a = cadj[b]; a != -1; a = cant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define dbg2(x) cerr << ">>>> " << #x << " = " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mv = 211111, me = 2*mv;

int adj[mv], to[me], ant[me], a[mv];
int z, n;
int size[mv], vis[mv];

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

const int mlog = 30;
int cnt[mv][mlog];

ll solve(int u){
	vis[u] = 1;
	ll ans = a[u];

	fr(i, 0, mlog){
		cnt[u][i] += (a[u] >> i)&1;
	}
	size[u] = 1;

	fre(i, u){
		int v = to[i];
		if(vis[v])
			continue;
		ans += solve(v);
		fr(k, 0, mlog){
			ans += (1LL << k) * ll(cnt[v][k]) * ll(size[u] - cnt[u][k]);
			ans += (1LL << k) * ll(size[v] - cnt[v][k]) * ll(cnt[u][k]);
			cnt[u][k] += (a[u] >> k)&1 ? size[v] - cnt[v][k] : cnt[v][k];
		}
		size[u] += size[v];
	}

	return ans;
}


int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);

	cin >> n;
	fr(i, 0, n)
		cin >> a[i];
	
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	cout << solve(0) << endl;
	return 0;
}