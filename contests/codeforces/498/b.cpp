#include <bits/stdc++.h>

using namespace std;

const int ms = 5e3 + 200;

int p[ms];
int q[ms];

int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", p + i, q + i);
  }
  vector<long double> ls(t + 20, 0), cur(t + 20, 0);
  for (int i = n - 1; i > -1; i--) {
    if (p[i] == 100 or q[i] == 1) {
      for (int tt = 0; tt < t; tt++) {
        cur[tt] = 1 + ls[tt + 1];
      }
    } else {
      int tt;
      long double pp = p[i] / 100.0L, sum = 0, pot = 1;
      for (tt = t - 1; tt + q[i] > t; tt--) {
        sum *= (1 - pp);
        sum += pp * (1 + ls[tt + 1]);
        cur[tt] = sum;
        pot *= (1 - pp);
      }
      for(; tt > -1; tt--) {
        sum *= (1 - pp);
        sum += pp * (1 + ls[tt + 1]);
        sum -= pot * pp * (1 + ls[tt + q[i]]);
        cur[tt] = sum + pot * (1 + ls[tt + q[i]]);
      }
    }
    cur.swap(ls);
  }
  cout << fixed << setprecision(10) << ls[0] << endl;
}
