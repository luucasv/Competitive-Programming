#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

ll memo[1 << 10][66][2][2][11];
int mark[1 << 10][66][2][2][11], step;
ll num[66];
int b;

ll count(int mask, int p, int q, int fs) {
  if (p == 0) {
    return mask == 0 ? 1 : 0;
  }
  ll &ans = memo[mask][p][q][fs][b];
  int &mk = mark[mask][p][q][fs][b];
  if (mk == step || (mk > 0 && q == 1))
    return ans;
  mk = step;
  ans = 0;
  int popcnt = __builtin_popcount(mask);
  if (popcnt > p) {
    return 0;
  }
  if ((popcnt&1) != (p&1)) {
    return 0;
  }
  int k = num[p-1];
  int ma = q ? (b-1) : (k);
  int nm, nq;
  fr(i, fs, ma+1) {
    nm = mask ^ (1 << i), nq = q;
    if (i < k)
      nq = 1;
    ans += count(nm, p-1, nq, 0);
  }
  return ans;
}

ll solve(ll x) {
  ++step;
  int sz = 0;
  ll cp = x;
  while(cp > 0) {
    num[sz++] = cp % b;
    cp /= b;
  }
  ll ans = 0;
  fr(i, 1, sz+1) {
    ans += count(0, i, i < sz ? 1 : 0, 1);
  }
  return ans;
}

int main() {
  int q;
  cin >> q;
  ll l, r;
  fr(i, 0, q) {
    scanf("%d %lld %lld", &b, &l, &r);
    --l;
    printf("%lld\n", solve(r) - solve(l));
  }
}