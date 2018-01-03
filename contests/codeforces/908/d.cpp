#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ms = 1001;
const ll mod = 1e9 + 7;

ll memo[ms][ms];

ll pa, pb, ipa, ipb;
int k;

ll fexp(ll a, ll e) {
  ll r = 1;
  for (; e; e >>= 1) {
    if (e & 1) {
      r = r * a % mod;
    }
    a = a * a % mod;
  }
  return r;
}

ll dp(int qab, int qa) {
  if (qab + qa >= k) {
    return (ipb + qa - 1 + mod) % mod;
  }
  ll &ans = memo[qab][qa];
  if (ans != -1) return ans;
  ans = ((pa * dp(qab, qa + 1)) % mod + (pb * (dp(qab + qa, qa) + qa)) % mod ) % mod;
  return ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  cin >> k >> pa >> pb;
  ll ab = fexp(pa + pb, mod - 2);
  pa = pa * ab % mod;
  pb = pb * ab % mod;
  ipa = fexp(pa, mod - 2);
  ipb = fexp(pb, mod - 2);
  cout << dp(0, 1) << '\n';
  return 0;
}