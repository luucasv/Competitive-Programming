#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (char c : s) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      ans++;
    }
    if (c >= '0' && c <= '9') {
      c -= '0';
      if (c & 1) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}