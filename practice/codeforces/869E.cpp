#include <bits/stdc++.h>

using namespace std;

const int ms = 2.5e3 + 20;

typedef long long ll;

ll bit[ms][ms];
ll vals[ms][ms];

void update(int x, int y, ll v) {
  x += 2;
  y += 2;
  for (; x < ms; x += (x & -x)) {
    for (int yy = y; yy < ms; yy += (yy & -yy)) {
      bit[x][yy] ^= v;
    }
  }
}

ll query(int x, int y) {
  x += 2;
  y += 2;
  ll ans = 0;
  for (; x > 0; x -= (x & -x)) {
    for (int yy = y; yy > 0; yy -= (yy & -yy)) {
      ans ^= bit[x][yy];
    }
  }
  return ans;
}

void update(int x1, int y1, int x2, int y2, ll val) {
  update(x1, y1, val);
  update(x1, y2 + 1, val);
  update(x2 + 1, y1, val);
  update(x2+1, y2+1, val);
} 

int main() {
  srand(time(NULL));
  int n, m, q;
  cin >> n >> m >> q;
  while (q--) {
    int t, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
    if (t == 1) {
      ll val = rand();
      val <<= 16;
      val ^= rand();
      val <<= 16;
      vals[x1][y1] = val;
      update(x1, y1, x2, y2, val);
    } else if (t == 2) {
      update(x1, y1, x2, y2, vals[x1][y1]);
    } else {
      puts(query(x1, y1) == query(x2, y2) ? "Yes" : "No");
    }
  }
}
