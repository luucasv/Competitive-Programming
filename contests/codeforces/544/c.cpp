#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ms = 511;

int a[ms];
ll memo[2][ms][ms];

ll mod;
int n, m, b;

int main() {
  cin >> n >> m >> b >> mod;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int at = 0;
  for (int i = 0; i < n; i++) {
    for (int k = b; k > -1; k--) {
      memo[0][i][k] = 1;
    }
  }
  for (int c = 1; c <= m; c++) {
    at = 1 - at;
    for (int i = n - 1; i > -1; i--) {
      for (int k = b; k > -1; k--) {
        memo[at][i][k] = 0;
        if (k >= a[i]) memo[at][i][k] += memo[1 - at][i][k - a[i]];
        if (i + 1 < n) memo[at][i][k] += memo[at][i + 1][k];
        memo[at][i][k] %= mod;
      }
    }
  }
  cout << memo[at][0][b] << '\n';
}