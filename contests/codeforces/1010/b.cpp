#include <bits/stdc++.h>

using namespace std;

const int ms = 33;

int p[ms];

int query(int v) {
  cout << v << endl;
  int ans;
  cin >> ans;
  if (ans == 0) exit(0);
  return ans;
}

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    p[i] = query(m);
  }
  int at = 0;
  int lo = 1, hi = int(m) - 1;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (p[at] * query(md) < 0) {
      lo = md + 1;
    } else {
      hi = md - 1;
    }
    at++;
    at %= n;
  }
  query(lo);
  assert(false);
}
