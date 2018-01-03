#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5 + 20;

map<string, int> mp;

int get_id(string v) {
  if (!mp.count(v)) {
    int i = mp.size();
    mp[v] = i;
  }
  return mp[v];
}

char s[30];
char w[ms][30];
vector<int> g[ms];
int mk[ms];
vector<string> ans;

void solve(int at) {
  mk[at] = 1;
  for (auto id : g[at]) {
    if (!mk[id]) {
      solve(id);
    }
  }
  ans.emplace_back(w[at]);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf(" def %s", s);
    int f = get_id(s);
    assert(f == i);
    string ss;
    while (scanf(" %s", s), ss = string(s), ss != "=") {
      scanf(" %s", s);
      g[f].push_back(get_id(s));
      assert(get_id(s) < f);
    }
    reverse(g[f].begin(), g[f].end());
    scanf(" %s", w[f]);
  }
  string ss;
  cin >> ss;
  solve(get_id(ss));
  reverse(ans.begin(), ans.end());
  for (auto it : ans) {
    cout << it << ' ';
  }
  puts("");
}