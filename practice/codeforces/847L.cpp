#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
typedef unsigned int ui;
const int ms = 1001, mb = (ms + 31) / 32, mm = 32;

struct meubitset{
  ui bits[mb];
  int sz;
  meubitset(int n, bool to_set = false) {
    sz = (n + mm - 1) / mm;
    memset(bits, 0, sizeof bits);
  }

  bool operator<(const meubitset& b) const {
    int i = sz - 1;
    while(i > 0 && bits[i] == b.bits[i]) i--;
    return bits[i] < b.bits[i];
  }

  bool operator==(const meubitset& b) const {
    fr(i, 0, sz) {
      if(bits[i] != b.bits[i]) return false;
    }
    return true;
  }

  void set(int i) {
    int p = i / mb, at = i%mb;
    bits[p] |= (1 << at);
  }

  void reset() {
    memset(bits, 0, sizeof bits);
  }

  void operator^=(const meubitset& b) {
    fr(i, 0, sz) {
      bits[i] ^= b.bits[i];
    }
  }
};

map<meubitset, int> mp;
vector<int> adj[ms];
int vis[ms];

int getint(const string &s, int &i) {
  int ans = 0;
  while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
    ans *= 10;
    ans += s[i] - '0';
    i++;
  }
  ++i;
  return ans;
}

bool dfs(int u, int p) {
  vis[u] = 1;
  bool ans = true;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    if (vis[v])
      return false;
    ans = ans && dfs(v, u);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  string s;
  bool posible = true;
  meubitset ones(n, true), aux(n);
  fr(i, 0, n) {
    ones.set(i);
  }
  cin.ignore();
  fr(u, 0, n) {
    getline(cin, s);
    int i = 0;
    while(i < s.size()) {
      int sz = getint(s, i);
      aux.reset();
      fr(k, 0, sz) {
        int v = getint(s, i);
        v--;
        aux.set(v);
        // dbg(i _ u _ v)
      }
      if (mp.count(aux)) {
        int v = mp[aux];
        if (v == -1 || v == u) {
          puts("-1");
          return 0;
        }
        // dbg("add" _ u _ v)
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[aux] = -1;
      }
      aux ^= ones;
      // dbg(aux.bits[0] _ u _ "aha")
      if (mp.count(aux)) {
        puts("-1");
        return 0;
      }
      mp[aux] = u;
    }
  }

  bool ans = dfs(0, 0);
  fr(i, 0, n) {
    if (!vis[i]) {
      ans = false;
    }
  }
  if (!ans) {
    puts("-1");
    return 0;
  }
  cout << n - 1 << endl;
  fr(i, 0, n) {
    for(int u : adj[i]) {
      if (u < i) {
        cout << i + 1 << ' ' << u + 1<< endl;
      }
    }
  }
}