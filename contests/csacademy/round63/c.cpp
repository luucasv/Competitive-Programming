#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5;
int a[ms], b[ms];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  int ans = 0;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    int at = abs(a[i] - b[i]);
    ma = max(ma, max(a[i], b[i]));
    if (at > 0) {
      ans = __gcd(ans, at);
    }
  }
  if (ans == 0) {
    cout << ma + 1 << '\n';
    return 0;
  }
  int res = 1e9;
  for (int d = 1; d * d <= ans; d++) {
    if (ans % d) continue;
    int ok = 1;
    for (int i = 0; ok && i < n; i++) {
      if (a[i] % d != b[i]) ok = 0;
    }
    if (ok) {
      res = min(res, d);
    }
    ok = 1;
    int dd = ans / d;
    for (int i = 0; ok && i < n; i++) {
      if (a[i] % dd != b[i]) ok = 0;
    }
    if (ok) {
      res = min(res, dd);
    }
  }
  if (res < 1e9) {
    cout << res << '\n';
  } else {
    cout << "-1\n";
  }
}
