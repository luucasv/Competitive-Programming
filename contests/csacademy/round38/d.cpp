#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> adj[111111];
int v[111111], at;

void dfs(int u, int p, int h){
	if(h)
		v[at++] = u;
	for(auto v : adj[u]){
		if(v != p){
			dfs(v, u, 1 - h);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fr(i, 0, n)
			adj[i].clear();
		set<ii> st;
		fr(i, 1, n){
			int a, b;
			cin >> a >> b;
			--a, --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			st.insert(ii(min(a, b), max(a, b)));
		}
		fr(i, 0, n){
			sort(adj[i].begin(), adj[i].end(), [](int a, int b){return adj[a].size() < adj[b].size();});
		}
		at = 0;
		dfs(0, 0, 0);
		dfs(0, 0, 1);
		bool ok = true;
		fr(i, 0, n)
			dbg(i _ v[i]+1)
		fr(i, 0, at-1){
			if(st.count(ii(min(v[i+1], v[i]), max(v[i+1], v[i])) ) )
				ok = false;
		}
		if(!ok){
			cout << "-1\n"; 
		}
		else{
			cout << v[0];
			fr(i, 1, at)
				cout << ' ' << v[i];
			cout << endl;
		}
	}
	return 0;
}