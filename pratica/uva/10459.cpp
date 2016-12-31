#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int mv = 5111, me = 2*mv;
int ant[me], to[me], adj[mv];
int z;

int vis[mv], ans[mv];
vector<ii> maior[mv];

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int dfs(int u){
	vis[u] = 1;

	maior[u].clear();

	maior[u].push_back(ii(0, -1));
	maior[u].push_back(ii(0, -1));
	int v, at;
	fre(i, u){
		v = to[i];
		if(vis[v])
			continue;

		at = dfs(v);
		maior[u].push_back(ii(at+1, v));
		sort(maior[u].begin(), maior[u].end(), greater<ii>());
		maior[u].pop_back();
	}
	return maior[u][0].first;
}

void solve(int u, int ma){
	vis[u] = 1;

	int v, p, at;
	ans[u] = max(ma, maior[u][0].first);
	fre(i, u){
		v = to[i];
		if(vis[v])
			continue;

		p = (v == maior[u][0].second);
		at = max(ma, maior[u][p].first);
		solve(v, at+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	while(cin >> n){
		memset(adj, -1, sizeof adj);
		z = 0;

		fr(i, 0, n){
			int q, a;
			cin >> q;
			while(q--){
				cin >> a;
				add(i, a-1);
			}
		}

		memset(vis, 0, sizeof vis);
		dfs(0);
		memset(vis, 0, sizeof vis);
		solve(0, 0);
		int ma = 0, mi = n;
		fr(i, 0, n){
			dbg(ans[i] _ i)
			ma = max(ma, ans[i]);
			mi = min(mi, ans[i]);
		}

		vector<int> sma, smi;
		fr(i, 0, n){
			if(ans[i] == ma)
				sma.push_back(i+1);
			else if(ans[i] == mi)
				smi.push_back(i+1);
		}

		dbg(ma _ mi)

		cout << "Best Roots  :";
		for(auto it : smi)
			cout << " " << it;

		cout << endl;

		cout << "Worst Roots :";
		for(auto it : sma)
			cout << " " << it;
		cout << endl;
	}
	return 0;
}