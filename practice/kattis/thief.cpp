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
  dp[s][i] = max(dp[s - sz[i]][i-1] + val[i], dp[s][i-1])
}