#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5;
int p[ms];

int main() {
  int  q, k;
  double s;
  cin >> s >> q >> k;
  for (int i = 0; i < q; i++) {
    scanf("%d", p + i);
  }
  sort(p, p + q);
  for (int i = 0; i < q; i++) {
    if (s * p[i] / 100.0 > k) {
      s += s * p[i] / 100.0;
    } else {
      s += k;
    }
  }
  cout << setprecision(10) << fixed << s << '\n';
}
