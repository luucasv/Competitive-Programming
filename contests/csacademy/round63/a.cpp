#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5;
int a[ms], b[ms];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  int ans = 0;
  for (int i = 0; i + n - 1 < m; i++) {
    int ok = 1;
    for (int j = 0; j < n; j++) {
      ok = ok && (a[j] ^ b[i + j]);
    }
    ans += ok;
  }
  cout << ans << endl;
}
