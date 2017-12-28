#include <bits/stdc++.h>
#define L(x) (x << 1)
#define R(x) (L(x) | 1)
using namespace std;

typedef pair<int, int> ii;

const int ms = 1e6 + 20, inf = 0x3f3f3f3f;

int n;
int v[ms];
int mn[4 * ms][22];
int lazy[4 * ms];

void build(int idx = 1, int l = 0, int r = n - 1) {
  lazy[idx] = 0;
  if (l == r) {
    memset(mn[idx], 0x3f, sizeof mn[idx]);
    int c = __builtin_popcount(v[l]);
    mn[idx][c] = l;
    return;
  }
  int m = (l + r) / 2;
  build(L(idx), l, m);
  build(R(idx), m + 1, r);
  for (int i = 0; i <= 20; i++) {
    mn[idx][i] = min(mn[L(idx)][i], mn[R(idx)][i]);
  }
}

void updt(int i, int j, int idx = 1, int l = 0, int r = n - 1) {
  if (lazy[idx]) {
    for (int p = 0; p < 10; p++) {
      swap(mn[idx][p], mn[idx][20 - p]);
    }
    if (l != r) {
      lazy[L(idx)] = !lazy[L(idx)];
      lazy[R(idx)] = !lazy[R(idx)];
    }
    lazy[idx] = 0;
  }
  if (r < i || l > j) {
    return;
  }
  if (i <= l && r <= j) {
    for (int p = 0; p < 10; p++) {
      swap(mn[idx][p], mn[idx][20 - p]);
    }
    if (l != r) {
      lazy[L(idx)] = !lazy[L(idx)];
      lazy[R(idx)] = !lazy[R(idx)];
    }
    return;
  }
  int m = (l + r) / 2;
  updt(i, j, L(idx), l, m);
  updt(i, j, R(idx), m + 1, r);
  for (int p = 0; p <= 20; p++) {
    mn[idx][p] = min(mn[L(idx)][p], mn[R(idx)][p]);
  }
}

ii qry(int i, int j, int q, int idx = 1, int l = 0, int r = n - 1) {
  if (lazy[idx]) {
    for (int p = 0; p < 10; p++) {
      swap(mn[idx][p], mn[idx][20 - p]);
    }
    if (l != r) {
      lazy[L(idx)] ^= 1;
      lazy[R(idx)] ^= 1;
    }
    lazy[idx] = 0;
  }
  if (r < i || l > j) {
    return {inf, inf};
  }
  if (i <= l && r <= j) {
    ii ans(inf, inf);
    for (int p = 0; p <= 20; p++) {
      if (mn[idx][p] < inf) {
        ans = min(ans, {abs(p - q), mn[idx][p]});
      }
    }
    assert(ans < ii(inf, inf));
    return ans;
  }
  int m = (l + r) / 2;
  return min(qry(i, j, q, L(idx), l, m), qry(i, j, q, R(idx), m + 1, r));
}

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    build();
    printf("Case %d:\n", cas++);
    while (m--) {
      int t, l, r;
      scanf("%d %d %d", &t, &l, &r);
      --l, --r;
      assert(l <= r);
      if (t == 2) {
        updt(l, r, 1, 0, n-1);
      } else {
        int q;
        scanf("%d", &q);
        q = __builtin_popcount(q);
        ii ans = qry(l, r, q, 1, 0, n-1);
        printf("%d\n", ans.second + 1);
      }
    }
  }
}