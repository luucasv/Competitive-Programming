#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

struct PT {
  ll x, y;

  PT(ll x = 0, ll y = 0) :x(x), y(y) {}

  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  ll operator%(const PT &p) const { return x * p.y - y * p.x; }
  ld operator!() const { return hypot(x, y); }
};

PT le[1111], ri[1111];
PT pts[1111];
int n;

int q(PT p) {
  if (p.x >= 0 and p.y >= 0) return 0;
  if (p.x < 0 and p.y >= 0) return 1;
  if (p.x < 0 and p.y < 0) return 2;
  return 3;
}

PT base;

bool cmp(pair<PT, int> a, pair<PT, int> b) {
  PT v1 = a.first - base, v2 = b.first - base;
  int q1 = q(v1), q2 = q(v2);
  if (q1 != q2) return q1 < q2;
  return v1 % v2 > 0;
}

int den[1111];
ld num[1111];
pair<PT, int> aux[1111];

ld calc(int id) {
  int q = 0;
  for (int i = 0; i < n; i++) {
    if (i == id) continue;
    aux[q++] = {pts[i], i};
  }
  base = pts[id];
  sort(aux, aux + q, cmp);
  for (int i = 0; i < q; i++) aux[i + q] = aux[i];
  for (int i = 0; i < q; i++) {
    int ls = 0, rs = 0;
    for (int j = i + 1; j < i + q; j++) {
      ll cross = (pts[id] - aux[i].first) % (aux[j].first - aux[i].first);
      if (cross > 0) {
        le[ls++] = aux[j].first;
      } else if (cross < 0) {
        ri[rs++] = aux[j].first;
      }
    }
    ll q = 0;
    for (int l = 0, r = 0; l < ls; l++) {
      while (r < rs and (pts[id] - le[l]) % (ri[r] - le[l]) <= 0) r++;
      q += rs - r;
    }
    den[aux[i].second] += q;
    num[aux[i].second] += !(pts[id] - aux[i].first) * q;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    pts[i] = PT(x, y);
  }
  for (int i = 0; i < n; i++) {
    calc(i);
  }
  for (int i = 0; i < n; i++) {
    if (den[i] == 0) puts("-1");
    else printf("%.10lf\n", num[i] / den[i]);
  }
}
