#include <bits/stdc++.h>

using namespace std;

int a[20], mk[1200];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!mk[a[i] + a[j]]) {
        ans++;
        mk[a[i] + a[j]] = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}