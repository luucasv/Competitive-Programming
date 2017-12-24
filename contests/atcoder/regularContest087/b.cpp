#include <bits/stdc++.h>
using namespace std;

const int ms = 8009;

vector<int> d[2];
char memo[2][ms][2 * ms];

char dp(int at, int i, int pos) {
  if (i == d[at].size())
    return pos == ms;
  char &ans = memo[at][i][pos];
  if (ans != -1) return ans;
  return ans = dp(at, i + 1, pos + d[at][i]) || dp(at, i + 1, pos - d[at][i]);
}

int main() {
  memset(memo, -1, sizeof memo);

  string s;
  int x, y;
  cin >> s >> x >> y;
  int i = 0;
  while (i < s.size() && s[i] == 'F') i++, --x;

  int at = 0;
  while (i < s.size()) {
    while (i < s.size() && s[i] == 'T') {
      at = 1 - at;
      i++;
    }

    int cnt = 0;
    while (i < s.size() && s[i] == 'F') {
      cnt++;
      i++;
    }
    if (cnt) d[at].push_back(cnt);
  }
  if (dp(0, 0, ms + x) && dp(1, 0, ms + y)) {
    puts("Yes");
  } else {
    puts("No");
  }
}