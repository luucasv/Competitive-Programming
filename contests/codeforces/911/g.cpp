#include <bits/stdc++.h>

using namespace std;
const int ms = 2e5 + 200, Q = 500, mv = 110;

int rt[Q][mv];
int rep[Q][mv];
int color[Q][mv];
int a[ms];
int b[ms];

int root(int r[], int x) {
  if (r[x] == x) return x;
  return r[x] = root(r, r[x]);
}

int conn(int r[], int a, int b) {
  a = root(r, a), b = root(r, b);
  r[a] = b;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int q = 0; q < Q; q++) {
    for (int i = 0; i < mv; i++) {
      rt[q][i] = i;     // representante de i
      color[q][i] = i;  // cor do grupo representado por i
      rep[q][i] = i;    // representante da cor i
    }
  }

  int q;
  cin >> q;
  for (int aha = 0; aha < q; aha++) {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    --l, --r;
    int ql = l / Q, qr = r / Q;
    for (int i = ql + 1; i < qr; i++) {
      int rx = rep[i][x], ry = rep[i][y];
      if (rx == -1) {
        continue;
      } else if (ry == -1) {
        rep[i][y] = rx;
        color[i][rx] = y;
        rep[i][x] = -1;
      } else {
        rt[i][rx] = ry;
        rep[i][x] = -1;
        color[i][rx] = -1;
      }
    }
    for (int i = ql * Q; i < min(n, (ql + 1) * Q); i++) {
      a[i] = color[ql][root(rt[ql], a[i])];
      assert(a[i] >= 1);
    }
    for (int i = 0; i < mv; i++) {
      rt[ql][i] = i;
      color[ql][i] = i;
      rep[ql][i] = i;
    }
    for (int i = qr * Q; i < min(n, (qr + 1) * Q); i++) {
      a[i] = color[qr][root(rt[qr], a[i])];
      assert(a[i] >= 1);
    }
    for (int i = 0; i < mv; i++) {
      rt[qr][i] = i;
      color[qr][i] = i;
      rep[qr][i] = i;
    }
    for (int i = l; i < min(r + 1, (ql + 1) * Q); i++) {
      if (a[i] == x) {
        a[i] = y;
      }
    }
    if (qr != ql) {
      for (int i = qr * Q; i <= r; i++) {
        if (a[i] == x) {
          a[i] = y;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int qi = i / Q;
    a[i] = color[qi][root(rt[qi], a[i])];
    assert(a[i] >= 1);
    printf("%d ", a[i]);
  }
  puts("");
}