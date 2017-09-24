#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;
int n;
ll v[3], a[111111];
ll memo[4][111111];
int mk[4][111111];

ll dp(int x, int y) {
  if (x == 3)
    return 0;
  if (y == n-1) {
    return v[x] * a[y] + dp(x+1, y); 
  }
  ll &ans = memo[x][y];
  if (mk[x][y]) {
    return ans;
  }
  mk[x][y] = 1;
  ans = v[x] * a[y] + dp(x+1, y);
  ans = max(ans, dp(x, y+1));
  return ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  cin >> n;
  fr(i, 0, 3)
    cin >> v[i];
  fr(i, 0, n) {
    cin >> a[i];
  }
  cout << dp(0, 0) << endl;
}