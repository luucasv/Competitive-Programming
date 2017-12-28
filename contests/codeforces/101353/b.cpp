#include <bits/stdc++.h>

using namespace std;

int my_log(long long v, bool tp) {
  int ans = sizeof(v) * 8 - __builtin_clzll(v) - 1;
  if (tp && __builtin_popcountll(v) != 1) {
    ans++;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    unsigned long long n, p;
    int r;
    scanf("%llu %d %llu", &n, &r, &p);
    long double t = (logl(p) - logl(n)) / (logl(100 + r) - logl(100));
    long long ans = floor(t + 1e-6) + 1;
    ans = max(ans, 0LL);
    if (n >= p) ans = 0;
    printf("Case %d: %lld\n", cas++, ans);
  }
}