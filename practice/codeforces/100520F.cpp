// Solver codeforces 100520F. Flights 
// O(m * log(m)) each testcase
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << '\n';
#define _ << " , " <<

using namespace std;

struct Vertex {
  int to_one_edge;
  int sum;
  Vertex():sum(0){}
  bool operator<(const Vertex &v) const {
    return sum < v.sum;
  }
};

int main() {
  #ifndef LOCAL_TEST_LUCAS
    freopen("flights.in", "r", stdin);
    freopen("flights.out", "w", stdout);
  #endif
  int n, m;
  while (cin >> n >> m, n + m) {
    vector<Vertex> v(n-1);
    vector<int> ans(m, 0);

    int at = 1;
    fr(i, 0, m) {
      int a, b;
      cin >> a >> b;
      a -= 2;
      b -= 2;
      if (a == -1) {
        v[b].to_one_edge = i;
      } else if (b == -1) {
        v[a].to_one_edge = i;
      } else {
        v[a].sum += at;
        v[b].sum += at;
        ans[i] = at;
        at++;
      }
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
      ans[i.to_one_edge] = at++;
    }
    puts("Yes");
    fr(i, 0, m) {
      printf("%d%c", ans[i], i+1 < m ? ' ' : '\n');
    }
  }
}