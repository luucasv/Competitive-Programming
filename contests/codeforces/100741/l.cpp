#include <bits/stdc++.h>
using namespace std;

int a[20], b[20];
map<int, int> mp;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 1; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sum += a[j];
      }
    }
    mp[sum]++;
  }
  long long ans = 0;
  for (int i = 1; i < (1 << m); i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        sum += b[j];
      }
    }
    ans += mp[sum];
  }
  cout << ans << endl;
}