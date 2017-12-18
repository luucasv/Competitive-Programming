#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __  = c; a < __; a++)

using namespace std;
typedef long long ll;

const int ms = 1111;

int s[ms];

int main() {
  int m;
  cin >> m;
  int ok = 1;
  fr(i, 0, m) {
    cin >> s[i];
    if (s[i] % s[0] != 0) {
      ok = 0;
    }
  }
  if (!ok) {
    puts("-1");
  } else {
    cout << 2 * m - 1 << endl;
    cout << s[0];
    fr(i, 1, m) {
      cout << " " << s[0] << " " << s[i];
    }
    cout << endl;
  }
}
