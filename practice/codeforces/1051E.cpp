#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int ms = 1e6 + 20;
const int mod = 998244353;

ll pot[ms];

vector<ll> bhs(const string &s) {
  vector<ll> ans(s.size() + 1);
  ans[0] = 0;
  for (int i = 0; i < s.size(); i++) ans[i + 1] = ans[i] * 31 + s[i] - '0' + 1;
  return ans;
}

ll sub_hash(const vector<ll> &a, int l, int sz) {
  return a[l + sz] - a[l] * pot[sz];
}

int cmp(const vector<ll> &a, const vector<ll> &b, int st) {
  int sza = int(a.size()) - st - 1;
  int sz = int(b.size()) - 1;
  if (sza < sz) return -1;
  int lo = 0, hi = sz;
  while (lo < hi) {
    int md = (lo + hi + 1) / 2;
    if (sub_hash(a, st, md) == sub_hash(b, 0, md)) lo = md;
    else hi = md - 1;
  }
  if (lo == sz) {
    return 0;
  }
  return int(sub_hash(a, st + lo, 1)) - int(sub_hash(b, lo, 1)); 
}

int main() {
  string a, l, r;
  cin >> a >> l >> r;
  int n = a.size();
  pot[0] = 1;
  for (int i = 1; i <= n; i++) pot[i] = pot[i - 1] * 31;
  vector<ll> ha = bhs(a), hl = bhs(l), hr = bhs(r);
  vector<int> dp(n + 1, 0), sum(n + 2, 0);
  dp[n] = sum[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    int st = l.size(), ed = r.size();
    if (cmp(ha, hl, i) < 0) st++;
    if (cmp(ha, hr, i) > 0) ed--;
    if (ed < st || i + st > n) {
      dp[i] = 0;
    } else if (a[i] == '0') {
      if (l[0] == '0') dp[i] = dp[i + 1];
      else dp[i] = 0;
    } else {
      ed = min(n, i + ed);
      st = i + st;
      dp[i] = (sum[st] - sum[ed + 1] + mod) % mod;
    }
    sum[i] = (dp[i] + sum[i + 1]) % mod;
  }
  cout << dp[0] << endl;
}
