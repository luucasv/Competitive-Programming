#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int ms = 2e5 + 20;

int bit[ms];

int add(int p, int v) {
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

map<char, set<int>> mp;

int n, m;
int get_id(int i) {
  int lo = 1, hi = n;
  while (hi - lo > 0) {
    int md = (lo + hi) / 2;
    if (sum(md) < i) {
      lo = md + 1;
    } else {
      hi = md;
    }
  }
  return hi;
}

void del(char c, int l, int r) {
  auto st = mp[c].lower_bound(l), ed = mp[c].upper_bound(r);
  for (auto it = st; it != ed; it++) {
    add(*it, -1);
  }
  mp[c].erase(st, ed);
}

int main() {
  string s;
  cin >> n >> m;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    mp[s[i-1]].insert(i);
    add(i, 1);
  }
  for (int q = 0; q < m; q++) {
    int l, r;
    char c;
    scanf("%d %d %c", &l, &r, &c);
    l = get_id(l);
    r = get_id(r);
    del(c, l, r);
  }
  vector<ii> ans;
  for (auto it : mp) {
    for (int i : it.second) {
      ans.emplace_back(i, it.first);
    }
  }
  sort(ans.begin(), ans.end());
  for (auto it : ans) {
    cout << (char) it.second;
  }
  cout << '\n';
}