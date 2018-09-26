#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const int mlog = 25, ms = 1e5 + 20;

vector<ii> adj[ms];
int mk[ms], par[mlog][ms], level[ms];
ll dist[ms];
vector<int> yo;

void dfs(int u, int p) {
  mk[u] = 1;
  for (auto it : adj[u]) {
    int v;
    ll w;
    tie(w, v) = it;
    if (v == p) continue;
    if (mk[v]) {
      yo.push_back(v);
      yo.push_back(u);
      continue;
    }
    dist[v] = dist[u] + w;
    par[0][v] = u;
    level[v] = level[u] + 1;
    dfs(v, u);
  }
}

void dijkstra(ll dd[], int src) {
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(0, src);
  memset(dd, 0x3f, sizeof(ll) * ms);
  dd[src] = 0;
  while (pq.size()) {
    int u;
    ll d;
    tie(d, u) = pq.top();
    pq.pop();
    if (dd[u] < d) continue;
    for (auto it : adj[u]) {
      int v;
      ll c;
      tie(c, v) = it;
      c += d;
      if (c < dd[v]) {
        dd[v] = c;
        pq.emplace(c, v);
      }
    }
  }
}

int lca(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  int diff = level[u] - level[v];
  for (int i = 0; i < mlog; i++) if ((diff >> i) & 1) u = par[i][u];
  if (u == v) return u;
  for (int i = mlog - 1; i > -1; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][v];
}

ll dd[51][ms];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    adj[u].emplace_back(w, v);
    adj[v].emplace_back(w, u);
  }
  dfs(0, 0);
  for (int l = 1; l < mlog; l++) for (int i = 0; i < n; i++) par[l][i] = par[l - 1][par[l - 1][i]];
  sort(yo.begin(), yo.end());
  yo.resize(unique(yo.begin(), yo.end()) - yo.begin());
  for (int i = 0; i < yo.size(); i++) dijkstra(dd[i], yo[i]);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    ll ans = 1e18;
    for (int i = 0; i < yo.size(); i++) {
      int l = lca(u, yo[i]);
      ll res = dist[u] + dist[yo[i]] - 2 * dist[l] + dd[i][v];
      ans = min(ans, res);
    }
    int l = lca(u, v);
    ans = min(ans, dist[u] + dist[v] - 2 * dist[l]);
    printf("%lld\n", ans);
  }
  return 0;
}
