#include <bits/stdc++.h>

using namespace std;
const int mv = 1e3 + 20, me = 2 * mv;

int ant[me], to[me], adj[mv], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int idx[mv], low[mv], bridge[me], par[mv];
int t;

void dfs(int u) {
  int v;
  idx[u] = low[u] = t++;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    v = to[i];
    if (idx[v] == -1) {
      par[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);

      if (idx[u] < low[v]) {
        bridge[i] = bridge[i ^ 1] = 1;
      }

    } else if (par[u] != v) {
      low[u] = min(low[u], idx[v]);
    }
  }
}

int rt[mv];

int root(int u) {
  if (rt[u] == u) return u;
  return rt[u] = root(rt[u]);
}

void conn(int a, int b) {
  a = root(a), b = root(b);
  rt[a] = b;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  memset(adj, -1, sizeof adj);
  for (int i = 0; i < n; i++) rt[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(a - 1, b - 1);
  }
  memset(idx, -1, sizeof idx);
  for (int i = 0; i < n; i++)
    if (idx[i] == -1) dfs(i);
  for (int i = 0; i < m; i++)
    if (bridge[i << 1]) conn(to[i << 1], to[(i << 1) | 1]);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", root(a - 1) == root(b - 1));
  }
  return 0;
}