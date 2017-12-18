#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __  = c; a < __; a++)

using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  fr(i, 0, s.size()) {
    if (s[i] != 'Q') continue;
    fr(j, i + 1, s.size()) {
      if (s[j] != 'A') continue;
      fr(k, j + 1, s.size()) {
        if (s[k] == 'Q') ans++;
      }
    }
  }
  cout << ans << endl;
}