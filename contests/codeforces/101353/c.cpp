#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int my_log(long long v, bool tp) {
  int ans = sizeof(v) * 8 - __builtin_clzll(v) - 1;
  if (tp && __builtin_popcountll(v) != 1) {
    ans++;
  }
  return ans;
}

const ll mod = 1000000001;

int main() {
  int t = 1;
  int cas = 1;
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n <= 3) {
      ll v[3] = {1, 1, 1};
      for (int k = 0; k < n; k++) scanf("%lld", v + k);
      ll g = __gcd(v[0], __gcd(v[1], v[2]));
      v[0] /= g;
      v[1] /= g;
      v[2] /= g;
      for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
          g = __gcd(v[i], v[j]);
          v[i] /= g;
          v[j] /= g;
        }
        v[i] %= mod;
      }
      ll ans = v[0] * v[1] % mod;
      ans = ans * v[2] % mod;
      printf("%lld\n", ans);
      continue;
    }
    map<ll, ii> mp;
    for (int k = 0; k < n; k++) {
      long long a;
      scanf("%lld", &a);
      for (ll i = 2; i * i <= a; i++) {
        int c = 0;
        while (a % i == 0) {
          c++;
          a /= i;
        }
        ii p = mp[i];
        if (c > p.first) {
          p.second = p.first;
          p.first = c;
        } else if (c > p.second) {
          p.second = c;
        }
        mp[i] = p;
      }
      if (a > 1) {
        ii p = mp[a];
        if (1 > p.first) {
          p.second = p.first;
          p.first = 1;
        } else if (1 > p.second) {
          p.second = 1;
        }
        mp[a] = p;
      }
    }
    ll ans = 1;
    for (auto it : mp) {
      int p = it.second.first - it.second.second;
      while (p--) {
        ans = ans * it.first % mod;
      }
    }
    printf("%lld\n", ans);
  }
}