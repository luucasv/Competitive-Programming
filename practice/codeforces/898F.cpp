#include <bits/stdc++.h>

using namespace std;
typedef long long ull;

const int ms = 1e6 + 40;
const ull base = 10, mod = 1e9 + 21;
char s[ms], ans[ms];
ull hashh[ms], pot[ms];

inline ull sub_hash(int i, int sz) {
  return ((hashh[i + sz] - hashh[i] * pot[sz]) % mod + mod) % mod;
}

inline bool check(int a, int b, int c) {
  int carry = 0;
  int sz = max(a, b);
  for (int i = 0; i < sz; i++) {
    int va = i < a ? s[a - i - 1] - '0' : 0;
    int vb = i < b ? s[a + b - i - 1] - '0' : 0;
    int sum = va + vb + carry;
    ans[i] = sum % 10 + '0';
    carry = sum / 10;
  }
  if (carry) ans[sz++] = carry + '0';
  if (sz != c) return false;
  for (int i = 0; i < sz; i++) {
    if (ans[sz - i - 1] != s[a + b + i]) return false;
  }
  return true;
}

inline bool can(int a, int b, int c) {
  if (a > 1 && s[0] == '0') return false;
  if (b > 1 && s[a] == '0') return false;
  if (c > 1 && s[a + b] == '0') return false;
  if (a == 0 || b == 0 || c == 0) return false;
  if (c - max(a, b) > 1 || c - max(a, b) < 0) return false;

  ull fs = sub_hash(0, a), sd = sub_hash(a, b), ed = sub_hash(a + b, c);
  if ((fs + sd) % mod != ed) return false;
  return check(a, b, c);
}

inline void show(int a, int b, int c) {
  char save = s[a];
  s[a] = 0;
  printf("%s", s);
  s[a] = save;
  save = s[a + b];
  s[a + b] = 0;
  printf("+%s", s + a);
  s[a + b] = save;
  printf("=%s\n", s + a + b);
}

int main() {
  scanf(" %s", s);
  int n = strlen(s);
  pot[0] = 1;
  for (int i = 0; i < n; i++) {
    pot[i + 1] = pot[i] * base % mod;
    hashh[i + 1] = (hashh[i] * base + ull(s[i] - '0')) % mod;
  }
  for (int a = 1; a + a + 1 <= n; a++) {
    // a + x + y = s
    // y = min(x, a)
    // y = a -> x = s - 2 * a
    // y = x -> x = (s - a) / 2
    if (can(a, n - a - a, a)) {
      show(a, n - a - a, a);
      return 0;
    }
    if (can(a, n - a - a - 1, a + 1)) {
      show(a, n - a - a - 1, a + 1);
      return 0;
    }
    int d  = (n - a) / 2;
    if (can(a, n - a - d, d)) {
      show(a, n - a - d, d);
      return 0;
    }
    if (can(a, n - a - d - 1, d + 1)) {
      show(a, n - a - d - 1, d + 1);
      return 0;
    }
  }
}
