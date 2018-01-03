#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mm = 11, ms = 1e5 + 100;

ll bits[20][ms];

void add(ll bit[], int p, int v) {
  while (p < ms) {
    bit[p] += v;
    p += p & -p;
  }
}

ll sum(ll bit[], int p) {
  ll ans = 0;
  while (p > 0) {
    ans += bit[p];
    p -= p & -p;
  }
  return ans;
}

ll v[ms];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", v + i);
    add(bits[v[i] % m], i, v[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    char ch;
    int l, r;
    scanf(" %c %d %d", &ch, &l, &r);
    if (ch == '+') {
      add(bits[v[l] % m], l, -v[l]);
      v[l] += r;
      add(bits[v[l] % m], l, v[l]);
      printf("%lld\n", v[l]);
    } else if (ch == '-') {
      add(bits[v[l] % m], l, -v[l]);
      if (v[l] - r >= 0) v[l] -= r;
      add(bits[v[l] % m], l, v[l]);
      printf("%lld\n", v[l]);
    } else {
      int md;
      scanf(" %d", &md);
      printf("%lld\n", sum(bits[md], r) - sum(bits[md], l - 1));
    }
  }
}