#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 20;
typedef pair<int, int> ii;

set<int> adj[ms];
int d[ms], mk[ms];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ii> edges;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    edges.emplace_back(a, b);
    adj[a].insert(b);
    adj[b].insert(a);
    d[a]++;
    d[b]++;
  }
  queue<int> q;
  int res = n;
  for (int i = 0; i < n; i++) {
    if (d[i] < k) {
      mk[i] = 1;
      q.push(i);
      res--;
    }
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      d[v]--;
      adj[v].erase(u);
      if (d[v] < k && !mk[v]) {
        mk[v] = 1;
        res--;
        q.push(v);
      }
    }
    adj[u].clear();
  }
  vector<int> ans;
  ans.push_back(res);
  reverse(edges.begin(), edges.end());
  int i = 0;
  for (ii e : edges) {
    int u, v;
    tie(u, v) = e;
    if (!mk[u] && !mk[v]) {
      d[u]--;
      d[v]--;
      if (d[u] < k) {
        mk[u] = 1;
        q.push(u);
        res--;
      }
      if (d[v] < k) {
        mk[v] = 1;
        q.push(v);
        res--;
      }
        adj[u].erase(v);
        adj[v].erase(u);
    }
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        d[v]--;
        adj[v].erase(u);
        if (d[v] < k && !mk[v]) {
          mk[v] = 1;
          res--;
          q.push(v);
        }
      }
      adj[u].clear();
    }
    ans.push_back(res);
    i++;
  }
  ans.pop_back();
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
  }
}
