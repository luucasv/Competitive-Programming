#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 200;

vector<int> mp[300];
int st[300], ed[300];
int bit[ms];

void add(int p, int v) {
  while (p < ms) {
    bit[p] += v;
    p += p & -p;
  }
}

int sum(int p) {
  int ans = 0;
  while (p > 0) {
    ans += bit[p];
    p -= p & -p;
  }
  return ans;
}

char s[ms];

int main() {
  scanf(" %s", s);
  int n = strlen(s);
  for (int i = 0; s[i]; i++) {
    mp[s[i]].push_back(i);
    add(i + 1, 1);
  }
  int cnt = 0;
  for (int i = 0; i < 300; i++) {
    if (mp[i].size() & 1) cnt++;
    st[i] = 0, ed[i] = mp[i].size() - 1;
  }
  if (cnt > 1) {
    puts("-1");
    return 0;
  }
  long long ans = 0;
  for (int i = 0; 2 * i + 1 < n; i++) {
    int ml = 1, mr = 0, mdist = 1e8;
    char ch;
    for (int j = 0; j < 300; j++) {
      int sz = ed[j] - st[j] + 1;
      if (sz > 1){
        int l = mp[j][st[j]], r = mp[j][ed[j]];
        int ll = sum(l), rr = sum(r);
        int dist = ll + n - 2 * i - rr - 1;
        if (dist < mdist) {
          mr = r, ml = l;
          mdist = dist;
          ch = j;
        }
      }
    }
    add(ml + 1, -1);
    add(mr + 1, -1);
    st[ch]++;
    ed[ch]--;
    ans += mdist;
  }
  cout << ans << endl;
  return 0;
}