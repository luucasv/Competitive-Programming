#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int mv = int(1e5) + 100, me = 2 * mv;
int ant[me], to[me], d[mv], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, d[a]++, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, d[a]++, adj[a] = z++;
}

double dfs(int u = 0, int p = 0){
	int deg = d[u] - 1 + (u == 0);
	double prob = 1.0 / deg, ans = 0;
	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(v == p)
			continue;
		ans += prob * (1 + dfs(v, u));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n;
	cin >> n;
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	cout << fixed << setprecision(10) << dfs() << endl;
	return 0;
}
