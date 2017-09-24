/*
  Codeforces: 853B. Jury Meeting
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int mv = 3e5 + 20;
int n;
int a[mv];

bool can(ll cash) {
  ll bonus = 0;
  fr(i, 0, n) {
    if (i+1 < n && a[i+1] > a[i]) {
      ll use = min(bonus, ll(a[i]));
      if ((cash - (a[i] - use) < a[i+1] && cash >= a[i]) || 
          (cash - a[i] >= a[i+1])) {
        bonus += a[i] / 10;
        cash -= a[i];
      } else {
        bonus -= use;
        cash -= a[i] - use;
      }
    } else {
      if (cash >= a[i]) {
        bonus += a[i] / 10;
        cash -= a[i];
      } else {
        ll use = min(bonus, ll(a[i]));
        bonus -= use;
        cash -= a[i] - use;
      }
    }
    // dbg(cash _ bonus _ a[i])
    if (cash < 0) {
      return false;
    }
  }
  return cash >= 0;
}

int main(){
  cin >> n;
  ll total = 0;
  fr(i, 0, n){
    cin >> a[i];
    /*if (i > 0) {
      hasOne[i-1] = a[i] == 1000;
      hasTwo[i-1] = a[i] == 2000;
    }*/
  }
  /*for (int i = n-2; i > -1; i--) {
    hasOne[i] += hasOne[i+1];
    hasTwo[i] += hasTwo[i+1];
  }*/
  ll lo = 1, hi = n * 2000LL;
  while (hi - lo > 0) {
    ll m = (lo + hi) / 2;
    if (can(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  if (!can(lo)) {
    lo = hi;
  }
  cout << lo << endl;
  return 0;
}