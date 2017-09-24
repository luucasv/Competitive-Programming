#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int ms = int(1e5) + 100;

int adj[20], t[20], mk[20], step;
int n;
int dfs(int u){
	memset(dist, 0x3f, sizeof distt)
	mk[u] = step;
	int ans = 20;
	fr(i, 0, n){
		if(((adj[u] >> i)&1) && mk[i] != step){
			ans = min(ans, dfs(i));
		}
	}
	ans += t[u];
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	int ans = 0;
	fr(i, 0, n){
		cin >> t[i];
		ans += t[i];
	}
	fr(i, 1, n){
		int x;
		cin >> x;
		--x;
		adj[i] |= (1 << x);
		adj[x] |= (1 << i);
	}
	fr(i, 0, n){
		step++;
		ans = min(ans, dfs(i));
	}
	cout << ans << endl;
}