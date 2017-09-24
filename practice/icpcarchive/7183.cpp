/*
  Solving icpc archive 7183 Too rich
  O(?)
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int val[] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
const int ms = 10, inf = 1e9 + 7;

int c[ms];
map<ii, int> memo;

int lcm(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 200 && b == 500) {
    return 5 * 2 * 100;
  } else if (a == 20 && b == 50) {
    return 5 * 2 * 10;
  } else {
    return b;
  }
}

int solve(int at, int cost) {
  if (cost == 0) {
    return 0;
  }
  if (at == ms) {
    return -inf;
  }
  if (cost % val[at] != 0) {
    return -inf;
  }
  int ans = -inf;
  if (ll(c[at]) * val[at] >= cost) {
    int q = cost / val[at];
    ans =  q + solve(at+1, cost - q * val[at]);
  }
  fr(i, at+1, 10) {
    int need = cost % val[i];
    if (need % val[at] != 0 || need / val[at] > c[at]) {
      continue;
    }
    int cneed = need / val[at];
    int par = lcm(val[at], val[i]);
    int k = min((cost - need) / par, (c[at] - cneed) / (par / val[at]));
    k *= (par / val[at]);
    ans = max(ans, k + cneed + solve(at+1, cost - (k + cneed) * val[at]));
  }
  return memo[ii(at, cost)] = ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int p;
    scanf("%d", &p);
    fr(i, 0, 10) {
      scanf("%d", c + i);
    }
    memo.clear();
    int ans = solve(0, p);
    if (ans < 0)
      ans = -1;
    printf("%d\n", ans);
  }
}

