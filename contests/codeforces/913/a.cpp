#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= 31) {
    cout << m << '\n';
  } else {
    cout << m % (1 << n) << '\n';
  }
  return 0;
}