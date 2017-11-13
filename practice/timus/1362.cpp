#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int mv = 100000 + 20, me = 2 * mv;

int adj[mv], to[me], ant[me], z;
inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int dfs(int u, int p = -1) {
  vector<int> vv;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v == p) continue;
    vv.push_back(dfs(v, u));
  }
  sort(vv.begin(), vv.end(), greater<int>());
  int ans = 0, cc = 1;
  for (int v : vv) {
    ans = max(ans, cc + v);
    cc++;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  memset(adj, -1, sizeof adj);
  fr(i, 0, n) {
    int u;
    while(scanf("%d", &u), u) {
      u--;
      add(i, u);
    }
  }
  int s;
  scanf("%d", &s);
  printf("%d\n", dfs(s-1));
	return 0;
}