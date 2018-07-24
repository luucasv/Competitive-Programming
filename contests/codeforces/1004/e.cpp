#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

typedef pair<int, int> ii;

vector<ii> adj[ms];
ii ma[ms][4];
int ans[ms];
int dist[ms];

void dfs(int u, int p) {
  for (ii e : adj[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == p) continue;
    dfs(v, u);
    ma[u][3] = ii(w + ma[v][0].first, v);
    dist[v] = w;
    sort(ma[u], ma[u] + 4, greater<ii>());
  }
}

int k;

int can1(int u, int ls, int d) {
  if (u == -1) return 0;
  int ans = 0;
  while (u != -1 and ma[u][0].first > d) {
    ans++;
    if (ma[u][1].first > d) return 1e7;
    ls = u;
    u = ma[u][0].second;
  }
  if (ma[ls][0].first > d) ans++;
  return ans;
}

bool can2(int u, int d, int dd = 0) {
  if (u == -1) return 1;
  if (ma[u][2].first > d) return false;
  if (ma[u][1].first > d) {
    return can1(ma[u][0].second, u, d) + can1(ma[u][1].second, u, d) < k;
  } else if (ma[u][0].first >= d) {
    int dtm = max(dd, ma[u][1].first) + dist[ma[u][0].second];
    if (dtm > d) {
      return can1(ma[u][0].second, u, d) < k;
    } else {
      return can2(ma[u][0].second, d, max(dd, ma[u][1].first) + dist[ma[u][0].second]);
    }
  }
  return 1;
}

int main() {
  int n;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v, d;
    scanf("%d %d %d", &u, &v, &d);
    u--;
    v--;
    adj[u].emplace_back(v, d);
    adj[v].emplace_back(u, d);
  }
  if (k == n) {
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() > 2) ok = 0;
    }
    if (ok) {
      puts("0");
      return 0;
    }
  }
  dfs(0, -1); 
  int lo = 1, hi = 1e9 + 50;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    bool ans = can2(0, md);
    if (ans) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << endl;
}