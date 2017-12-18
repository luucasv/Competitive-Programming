#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

int main() {
  int n;
  int e1, e2;
  cin >> n >> e1 >> e2;
  vector<ii> v;
  fr(i, 0, n) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }
  int ans = 0;
  fr(a, 0, 2) {
    fr(b, 0, 2) {
      int cnt = 0;
      fr(i, 0, n) {
        bool ok = false;
        if (e1 <= v[i].first) {
          ok = ok || (a == 1 && (v[i].first < v[i].second));
        }
        if (e1 >= v[i].first) {
          ok = ok || (a == 0 && (v[i].first > v[i].second));
        }
        if (e2 <= v[i].first) {
          ok = ok || (b == 1 && (v[i].first < v[i].second));
        }
        if (e2 >= v[i].first) {
          ok = ok || (b == 0 && (v[i].first > v[i].second));
        }
        cnt += (ok ? 1 : 0);
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
}