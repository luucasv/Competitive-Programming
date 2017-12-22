#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int mv = 3e5 + 20, me = 2 * mv, mlog = 20;

int ant[me], to[me], adj[mv], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

int t;
int st[mv], ed[mv];

void linear(int u, int p = -1) {
  // cout << "id " << u << " = " << t << '\n';
  st[u] = t++;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v != p) linear(v, u);
  }
  ed[u] = t - 1;
}

int mp[mv], v[mv];
void dfs(int u, int p = -1) {
  v[t] = mp[u];
  // cout << "v " << t << ' ' << mp[u] << '\n';
  st[u] = t++;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v != p) dfs(v, u);
  }
  ed[u] = t - 1;
}

int mi[mlog][mv], ma[mlog][mv];
void preprocess(int n) {
  memcpy(mi[0], v, sizeof v);
  memcpy(ma[0], v, sizeof v);
  for (int p = 1; p < mlog; p++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << (p - 1)) < n) {
        ma[p][i] = max(ma[p - 1][i], ma[p - 1][i + (1 << (p - 1))]);
        mi[p][i] = min(mi[p - 1][i], mi[p - 1][i + (1 << (p - 1))]);
      } else {
        ma[p][i] = ma[p-1][i];
        mi[p][i] = mi[p-1][i];
      }
    }
  }
}

int get_min(int l, int r) {
  int sz = (r - l + 1);
  if (sz <= 0) return 1e8;
  int lg = 31 - __builtin_clz(sz);
  return min(mi[lg][l], mi[lg][r - (1 << lg) + 1]);
}

int get_max(int l, int r) {
  int sz = (r - l + 1);
  if (sz <= 0) return -1;
  int lg = 31 - __builtin_clz(sz);
  return max(ma[lg][l], ma[lg][r - (1 << lg) + 1]);
}

int main() {
  int n;
  cin >> n;
  memset(adj, -1, sizeof adj);
  for (int i = 1; i < n; i++) {
    int a;
    scanf("%d", &a);
    --a;
    add(a, i);
  }
  linear(0);
  set<ii> ranges;
  for (int i = 0; i < n; i++) {
    mp[i] = st[i];
    // cout << "Range " << st[i] << ' ' << ed[i] << '\n'; 
    if (i) ranges.insert(ii(st[i], ed[i]));
  }

  memset(adj, -1, sizeof adj);
  z = 0;
  t = 0;
  for (int i = 1; i < n; i++) {
    int a;
    scanf("%d", &a);
    --a;
    add(a, i);
  }
  dfs(0);
  preprocess(n);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    // cout << "At range " << st[i] << ' ' << ed[i] << '\n';
    // direto
    int mmi = get_min(st[i], ed[i]), mma = get_max(st[i], ed[i]);
    // cout << "dir " << mmi << ' ' << mma << '\n'; 
    if (mma - mmi + 1 == ed[i] - st[i] + 1) {
      ans += ranges.count(ii(mmi, mma));
    }
    // complemento
    mmi = min(get_min(0, st[i] - 1), get_min(ed[i] + 1, n - 1));
    mma = max(get_max(0, st[i] - 1), get_max(ed[i] + 1, n - 1));
    int sz = st[i] + n - ed[i] - 1;
    if (mma - mmi + 1 == sz) {
      ans += ranges.count(ii(mmi, mma));
    }
  }
  cout << ans << endl;
}