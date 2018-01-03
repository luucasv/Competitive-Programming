#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 3e3 + 500;
int adj[ms], to[2 * ms], ant[2 * ms], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int dist[ms][ms];

void bfs(int d[], int st) {
  queue<int> fila;
  fila.push(st);
  memset(d, 0x3f, sizeof dist[0]);
  d[st] = 0;
  while (!fila.empty()) {
    int u = fila.front();
    fila.pop();
    for (int i = adj[u]; i > -1; i = ant[i]) {
      int v = to[i];
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        fila.emplace(v);
      }
    }
  }
}

int main() {
  memset(dist, -1, sizeof dist);
  memset(adj, -1, sizeof adj);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(--a, --b);
  }
  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  --s1, --s2, --t1, --t2;
  for (int i = 0; i < n; i++) bfs(dist[i], i);
  if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    puts("-1");
    return 0;
  }
  int mi = dist[s1][t1] + dist[s2][t2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int d1 = dist[s1][i] + dist[i][j] + dist[j][t1];
      int d2 = dist[s2][i] + dist[i][j] + dist[j][t2];
      if (d1 <= l1 && d2 <= l2) mi = min(mi, d1 + d2 - dist[i][j]);
      d1 = dist[s1][j] + dist[j][i] + dist[i][t1];
      if (d1 <= l1 && d2 <= l2) mi = min(mi, d1 + d2 - dist[i][j]);
    }
  }
  cout << m - mi << '\n';
}