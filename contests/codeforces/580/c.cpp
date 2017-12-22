#include <bits/stdc++.h>

using namespace std;

const int mv = 1e5 + 40, me = 2 * mv;

int ant[me], to[me], adj[mv], z;
int a[mv];
int n, m;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int dfs(int u, int p = -1, int c = 0) {
  if (a[u]) {
    c++;
  } else {
    c = 0;
  }
  if (c > m) {
    return 0;
  }
  bool leaf = 1;
  int ans = 0;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v == p) continue;
    leaf = 0;
    ans += dfs(v, u, c);
  }
  if (leaf) {
    return 1;
  } else {
    return ans;
  }
}

int main() {
  cin >> n >> m;
  memset(adj, -1, sizeof adj);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    add(a, b);
  }
  cout << dfs(0) << endl;
}