#include <bits/stdc++.h>

using namespace std;

bool can(string s, int i, int p) {
  for (int c = s[i] - 'a' + 1; c < p; c++) {
    s[i] = c + 'a';
    if (i and s[i - 1] == s[i]) {
      continue;
    }
    if (i - 2 >= 0 and s[i - 2] == s[i]) {
      continue;
    }
    return 1;
  }
  return 0;
}

string get(string s, int i, int p) {
  for (int c = s[i] - 'a' + 1; c < p; c++) {
    s[i] = c + 'a';
    if (i and s[i - 1] == s[i]) {
      continue;
    }
    if (i - 2 >= 0 and s[i - 2] == s[i]) {
      continue;
    }
    for (int j = i + 1; j < s.size(); j++) {
      for (int c = 0; c < p; c++) {
        if (s[j - 1] == c + 'a') continue;
        if (j - 2 >= 0 and s[j - 2] == c + 'a') continue;
        s[j] = c + 'a';
        break;
      }
    }
    return s;
  }
  assert(false);
}

int main() {
  int n, p;
  string s;
  cin >> n >> p >> s;
  for (int i = n - 1; i > -1; i--) {
    if (can(s, i, p)) {
      cout << get(s, i, p) << endl;
      return 0;
    }
  }
  puts("NO");
}