#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int i = 0, j = 0, ans = 1;
  int n = s.size();
  while (j < n) {
    while (j < n && s[i] == s[j]) j++;
    ans = max(ans, j - i + min(i, n - j));
    i = j;
  }
  cout << ans << endl;
  return 0;
}