#include <bits/stdc++.h>

using namespace std;

const int ms = 6e4 + 200;

int x[ms], v[ms];
int n;

bool can(double t) {
  double l = x[0] - t * v[0], r = x[0] + t * v[0];
  for (int i = 1; i < n; i++) {
    l = max(l, x[i] - t * v[i]);
    r = min(r, x[i] + t * v[i]);
    if (fabs(r - l) > 1e-8 && l > r) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  double lo = 0, hi = 1;
  while (!can(hi)) {
    lo = hi;
    hi = 2 * hi;
  }
  for (int i = 0; i < 300; i++) {
    double m = (lo + hi) / 2;
    if (can(m)) hi = m;
    else lo = m;
  }
  cout << setprecision(12) << fixed << lo << '\n';
}
