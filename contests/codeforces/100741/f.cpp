#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 311;

int mat[ms][ms];
map<int, int> mp;
int ret[ms * ms];

const int mv = ms * ms * 2 + 500, me = 2 * (ms * ms + 2 * ms + ms * ms);

int adj[mv], to[me], cap[me], ant[me], z;
int c_adj[mv];

inline void add(int a, int b) {
  // cout << a << ' ' << b << '\n';
  ant[z] = adj[a], to[z] = b, cap[z] = 1, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, cap[z] = 0, adj[a] = z++;
}

int level[mv], fila[mv];

int bfs(int src, int sink) {
  memset(level, -1, sizeof level);
  level[src] = 0;
  int front = 0, size = 0;
  fila[size++] = src;
  while (front < size) {
    int v = fila[front++];
    for (int i = adj[v]; i > -1; i = ant[i]) {
      if (cap[i] && level[to[i]] == -1) {
        level[to[i]] = level[v] + 1;
        fila[size++] = to[i];
      }
    }
  }
  return level[sink] != -1;
}

int dfs(int v, int sink, int flow = 1 << 30) {
  if (v == sink) return flow;
  int f;
  for (int &i = c_adj[v]; i > -1; i = ant[i]) {
    if (cap[i] && level[to[i]] == level[v] + 1 && (f = dfs(to[i], sink, min(flow, cap[i])))) {
      cap[i] -= f;
      cap[i^1] += f;
      return f;
    }
  }
  return 0;
}

int maxflow(int src, int sink) {
  int ans = 0;
  int flow;
  while (bfs(src, sink)) {
    memcpy(c_adj, adj, sizeof adj);
    while (flow = dfs(src, sink)) ans += flow;
  }
  return ans;
}

int get_id(int v) {
  if (!mp.count(v)) {
    int i = mp.size();
    mp[v] = i;
    ret[i] = v;
  }
  return mp[v];
}

int main() {
  int n;
  cin >> n;
  memset(adj, -1, sizeof adj);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", mat[i] + j);
      mat[i][j] = get_id(mat[i][j]);
    }
  }
  int val = 2 * max(n * n + 1, n) + 10;
  int src = val, sink = src + 1;
  for (int i = 0; i < 2 * n - 1; i++) {
    add(src, i << 1);
  }
  for (int i = 0; i < mp.size(); i++) {
    add(2 * i + 1, sink);
  }
  int id = 0;
  for (int i = n-1; i > 0; i--) {
    for (int s = 0; i + s < n; s++) {
      add(id << 1, 2 * mat[i + s][s] + 1);
    }
    id++;
  }
  for (int i = 0; i < n; i++) {
    for (int s = 0; i + s < n; s++) {
      add(id << 1, 2 * mat[s][i + s] + 1);
    }
    id++;
  }
  int mf = maxflow(src, sink);
  if (mf < 2 * n - 1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < 2 * n - 1; i++) {
    int a;
    for (int e = adj[i << 1]; e > -1; e = ant[e]) {
      if (cap[e] == 0) {
        a = ret[to[e] >> 1];
        break;
      }
    }
    printf("%d%c", a, " \n"[i+2 == 2 * n]);
  }
}