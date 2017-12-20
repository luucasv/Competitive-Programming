#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 20;
int v[ms];
int cnt[ms];

int main() {
  int n;
  cin >> n;
  int ma = 0, ma2 = 0;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
    if (v[i] > v[ma]) {
      ma2 = ma;
      ma = i;
      cnt[i]--;
      tot++;
      // cout << ">>>> tot " << i << " " << ma << ' ' << ma2 << ' ' << cnt[i] << '\n';
    } else if (v[i] > v[ma2]) {
      cnt[ma]++;
      ma2 = i;
      // cout << ">>>> pat " << i << " " << ma << ' ' << ma2 << ' ' << cnt[ma2] << '\n';
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, cnt[i] + tot);
  }
  cout << ans << endl;
  return 0;
}