#include <bits/stdc++.h>

using namespace std;

const int ms = 1e6 + 20;

int dp[ms];

int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  dp[n] = 0;
  dp[n - 1] = (a[n - 1] != b[n - 1] ? 1 : 0);
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = (a[i] != b[i] ? 1 : 0) + dp[i + 1];
    if (a[i] != a[i + 1] and a[i] != b[i] and a[i + 1] != b[i + 1]) {
      dp[i] = min(dp[i], 1 + dp[i + 2]);
    }
  }
  cout << dp[0] << endl;
}
