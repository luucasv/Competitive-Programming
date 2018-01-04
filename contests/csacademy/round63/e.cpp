#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> i3;

const int mv = 1e5 + 20, me = 2 * mv;

int adj[mv], to[me], ant[me], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int t;
int le[mv], ri[mv];
vector<i3> que[mv];
int ans[mv], n, q;

int get_id(const vector<ii> &v, int i) {
  auto it = upper_bound(v.begin(), v.end(), ii(i, 1e9));
  if (it == v.begin()) return v.size();
  --it;
  if (it->first <= i && i <= it->second) return it - v.begin();
  return v.size();
}

int size(const vector<ii> &v, int i, int sz) {
  if (i == v.size()) {
    return n - sz;
  }
  return v[i].second - v[i].first + 1;
}

int dfs(int u, int p = -1) {
  vector<ii> v;
  le[u] = t++;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    if (to[i] == p) continue;
    dfs(to[i], u);
    v.emplace_back(le[to[i]], ri[to[i]]);
  }
  ri[u] = t - 1;
  for (i3 q : que[u]) {
    int ia = get_id(v, le[q.second.first]);
    int ib = get_id(v, le[q.second.second]);
    if (ia == ib) continue;
    ans[q.first] =
        n - size(v, ia, ri[u] - le[u] + 1) - size(v, ib, ri[u] - le[u] + 1);
  }
}

int main() {
  cin >> n >> q;
  memset(adj, -1, sizeof adj);
  memset(le, -1, sizeof le);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(--a, --b);
  }
  for (int i = 0; i < q; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    que[--c].push_back(i3(i, ii(--a, --b)));
  }
  dfs(0);
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
}
