// Solver codeforces 100520C. Catalian Sequences
// O(1) each testcase
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << '\n';
#define _ << " , " <<

using namespace std;
typedef long long ll;
/*
map<ll, ll> memo;
ll get_id(int at, int last, int low, int A, ll used) {
  ll ans = 0;
  ans |= at;
  ans <<= 6;
  ans |= last;
  ans <<= 6;
  ans |= low;
  ans <<= 6;
  ans |= A;
  ans <<= 32;
  ans |= used;
  return ans;
}

inline int find(ll mask, int max_val) {
  if ((mask & ((1LL << max_val) - 1)) == 0)
    return 0;
  while(--max_val) {
    if ((mask >> max_val) & 1)
      return max_val;
  }
  return 0;
}

inline void delete_smaller(ll &mask, int low) {
  mask &= ~(1LL << low);
}

ll dp(int at, int last, int low, int A, ll used) {
  if(at == 0)
    return 1;
  ll id = get_id(at, last, low, A, used);
  if (memo.count(id)) {
    return memo[id];
  }
  ll ans = 0;
  int new_low, new_a;
  ll new_used;
  fr(i, low, A+2) {
    new_low = low;
    new_a = A;
    new_used = used;
    if (i > last) {
      new_a++;
    }
    new_used |= (1LL << i);
    new_low = max(new_low, find(used, i));
    delete_smaller(new_used, new_low);
    ans += dp(at-1, i, new_low, new_a, new_used);
  }
  return memo[id] = ans;
}*/

int main() {
  #ifndef LOCAL_TEST_LUCAS
    freopen("catalian.in", "r", stdin);
    freopen("catalian.out", "w", stdout);
  #endif
  /*fr(i, 1, 33){
    printf("v[%d] = %lld;\n", i, dp(i-1, 0, 0, 0, 0));
  }*/
  ll v[33];
  v[1] = 1;
  v[2] = 2;
  v[3] = 5;
  v[4] = 14;
  v[5] = 42;
  v[6] = 133;
  v[7] = 442;
  v[8] = 1535;
  v[9] = 5546;
  v[10] = 20754;
  v[11] = 80113;
  v[12] = 317875;
  v[13] = 1292648;
  v[14] = 5374073;
  v[15] = 22794182;
  v[16] = 98462847;
  v[17] = 432498659;
  v[18] = 1929221610;
  v[19] = 8728815103;
  v[20] = 40017844229;
  v[21] = 185727603829;
  v[22] = 871897549029;
  v[23] = 4137132922197;
  v[24] = 19828476952117;
  v[25] = 95934298966615;
  v[26] = 468291607852143;
  v[27] = 2305162065138433;
  v[28] = 11437543341740789;
  v[29] = 57178201626205353;
  v[30] = 287892071946023887;
  v[31] = 1459414167392268173;
  v[32] = 7446238508716086567;
  int n, cas = 1;
  while(cin >> n, n) {
    cout << "Case #" << cas++ << ": " << v[n] << '\n';
  }
}