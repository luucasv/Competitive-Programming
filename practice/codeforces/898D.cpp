#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 200;

int a[ms];
int del[ms];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int l = 0, r = 0;
  int ans = 0, cnt = 0;
  while (r < n) {
    if (del[l]) {
      l++;
      cnt--;
      continue;
    }
    while (r < n && a[r] - a[l] < m) {
      if (r - l + 1 - cnt == k) {
        cnt++;
        ans++;
        del[r] = 1;
      }
      r++;
    }
    if (del[l]) cnt--;
    l++;
  }
  cout << ans << endl;
}
