#include <bits/stdc++.h>
#define L(x) (x << 1)
#define R(x) (L(x) + 1)

using namespace std;

typedef long long ll;

const int ms = 5e4 + 300;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

ll lazy[4 * ms];
ll st[4 * ms];
int n;

void push(int idx, int l, int r) {
  st[idx] += lazy[idx];
  if (l != r) {
    lazy[L(idx)] += lazy[idx];
    lazy[R(idx)] += lazy[idx];
  }
  lazy[idx] = 0;
}

void update(int i, int j, ll v, int idx = 1, int l = 0, int r = n - 1) {
  push(idx, l, r);
  if (r < i || l > j) {
    return;
  }
  if (i <= l && r <= j) {
    lazy[idx] += v;
    push(idx, l, r);
    return;
  }
  int m = (l + r) / 2;
  update(i, j, v, L(idx), l, m);
  update(i, j, v, R(idx), m + 1, r);
  st[idx] = min(st[L(idx)], st[R(idx)]);
}

ll query(int i, int j, int idx = 1, int l = 0, int r = n - 1) {
  push(idx, l, r);
  if (r < i || l > j) {
    return inf;
  }
  if (i <= l && r <= j) {
    return st[idx];
  }
  int m = (l + r) / 2;
  return min(
    query(i, j, L(idx), l, m),
    query(i, j, R(idx), m + 1, r)
  );
}

int a[ms];

int gcd(int a, int b) {
  if (a == 0) return b;
  return __gcd(a, b);
}

int maxs[ms];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  map<int, int> gcds;
  ll prefix = 0;
  int size = 0;
  maxs[size++] = -1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    map<int, int> new_gcds;
    int aa = abs(a[i]);
    new_gcds[aa] = i;
    for (const auto &it : gcds) {
      int g = gcd(aa, it.first);
      if (new_gcds.count(g)) {
        new_gcds[g] = min(new_gcds[g], it.second);
      } else {
        new_gcds[g] = it.second;
      }
    }
    gcds.swap(new_gcds);
    while (size > 1 && a[maxs[size - 1]] <= a[i]) {
      update(maxs[size - 2] + 1, maxs[size - 1], -a[maxs[size - 1]]);
      size--;
    }
    maxs[size++] = i;
    update(i, i, prefix);
    update(maxs[size - 2] + 1, i, a[i]);
    prefix += a[i];
    for (const auto &it : gcds) {
      ans = max(ans, it.first * (prefix - query(it.second, i)));
    }
  }
  cout << ans << '\n';
}