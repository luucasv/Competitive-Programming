#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 20;

int cnt[10];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  int ans = min(cnt[2], cnt[1]);
  cnt[1] -= ans;
  ans += cnt[1] / 3;
  cout << ans << endl;
}