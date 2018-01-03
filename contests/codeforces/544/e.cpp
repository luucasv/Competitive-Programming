#include <bits/stdc++.h>

using namespace std;

string s[30];

int memo[1 << 20];
int mat[30][30], mask[30][30], cost[30][30];
int n, m;

int dp(int msk) {
  if (msk == ((1 << n) - 1)) return 0;
  int &ans = memo[msk];
  if (ans != -1) return ans;
  ans = 1e9;
  for (int i = 0; i < n; i++) {
    if ((msk >> i) & 1) continue;
    for (int j = 0; j < m; j++) {
      ans = min(ans, mat[i][j] + dp(msk | (1 << i)));
      ans = min(ans, cost[i][j] + dp(msk | mask[i][j]));
    }
    break;
  }
  return ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int ma = 0, mmask = 0, sum = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][j] == ch) {
          mmask |= (1 << i);
          sum += mat[i][j];
          ma = max(ma, mat[i][j]);
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i][j] == ch) {
          cost[i][j] = sum - ma;
          mask[i][j] = mmask;
        }
      }
    }
  }
  cout << dp(0) << "\n";
}