/*
  Solving icpc archive 2755
  O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll BASE = 13, mod[3] = {ll(1e9+7), ll(1e9+9), ll(1e9+27)};
map<iii, int> cnt;
string num[71111];


int main() {
  int n;
  cin >> n;
  fr(k, 0, n){
    cin >> num[k];
    set<iii> st;
    fr(i, 0, 9) {
      ll h[3] = {0, 0};
      fr(j, i, 9) {
        fr(o, 0, 3) {
          h[o] = h[o] * BASE + (num[k][j] - '0' + 1);
          h[o] %= mod[o];
        }
        iii at = iii(h[0], ii(h[1], h[2]));
        if(!st.count(at)){
          cnt[at]++;
          st.insert(at);
        }
      }
    }
  }
  fr(k, 0, n){
    int ia = 0, ja = num[k].size() - 1;
    fr(i, 0, 9) {
      ll h[3] = {0, 0};
      fr(j, i, 9) {
        fr(o, 0, 3) {
          h[o] = h[o] * BASE + (num[k][j] - '0' + 1);
          h[o] %= mod[o];
        }
        iii at = iii(h[0], ii(h[1], h[2]));
        if (cnt[at] == 1 && ja - ia > j - i) {
          ja = j;
          ia = i;
        }
      }
    }
    cout << num[k].substr(ia, ja-ia+1) << endl;
  }
}

