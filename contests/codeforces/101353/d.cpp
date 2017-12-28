#include <bits/stdc++.h>

using namespace std;

int a[111111];

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    int xr = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      xr ^= a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int aux = xr ^ a[i];
      if (aux < a[i]) {
        ans++;
      }
    }
    printf("Case %d: %d\n", cas++, ans);
  }
}