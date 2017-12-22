#include <bits/stdc++.h>

using namespace std;

const int mn = 18;
int s[mn][mn], a[mn];
long long memo[1 << mn][mn];
int n, m, k;

long long dp(int mask, int at) {
  if (__builtin_popcount(mask) == m) return 0;
  if (memo[mask][at] != -1) return memo[mask][at];
  long long ans = 0;
  for (int i = 0; i < n; i++) if (!((mask >> i) & 1)) {
    ans = max(ans, a[i] + s[at][i] + dp(mask | (1 << i), i));
  }
  return memo[mask][at] = ans;
} 

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    cin >> s[x][y];
  }
  memset(memo, -1, sizeof memo);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] + dp(1 << i, i));
  }
  cout << ans << endl;
}