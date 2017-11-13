#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int main() {
  ll n;
  ll  k;
  cin >> n >> k;
  vector<int> v(n);
  fr(i, 0, n) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  --k;
  int i = 0;
  while(i < n) {
    int j = i;
    while(j < n && v[j] == v[i]) j++;
    ll q = j - i;
    if (k - q*n >= 0) {
      k -= q*n;
    } else {
      cout << v[i] << ' ' << v[k / q] << '\n';
      return 0;
    }
    i = j;
  }
}