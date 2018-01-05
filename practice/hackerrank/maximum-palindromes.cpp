#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ms = 1e5 + 20, sigma = 27;
const ll mod = 1e9 + 7;

int cnt[ms][sigma];
ll ifat[ms], fat[ms];

ll solve(int l, int r) { // [l, r)
  ll ans = 1;
  int total = r - l, odd = 0;
  for (int i = 0; i < sigma; i++) {
    int c = cnt[r][i] - cnt[l][i];
    if (c & 1) odd++;
    ans = ans * ifat[c / 2] % mod;
  }
  if (odd) {
    ans = ans * odd % mod;
    total -= odd - 1;
  }
  ans = ans * fat[total / 2] % mod;
  return ans;
}

ll fexp(ll a, ll e) {
  ll ans = 1;
  for (; e; e >>= 1) {
    if (e&1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  ifat[0] = 1;
  fat[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    fat[i + 1] = fat[i] * (i + 1) % mod;
    ifat[i + 1] = fexp(fat[i + 1], mod - 2) % mod;
    for (int k = 0; k < sigma; k++) {
      cnt[i + 1][k] = cnt[i][k];
      if (s[i] == k + 'a') cnt[i + 1][k]++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    printf("%lld\n", solve(l, r));
  }
}