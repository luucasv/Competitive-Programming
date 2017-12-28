#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int a[111111], mk[111111], cnt[111111], step;
int values[111111];

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    step++;
    int n;
    scanf("%d", &n);
    int sz = 0;
    bool yep = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (mk[a[i]] != step) {
        cnt[a[i]] = 0;
        values[sz++] = a[i];
      } else {
        yep = 1;
      }
      mk[a[i]] = step;
      cnt[a[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
      int at = values[i];
      ans += cnt[at] * ll(n - cnt[at]);
    }
    if (yep) ans += 2;
    cout << ans / 2 << endl;
  }
}