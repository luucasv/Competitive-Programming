#include <bits/stdc++.h>

using namespace std;
const int ms = 1e5  + 20;

int a[ms];


int main() {
  int ans = 1;
  int at = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      at = 1;
    } else {
      at++;
    }
    ans = max(ans, at);
  }
  cout << ans << endl;
}