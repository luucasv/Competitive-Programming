#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  long long x, y, z;
  cin >> a >> b >> x >> y >> z;
  a -= 2 * x;
  a -= y;
  b -= y;
  b -= 3 * z;
  cout << max(0LL, -a) + max(0LL, -b) << '\n';
}