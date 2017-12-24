#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5 + 30;

int n;
long long l;
char s[ms];
int trie[ms][2], z;
bool term[ms];

void add() {
  int cur = 0;
  for (int i = 0; s[i]; i++) {
    int id = s[i] - '0';
    if (trie[cur][id] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      trie[cur][id] = z++;
    }
    cur = trie[cur][id];
  }
  term[cur] = 1;
}

long long xr;

long long nimber(long long x) {
  long long ans = 1;
  if (x == 0) return 0;
  while ((x & 1) == 0) {
    ans <<= 1;
    x >>= 1;
  }
  return ans;
}

void search(int cur, int sz = 0) {
  if (term[cur]) return;
  for (int i = 0; i < 2; i++) {
    if (trie[cur][i] == -1) xr ^= nimber(l - sz);
    else search(trie[cur][i], sz + 1);
  }
}

int acc[100], mk[100], nim[100];

int main() {
  cin >> n >> l;
  memset(trie[0], -1, sizeof trie[0]);
  z = 1;
  for (int i = 0; i < n; i++) {
    scanf(" %s", s);
    add();
  }
  search(0);
  if (xr) puts("Alice");
  else puts("Bob");
  // cout << 0 << '\n';
  // int acc;
  // for (int x = 1; x < 20; x++) {
  //   memset(mk, 0, sizeof mk);
  //   acc = 0;
  //   mk[acc]++;
  //   for (int i = 1; i < x; i++) {
  //     acc ^= nim[x - i];
  //     mk[acc]++;
  //   }
  //   int n = 0;
  //   while (mk[n]) n++;
  //   nim[x] = n;
  //   cout << n << ' ' << x << '\n';
  // }
}