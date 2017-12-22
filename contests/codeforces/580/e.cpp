#include <bits/stdc++.h>
#define L(x) (x << 1)
#define R(x) (L(x) | 1)
using namespace std;
typedef long long ll;

const int ms = 1e5 + 20;
const ll base = 37, mod = 1e9 + 9;

ll seg[4 * ms], sum[ms], pot[ms];
string s;
int n;

void build(int idx = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    seg[idx] = s[l] - '0' + 1;
    return;
  }
  int m = (l + r) / 2;
  build(L(idx), l, m);
  build(R(idx), m + 1, r);
  seg[idx] = (seg[L(idx)] * pot[r - m] + seg[R(idx)]) % mod;
}

int lazy[4 * ms];
void updt(int i, int j, int c, int idx = 1, int l = 0, int r = n - 1) {
  if (lazy[idx]) {
    seg[idx] = sum[r - l + 1] * lazy[idx] % mod;
    if (l != r) {
      lazy[L(idx)] = lazy[idx];
      lazy[R(idx)] = lazy[idx];
    }
    lazy[idx] = 0;
  }
  if (l > j || r < i) {
    return;
  }
  if (i <= l && r <= j) {
    seg[idx] = sum[r - l + 1] * c % mod;
    if (l != r) {
      lazy[L(idx)] = c;
      lazy[R(idx)] = c;
    }
    return;
  }
  int m = (l + r) / 2;
  updt(i, j, c, L(idx), l, m);
  updt(i, j, c, R(idx), m + 1, r);
  seg[idx] = (seg[L(idx)] * pot[r - m] + seg[R(idx)]) % mod;
}

ll qry(int i, int j, int idx = 1, int l = 0, int r = n - 1) {
  if (i > j) {
    return 0;
  }
  if (lazy[idx]) {
    seg[idx] = sum[r - l + 1] * lazy[idx] % mod;
    if (l != r) {
      lazy[L(idx)] = lazy[idx];
      lazy[R(idx)] = lazy[idx];
    }
    lazy[idx] = 0;
  }
  if (l > j || r < i) {
    return 0;
  }
  if (i <= l && r <= j) {
    return seg[idx];
  }
  int m = (l + r) / 2;
  ll a = qry(i, j, L(idx), l, m);
  ll b = qry(i, j, R(idx), m + 1, r);
  int sz = max(0, min(j, r) - m);
  return (a * pot[sz] + b) % mod;
}

int main() {
  int m, k;
  cin >> n >> m >> k;
  cin >> s;
  pot[0] = 1;
  sum[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    sum[i + 1] = (sum[i] + pot[i]) % mod;
    pot[i + 1] = (pot[i] * base) % mod;
  }
  build();
  for (int i = 0; i < m + k; i++) {
    int t, l, r, c;
    scanf("%d %d %d %d", &t, &l, &r, &c);
    --l, --r;
    if (t == 1) {
      updt(l, r, c+1);
    } else {
      ll a = qry(l, r - c);
      ll b = qry(l + c, r);
      puts(a == b ? "YES" : "NO");
    }
  }
}