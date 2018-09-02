#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 20;

set<int> adj[ms];
int a[ms];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  vector<int> last(1, 0);
  bool ok = a[0] == 0; 
  int at = 1;
  while (ok && at < n) {
    vector<int> cur;
    for (auto u : last) {
      for (int k = u != 0; k < adj[u].size() && ok; k++) {
        if (!adj[u].count(a[at])) {
          ok = false;
        } else {
          cur.push_back(a[at++]);
        }
      }
      if (!ok) break;
    }
    last.swap(cur);
  }
  ok = ok && at == n;
  puts(ok ? "yes" : "no");
}
