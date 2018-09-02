#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 20;

int a[ms];

int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n / 2; i++) {
    ans += max(0, a[i] - s);
  }
  ans += abs(a[n / 2] - s);
  for (int i = n / 2 + 1; i < n; i++) {
    ans += max(0, s - a[i]);
  }
  cout << ans << endl;
}
