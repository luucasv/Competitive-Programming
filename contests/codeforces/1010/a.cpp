#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5;

int a[ms], b[ms];

int n, m;

bool can(long double f) {
  for (int i = 0; i < n; i++) {
    int nx = (i + 1) % n;
    f -= (m + f) / a[i];
    if (f < -1e-15) return false;
    f -= (m + f) / b[nx];
    if (f < -1e-15) return false;
  }
  return true;
}


int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int j = 0; j < n; j++) {
    scanf("%d", b + j);
  }
  long double lo = 0, hi = 1e9;
  for (int i = 0; i < 100; i++) {
    long double md = (lo + hi) / 2;
    if (can(md)) hi = md;
    else lo = md;
  }
  if (!can(hi)) {
    puts("-1");
    return 0;
  }
  cout << fixed << setprecision(10) << hi << endl;
}
