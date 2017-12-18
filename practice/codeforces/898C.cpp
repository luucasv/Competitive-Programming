#include <bits/stdc++.h>

using namespace std;

int trie[1000000][15];
int mk[1000000];
int z, step;

bool add(string s) {
  reverse(s.begin(), s.end());
  int cur = 0;
  for (char ch : s) {
    int id = ch - '0';
    if (trie[cur][id] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      trie[cur][id] = z++;
    }
    mk[cur] = step;
    cur = trie[cur][id];
  }
  int ls = mk[cur];
  mk[cur] = step;
  return ls != step;
}

int main() {
  map<string, vector<string>> mp;
  int n;
  cin >> n;
  string s, nb;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int q;
    cin >> q;
    while(q--) {
      cin >> nb;
      mp[s].push_back(nb);
    }
  }

  cout << mp.size() << endl;
  for (auto &it : mp) {
    memset(trie[0], -1, sizeof trie[0]);
    z = 1;
    step++;
    sort(it.second.begin(), it.second.end(), [](const string &a, const string &b){
      return a.size() > b.size();
    });

    vector<string> ans;
    for (const auto &s : it.second) {
      if (add(s)) ans.push_back(s);
    }

    cout << it.first << ' ' << ans.size();
    for (const auto &s : ans) {
      cout << ' ' << s;
    }
    cout << '\n';
  }
}
