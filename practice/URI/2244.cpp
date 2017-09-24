#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
using namespace std;
typedef long double ld;
typedef pair<ld, ld> pld;
const ld inf = 1e20;

struct Line {
  ld a, b;
  int id;
  Line(){}
  Line(ld a, ld b):a(a), b(b){}
  bool operator<(const Line &l) const {
    if (a == l.a) {
      return b < l.b;
    }
    return a < l.a;
  }
  bool operator>(const Line &l) const {
    if (a == l.a) {
      return b > l.b;
    }
    return a > l.a;
  }
  ld over(const Line& l) {
    ld den = a - l.a, num = l.b - b;
    if (den == 0)
        return inf;
    return num / den;
  }
};

vector<Line> ConvexHullTrick(const vector<Line> &C, bool comp = false) {
  vector<Line> deq(C.size());
  int back = 0;
  for(Line c : C) {

    while(back >= 2 && deq[back-1].over(deq[back-2]) >= c.over(deq[back-2])) {
      back--;
    }
    deq[back++] = c;
  }
  int front = 0;
  if (comp){
    while(front+1 < back && deq[front].b <= deq[front+1].b)
      front++;
  }
  else {
    while(front+1 < back && deq[front].b >= deq[front+1].b)
      front++;
  }
  return vector<Line>(deq.begin() + front, deq.begin() + back);
}

int main() {
  int n;
  cin >> n;
  vector<Line> H(n), C(n);
  fr(i, 0, n) {
    cin >> H[i].b >> H[i].a >> C[i].b >> C[i].a;
    H[i].id = i;
    C[i].id = i;
  }
  sort(C.begin(), C.end(), greater<Line>());
  vector<Line> hull1 = ConvexHullTrick(C);
  sort(H.begin(), H.end());
  vector<Line> hull2 = ConvexHullTrick(H, true);
  vector<pld> range1(n, pld(-1, -1)), range2(n, pld(-1, -1));
  fr(i, 0, hull1.size()) {
    // dbg(hull1[i].a _ hull1[i].b _ hull1[i].id)
    pld at(0, inf);
    if (i > 0) {
      at.first = hull1[i-1].over(hull1[i]);
    }
    if (i+1 < hull1.size()) {
      at.second = hull1[i+1].over(hull1[i]);
    }
    // dbg(hull1[i].id _ at.first _ at.second)
    range1[hull1[i].id] = at;
  }
  // dbg("")
  fr(i, 0, hull2.size()) {
    // dbg(hull2[i].a _ hull2[i].b _ hull2[i].id)
    pld at(0, inf);
    if (i > 0) {
      at.first = hull2[i-1].over(hull2[i]);
    }
    if (i+1 < hull2.size()) {
      at.second = hull2[i+1].over(hull2[i]);
    }
    // dbg(hull2[i].id _ at.first _ at.second)
    range2[hull2[i].id] = at;
  }
  int res = 0;
  fr(i, 0, n) {
    ld fs = max(range1[i].first, range2[i].first),
    sd = min(range2[i].second, range1[i].second);
    if (sd - fs > 0)
      res++;
  }
  cout << res << endl;
}