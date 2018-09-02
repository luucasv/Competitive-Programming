#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int p = 1, ans = 0;
  while (p < n) {
    n -= p;
    p *= 2;
    ans++;
  }
  cout << ans + 1 << endl;
}
