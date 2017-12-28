#include <bits/stdc++.h>

using namespace std;

const int ms = 1e3 + 20;

int a[ms];
int k, n;

bool can(long long q) {
  long long tot = q * k;
  for (int i = 0; i < n; i++) {
    tot -= min(tot, min((long long)a[i], q));
  }
  return tot == 0;
}

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    long long lo = 0, hi = 1;
    while (can(hi)) {
      lo = hi;
      hi <<= 1;
    }
    while (hi - lo > 1) {
      long long m = (lo + hi) / 2;
      if (can(m)) {
        lo = m;
      } else {
        hi = m;
      }
    }
    long long ans = hi;
    if (!can(hi)) ans = lo;
    printf("Case %d: %lld\n", cas++, ans);
  }
}