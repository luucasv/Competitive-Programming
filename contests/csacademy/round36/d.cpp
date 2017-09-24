#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

const int mv = int(1e5) + 10;
int ant[mv], to[mv], adj[mv], z;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

set<int> st;
vector<vector<int>> ops;
int ans[mv];
void dfs(int v){
	vector<int> vt;
	for(auto op : ops[v]){
		if(op < 0){
			if(st.count(-op)){
				vt.push_back(-op);
				st.erase(-op);
			}
		}
		else{
			if(!st.count(op)){
				vt.push_back(-op);
				st.insert(op);
			}
		}
	}
	ans[v] = st.size();
	for(int i = adj[v]; i > -1; i = ant[i]){
		dfs(to[i]);
	}
	for(auto op : vt){
		if(op < 0)
			st.erase(-op);
		else
			st.insert(op);
	}
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	int n;
	cin >> n;
	fr(i, 1, n){
		int a;
		cin >> a;
		add(a-1, i);
	}
	ops = vector<vector<int>>(n);
	fr(i, 0, n){
		int k;
		cin >> k;
		ops[i] = vector<int>(k);
		fr(j, 0, k)
			cin >> ops[i][j];
	}
	dfs(0);
	fr(i, 0, n){
		cout << ans[i] << endl;
	}
}