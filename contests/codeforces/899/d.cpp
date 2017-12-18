#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll next(int x) {
  return 10LL * x + 9;
}

int main() {
  int n;
  cin >> n;
  int mx = n + n-1;
  int at = 0;
  while (next(at) <= mx) {
    at = next(at);
  }
  if (at == 0) {
    cout << n * (n - 1) / 2 << '\n';
    return 0;
  }

  int pot = at+1;
  ll ans = 0;
  for (int fs = 0; ll(fs) * pot + at <= mx; fs++) {
    int x = fs * pot + at;
    int lo = max(x - n, 1);
    int hi = min(n, x -1);
    ans += max(0, hi - lo + 1);
  }
  cout << ans / 2 << '\n';

}