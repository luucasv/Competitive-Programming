#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ms = 33;

ll c[ms];

int main() {
  int n;
  ll l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < i; j++) {
      c[i] = min(c[i], (1LL << (i - j)) * c[j]);
    }
  }
  for (int i = n; i < 31; i++) {
    c[i] = (1LL << (i)) * c[0];
    for (int j = 0; j < n; j++) {
      c[i] = min(c[i], (1LL << (i - j)) * c[j]);
    }
  }
  ll cost = 0, ans = 1.5e18;
  for (int i = 30; i > -1; i--) {
    if (l & (1 << i)) {
      cost += c[i];
    } else {
      if (cost  >= ans - c[i]) continue;
      ans = min(ans, cost + c[i]);
    }
  }
  ans = min(ans, cost);
  cout << ans << '\n';
}