#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int ms = 1e5 + 20;

ii a[ms];

int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  long long ans = 0, cur_fac = 0;
  int i = 0, j = 0;
  while (j < n) {
    while (j < n && a[j].first - a[i].first < d) {
      cur_fac += a[j].second;
      j++;
    }
    ans = max(ans, cur_fac);
    cur_fac -= a[i++].second;
  }
  cout << ans << endl;
}