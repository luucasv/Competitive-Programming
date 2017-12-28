#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int ms = 1e5 + 30;
int adj[ms], to[2 * ms], ant[2 * ms], w[2 * ms], z;

inline void add(int a, int b, int c) {
  ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
}

ll tot[ms];
ll sz[ms];
ll ans[ms];
ll dfs(int u, int p = -1) {
  sz[u] = 1;
  tot[u] = 0;
  ans[u] = 0;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v == p) continue;
    ans[u] += dfs(v, u);
    ans[u] %= mod;
    tot[v] = (tot[v] + w[i] * sz[v]) % mod;
    
    ll q = (tot[v] * sz[u] + tot[u] * sz[v]) % mod;
    ans[u] = (ans[u] + q) % mod;
    
    tot[u] = (tot[u] + tot[v]) % mod;
    sz[u] += sz[v];
  }
  return ans[u];
}

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    int n;
    scanf("%d", &n);
    z = 0;
    memset(adj, -1, sizeof adj);
    for (int i = 1; i < n; i++) {
      int a, b;
      ll c;
      scanf("%d %d %lld", &a, &b, &c);
      c %= mod;
      --a, --b;
      add(a, b, c);
      add(b, a, c);
    }
    dfs(0);
    ll res = 0;
    for (int u = 0; u < n; u++) res = (res + ans[u]) % mod;
    printf("Case %d: %lld\n", cas++, res);
  }
}