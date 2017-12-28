#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 30;
char s[ms];
bool canbe[400];
int mk[400];

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int total = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    canbe[i] = 1;
    total++;
  }
  for (int aha = 1; aha < n; aha++) {
    char ch;
    scanf(" %c %s", &ch, s);
    if (ch == '!') {
      if (total == 1) {
        ans++;
      } else {
        for (int i = 0; s[i]; i++) {
          mk[s[i]] = aha;
        }
        for (int i = 'a'; i <= 'z'; i++) {
          if (mk[i] != aha && canbe[i]) {
            canbe[i] = 0;
            total--;
          }
        }
      }
    } else if (ch == '?') {
      if (total == 1) {
        ans++;
      } else {
        if (canbe[s[0]]) total--;
        canbe[s[0]] = 0;
      }
    } else {
      if (total != 1) {
        for (int i = 0; s[i]; i++) {
          mk[s[i]] = aha;
        }
        for (int i = 'a'; i <= 'z'; i++) {
          if (canbe[i] && mk[i] == aha) {
            canbe[i] = 0;
            total--;
          }
        }
      }
    }
  }
  cout << ans << endl;
}