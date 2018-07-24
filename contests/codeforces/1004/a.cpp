#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

int a[ms];

int main() {
  int n, d;
  cin >> n >> d; 
  d *= 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 2;
  for (int i = 0; i + 1 < n; i++) {
    int df = a[i + 1] - a[i];
    if (df == d) ans++;
    else if (df > d) ans += 2;
  }
  cout << ans << endl;
}