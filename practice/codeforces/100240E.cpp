#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int val[6] = {100, 50, 20, 10, 5, 1};
const int basee = 2e2, ms = 2 * basee + 1000;

vector<vector<int>> ls(ms, vector<int>(ms, 150));
vector<vector<int>> cur(ms, vector<int>(ms, 150));

int main() {
 // ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int ab, bc, ca;
    cin >> ab >> bc >> ca;
    int bala = ca - ab, balb = ab - bc;
    
    vector<pair<int, int>> v;
    int freq[] = {0, 0};
    int ind[3][2];
    int base = 0;
    for (int i = 0; i < 3; i++) {
      for (int k = 0; k < 4; k++) {
        int q;
        cin >> q;
        base += q * val[k];
        for (int j = 0; j < q; j++) {
          v.emplace_back(val[k] / 10, i);
        }
      }
      cin >> ind[i][1];
      freq[1] += ind[i][1];
      cin >> ind[i][0];
      freq[0] += ind[i][0];

      base += ind[i][1] * 5;
      base += ind[i][0];
    }
    base = (base + 9) / 10;
    for(int i = 0; i < ms; i++) {
      for(int j = 0; j < ms; j++) {
        ls[i][j] = cur[i][j] = 150;
      }
    }
    
    ls[base][base] = 0;
    int lol = 0;
    for (auto &m : v) {
      lol += 1;
      for (int i = -base; i <= base; i++) {
        for (int j = -base; j <= base; j++) {
          cur[i + base][j + base] = ls[i + base][j + base];
          for (int to = 0; to < 3; to++) {
            int b[3] = {i, j, -i-j};
            b[m.second] -= m.first;
            b[to] += m.first;
            if (-base <= b[0] and b[0] <= base and -base <= b[1] and b[1] <= base) {
              cur[i + base][j + base] = min(cur[i + base][j + base], (1 + ls[b[0] + base][b[1] + base]));
            }
          }
        }
      }
      ls.swap(cur);
    }
    int ans = 1e8;
    for(int i0 = 0; i0 <= freq[0]; i0++)
    for(int j0 = 0; i0+j0 <= freq[0]; j0++)
    for(int i1 = 0; i1 <= freq[1]; i1++)
    for(int j1 = 0; i1+j1 <= freq[1]; j1++) {
      int k0 = freq[0] - i0 - j0;
      int k1 = freq[1] - i1 - j1;
      int cost = 
        (abs(i0 - ind[0][0]) + abs(j0 - ind[1][0]) + abs(k0 - ind[2][0]) + 
        abs(i1 - ind[0][1]) + abs(j1 - ind[1][1]) + abs(k1 - ind[2][1])) / 2;
      int bal0 = bala + (ind[0][0] - i0) + 5 * (ind[0][1] - i1);
      int bal1 = balb + (ind[1][0] - j0) + 5 * (ind[1][1] - j1);
      int v0 = -bal0 / 10 + base, v1 = -bal1 / 10 + base;
      if (bal0 % 10 == 0 and bal1 % 10 == 0 and 0 <= v0 and v0 < ms and 0 <= v1 and v1 < ms) {
        ans = min(ans, cost + ls[v0][v1]); 
      }
    }
    if (ans > 100) {
      cout << "impossible\n";
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}