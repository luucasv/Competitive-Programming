#include <bits/stdc++.h>

using namespace std;
const int mv = 2e5 + 20, me = 2 * mv;
int adj[mv], to[me], ant[me], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int dist[2][mv];
int p[mv];

int bfs(int d[], int u) {
  int v;
  queue<int> q;
  q.push(u);
  memset(d, 0x3f, sizeof dist[0]);
  d[u] = 0;
  while (!q.empty()) {
    v = q.front(); q.pop();
    for (int i = adj[v]; i > -1; i = ant[i]) {
      if (d[v] + 1 < d[to[i]]) {
        d[to[i]] = d[v] + 1;
        p[to[i]] = v;
        q.push(to[i]);
      }
    }
  }
  return v;
}

int cant[mv];
int d1, d2;
void dfs(int u, int p = -1) {
  for (int i = adj[u]; i > -1; i = ant[i]) {
    if (to[i] == p) continue;
    dfs(to[i], u);
  }
  if (!cant[u]) {
    int o, d;
    if (dist[0][u] > dist[1][u]) {
      o = d1;
    } else {
      o = d2;
    }
    cout << u+1 << ' ' << o+1 << ' ' << u+1 << '\n';
  }
}

int main() {
  int n;
  cin >> n;
  memset(adj, -1, sizeof adj);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(--a, --b);
  }
  d1 = bfs(dist[0], 0), d2 = bfs(dist[0], d1);
  int at = d2;
  while (d1 != at) {
    cant[at] = 1;
    at = p[at];
  }
  cant[d1] = 1;
  bfs(dist[1], d2);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!cant[i]) ans += max(dist[0][i], dist[1][i]);
  }
  long long d = dist[0][d2];
  ans += d * (d + 1) / 2;
  cout << ans << '\n';
  dfs(d1);
  at = d1;
  while (d2 != at) {
    cout << d2 + 1 << ' ' << at + 1 << ' ' << at + 1 << '\n';
    at = p[at];
  }
}