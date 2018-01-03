#include <bits/stdc++.h>

using namespace std;

int mk[500];

int main() {
  int k;
  string s;
  cin >> k;
  cin >> s;
  int cnt = 0;
  for (auto i = 0; i < s.size(); i++) {
    if (mk[s[i]] == 0) {
      mk[s[i]] = i+1;
      cnt++;
    }
  }
  if (cnt >= k) {
    cout << "YES";
    for (auto i = 0; i < s.size(); i++) {
      if (mk[s[i]] > 0 && k > 0) {
        cout << '\n';
        mk[s[i]] = -1;
        k--;
      }
      cout << s[i];
    }
    cout << '\n';
  } else {
    puts("NO");
  }
}