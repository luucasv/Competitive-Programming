#include <bits/stdc++.h>

using namespace std;
const int ms = 1.5e3 + 20;

int a[ms];
char st[20 * ms * ms];
char sz[20 * ms * ms];
char lazy[20 * ms * ms];
void build(int id, int x1, int x2, int y1, int y2) {
  if (x1 == x2 && y1 == y2) {
    if (x1 < y1) {
      st[id] = a[x1] > a[y1];
      sz[id] = 1;
    } else {
      st[id] = 0;
      sz[id] = 0;
    }
  } else if (x1 == x2) {
    int m = (y1 + y2) / 2;
    build(4 * id, x1, x2, y1, m);
    build(4 * id + 1, x1, x2, m + 1, y2);
    st[id] = st[4 * id] + st[4 * id + 1];
    sz[id] = sz[4 * id] + sz[4 * id + 1];
  } else if (y1 == y2) {
    int m = (x1 + x2) / 2;
    build(4 * id + 2, x1, m, y1, y2);
    build(4 * id + 3, m + 1, x2, y1, y2);
    st[id] = st[4 * id + 2] + st[4 * id + 3];
    sz[id] = sz[4 * id + 2] + sz[4 * id + 3];
  } else {
    int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
    build(4 * id    , x1, mx, y1, my);
    build(4 * id + 1, x1, mx, my + 1, y2);
    build(4 * id + 2, mx + 1, x2, y1, my);
    build(4 * id + 3, mx + 1, x2, my + 1, y2);
    st[id] = st[4 * id] + st[4 * id + 1] + st[4 * id + 2] + st[4 * id + 3];
    sz[id] = sz[4 * id] + sz[4 * id + 1] + sz[4 * id + 2] + sz[4 * id + 3];
  }
  st[id] &= 1;
  sz[id] &= 1;
}

void updt(int id, int x1, int x2, int y1, int y2, int l1, int l2, int r1, int r2) {
  if (lazy[id]) {
    if (x1 == x2 && y1 == y2) {
      st[id] = sz[id] - st[id];
    } else {
      st[id] = sz[id] - st[id];
      for (int i = 0; i < 4; i++) {
        lazy[4 * id + i] = !lazy[4 * id + i];
      }
    }
    st[id] &= 1;
    lazy[id] = 0;
  }
  if (l1 <= x1 && x2 <= l2 && r1 <= y1 && y2 <= r2) {
    st[id] = sz[id] - st[id];
    st[id] &= 1;
    for (int i = 0; i < 4; i++) {
      lazy[4 * id + i] = !lazy[4 * id + i];
    }
    return;
  }
  if (x2 < l1 || x1 > l2 || y2 < r1 || y1 > r2) {
    return;
  }
  if (x1 == x2) {
    int m = (y1 + y2) / 2;
    updt(4 * id, x1, x2, y1, m, l1, l2, r1, r2);
    updt(4 * id + 1, x1, x2, m + 1, y2, l1, l2, r1, r2);
    st[id] = st[4 * id] + st[4 * id + 1];
  } else if (y1 == y2) {
    int m = (x1 + x2) / 2;
    updt(4 * id + 2, x1, m, y1, y2, l1, l2, r1, r2);
    updt(4 * id + 3, m + 1, x2, y1, y2, l1, l2, r1, r2);
    st[id] = st[4 * id + 2] + st[4 * id + 3];
  } else {
    int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
    updt(4 * id, x1, mx, y1, my, l1, l2, r1, r2);
    updt(4 * id + 1, x1, mx, my + 1, y2, l1, l2, r1, r2);
    updt(4 * id + 2, mx + 1, x2, y1, my, l1, l2, r1, r2);
    updt(4 * id + 3, mx + 1, x2, my + 1, y2, l1, l2, r1, r2);
    st[id] = st[4 * id] + st[4 * id + 1] + st[4 * id + 2] + st[4 * id + 3];
  }
  st[id] &= 1;
}

int main() {
  int n;
  cin >> n;
  int t = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) t = 1 - t;
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int sz = ((r - l + 1) * (r - l) / 2)&1;
    t = (t + sz)&1;
    if (t) {
      puts("odd");
    } else {
      puts("even");
    }
  }
}