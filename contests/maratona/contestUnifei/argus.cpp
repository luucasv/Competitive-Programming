#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define N first
#define P second
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int ms = 1e7 + 310;

int n;
int ans[ms];
ii v[ms];

ll can(int t) {
  ll sum = 0;
  fr(i, 0, n) {
    sum += t / v[i].P;
  }
  return sum;
}

int main() {
  string s;
  while(cin >> s, s != "#") {
    cin >> v[n].N >> v[n].P;
    if (v[n].P == 0) {
      return 0;
    }
    n++;
    if (n > ms) {
      return 0;
    }
  }
  sort(v, v+n);
  int k;
  cin >> k;
  int lo = 1, hi = 3e7 + 500;
  while(hi - lo > 1) {
    int m = (lo + hi) / 2;
    if (can(m) >= k) {
      hi = m;
    } else {
      lo = m;
    }
  }
  if (can(lo) < k) {
    lo = hi;
  }
  int at = 0;
  fr(i, 0, n) {
    at += (lo - 1) / v[i].P;
    ans[i] = (lo - 1) / v[i].P;
  }
  fr(i, 0, n) {
    if (at == k) {
      break;
    }
    if (lo % v[i].P == 0) {
      at++;
      ans[i]++;
    }
  }
  fr(i, 0, n) {
    cout << "Register " << v[i].N << " = " << ans[i] << endl;
  }
  return 0;
}