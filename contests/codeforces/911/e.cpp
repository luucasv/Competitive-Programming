#include <bits/stdc++.h>

using namespace std;
const int ms = 2e5 + 200;

int a[ms];
int b[ms];

int main() {
  int n, k;
  cin >> n >> k;
  set<int> st;
  for (int i = 1; i <= n; i++) st.insert(i);
  for (int i = 0; i < k; i++) {
    scanf("%d", a + i);
    st.erase(a[i]);
  }
  int at = 0;
  stack<int> p;
  int cur = 1;
  bool ok = 1;
  while (at < k) {
    while (at < k && ok && a[at] != cur) {
      if (p.empty() || a[at] < p.top()) {
        p.push(a[at]);
      } else {
        ok = 0;
      }
      at++;
    }
    if (!ok) {
      break;
    }
    if (at < k) {
      cur++;
      at++;
      while (!p.empty() && p.top() == cur) {
        cur++;
        p.pop();
      }
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  while (at < n) {
    int mn = n + 1;
    if (!p.empty()) {
      mn = p.top();
    }
    assert(st.lower_bound(mn) != st.begin());
    auto it = prev(st.upper_bound(mn));
    a[at] = *it;
    p.push(a[at]);
    at++;
    while (!p.empty() && p.top() == cur) {
      cur++;
      p.pop();
    }
    st.erase(it);
  }
  printf("%d", a[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", a[i]);
  }
  puts("");
}