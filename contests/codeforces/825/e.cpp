#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 111111, inf = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef long long int ll;

int d[ms];
vector<int> adj[ms];
int memo[ms], ans[ms];

int menor(int u){
	if(memo[u] != -1)
		return memo[u];
	int ans = u;
	for(auto v : adj[u]){
		ans = min(ans, menor(v));
	}
	return memo[u] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(memo, -1, sizeof memo);
	int n, m;
	cin >> n >> m;
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		d[b]++;
	}
	priority_queue<ii, vector<ii>, greater<ii>> hp;
	fr(i, 0, n)
		if(d[i] == 0)
			hp.push(ii(menor(i), i));
	int at = 1;
	while(!hp.empty()){
		int u = hp.top().second;
		hp.pop();
		ans[u] = at++;
		for(auto v : adj[u]){
			d[v]--;
			if(d[v] == 0)
				hp.push(ii(menor(v), v));
		}
	}
	fr(i, 0, n){
		assert(ans[i] > 0);
		cout << ans[i] << ' ';
	}
	cout << endl; 
	return 0;
}