#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 0;
    while(n--) {
      int a;
      scanf("%d", &a);
      a %= m;
      a = (m - a) % m;
      ans += a;
    }
    cout << ans << endl;
  }
}