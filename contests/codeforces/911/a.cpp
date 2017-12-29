#include <bits/stdc++.h>

using namespace std;

int a[111111];

int main() {
  int n;
  cin >> n;
  int mn = 1e9 + 1;
  int fs;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] < mn) {
      mn = a[i];
      fs = i;
    }
  }
  int ans = 1e9;
  for (int i = fs + 1; i < n; i++) {
    if (a[i] == mn) {
      ans = min(ans, i - fs);
      fs = i;
    }
  }
  cout << ans << endl;
}