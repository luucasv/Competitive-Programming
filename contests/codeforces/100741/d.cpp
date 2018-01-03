#include <bits/stdc++.h>
using namespace std;

int main() {
  int xr = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    xr ^= a;
  }
  cout << xr << '\n';
}