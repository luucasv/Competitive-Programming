#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

int a[ms], cnt[ms], seen[ms];

int main() {
  int n;
  cin >> n;
  int q = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) q++;
  }
  long long ans = 0;
  for (int i = n - 1; i > -1; i--) {
    cnt[a[i]]--;
    if (cnt[a[i]] == 0) q--;
    if (!seen[a[i]]) {
      ans += q;
    }
    seen[a[i]] = 1;
  }
  cout << ans << endl;
}