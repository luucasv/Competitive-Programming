#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int ms = 222;
const int inf = 0x3f3f3f3f;
const int mv = 2 * ms + 200, me = 4 * mv + 4 * ms * ms;

int adj[mv], to[me], cap[me], w[me], ant[me], z;

inline void add(int a, int b, int c) {
  ant[z] = adj[a], to[z] = b, cap[z] = 1, w[z] = c, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, cap[z] = 0, w[z] = -c, adj[a] = z++;
}

int a[ms], b[ms];
int c[10][10];

int d[700];
int dist[mv], pot[mv], pai[mv];

set<ii> heap;

void update(int no, int ndist, int p) {
  if (ndist >= dist[no]) return;
  if (dist[no] < inf) {
    heap.erase(ii(dist[no], no));
  }
  dist[no] = ndist, pai[no] = p;
  heap.insert(ii(dist[no], no));
}

ii top() {
  ii ret  = *heap.begin();
  heap.erase(heap.begin());
  return ret;
}

int dijikstra(int src, int sink) {
  heap.clear();
  memset(dist, 0x3f, sizeof dist);
  update(src, 0, -1);
  while (!heap.empty()) {
    ii p = top();
    for (int i = adj[p.second]; i > -1; i = ant[i])  {
      if (cap[i]) {
        update(to[i], p.first + w[i] + pot[p.second] - pot[to[i]], i);
      }
    }
  }
  return dist[sink] < inf;
}

ii mcmf(int src, int sink, int n) {
  memset(pot, 0, sizeof pot);
  ii p(0, 0);
  while (dijikstra(src, sink)) {
    int cost = 0, flow = inf;
    for (int x = sink; x != src; x = to[pai[x] ^ 1]) {
      if (cap[pai[x]] < flow) flow = cap[pai[x]];
    }
    for (int x = sink; x != src; x =  to[pai[x] ^ 1]) {
      cap[pai[x]] -= flow;
      cap[pai[x] ^ 1] += flow;
      cost += w[pai[x]] * flow;
    }
    for (int x = 0; x < n; x++) {
      pot[x] += dist[x];
    }
    p.first += cost, p.second += flow;
  }
  return p;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int k;
  cin >> k;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c[i][j];
    }
  }
  memset(adj, -1, sizeof adj);
  int src = 2 * n , sink = src + 1;
  for (int i = 0; i < n; i++) {
    add(src, i << 1, 0);
    add(2 * i + 1, sink, 0);
    memset(d, 0x3f, sizeof d);
    d[a[i]] = 0;
    heap.clear();
    heap.insert(ii(0, a[i]));
    while (heap.size()) {
      int dd, v;
      tie(dd, v) = *heap.begin();
      heap.erase(heap.begin());
      for (int bi = 0; bi < 8; bi++) {
        for (int bj = 0; bj < 8; bj++) {
          if (((v >> bi) & 1) == ((v >> bj) & 1)) continue;
          int nv = v;
          nv ^= (1 << bi);
          nv ^= (1 << bj);
          int nd = dd + c[bi][bj];
          if (nd < d[nv]) {
            if(d[nv] < 0x3f3f3f3f) heap.erase(ii(d[nv], nv));
            d[nv] = nd;
            heap.insert(ii(nd, nv));
          }
        }
      }
    }
    for (int j = 0; j < n; j++) {
      int mn = 1e9;
      for (int m = 1; m < 512; m++) {
        if ((m | b[j]) < k) continue;
        mn = min(mn, d[m]); 
      }
      if (a[i] == 256) {
        mn = 0;
      }
      add(2 * i, 2 * j + 1, mn);
    }
  }
  cout << mcmf(src, sink, n).first << '\n';
}