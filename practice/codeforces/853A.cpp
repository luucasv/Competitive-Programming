/*
  Codeforces: 853A. Planning
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int c[311111];

int main(){
  int n, k;
  cin >> n >> k;
  fr(i, 0, n) {
    cin >> c[i];
  }
  priority_queue<ii> hp;
  fr(i, 0, k) {
    hp.push(ii(c[i], i));
  }
  vector<int> v(n);
  ll ans = 0;
  fr(i, k, n+k) {
    if (i < n) {
      hp.push(ii(c[i], i));
    }
    ii tp = hp.top();
    hp.pop();
    ans += ll(tp.first) * (i -  tp.second);
    v[tp.second] = i;
  }
  cout << ans << endl;
  for (int i : v) {
    cout << i+1 << ' ';
  }
  cout << endl;
  return 0;
}