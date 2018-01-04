#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      scanf("%*d %*d");
    }
    cout << n % 2 << '\n';
  }
}
