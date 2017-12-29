#include <bits/stdc++.h>

using namespace std;

int a[111111];

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int x = 0;
  for (int i = 1; i < n; i++) {
    int cur = min(a / i, b / (n - i));
    x = max(x, cur);
  }
  cout << x << endl;
}