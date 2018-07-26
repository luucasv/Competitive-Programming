#include <bits/stdc++.h>

using namespace std;

const int ms = 1e6 + 20;

char name[ms][10];
int value[ms];
vector<int> adj[ms];
vector<int> st;

void dfs1(int u) {
  if (name[u][0] == 'N') {
    dfs1(adj[u][0]);
    value[u] = 1 - value[adj[u][0]];
  } else if (name[u][0] == 'X') {
    dfs1(adj[u][0]);
    dfs1(adj[u][1]);
    value[u] = value[adj[u][0]] ^ value[adj[u][1]];
  } else if (name[u][0] == 'A') {
    dfs1(adj[u][0]);
    dfs1(adj[u][1]);
    value[u] = value[adj[u][0]] & value[adj[u][1]];
  } else if (name[u][0] == 'O') {
    dfs1(adj[u][0]);
    dfs1(adj[u][1]);
    value[u] = value[adj[u][0]] | value[adj[u][1]];
  }
}

void dfs2(int u) {
  if (name[u][0] == 'N') {
    dfs2(adj[u][0]);
  } else if (name[u][0] == 'X') {
    dfs2(adj[u][0]);
    dfs2(adj[u][1]);
  } else if (name[u][0] == 'A') {
    if (value[adj[u][1]] == 1) dfs2(adj[u][0]);
    if (value[adj[u][0]] == 1) dfs2(adj[u][1]);
  } else if (name[u][0] == 'O') {
    if (value[adj[u][1]] == 0) dfs2(adj[u][0]);
    if (value[adj[u][0]] == 0) dfs2(adj[u][1]);
  } else {
    st.push_back(u);
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> leafs;
  for (int i = 0; i < n; i++) {
    scanf(" %s", name[i]);
    if (name[i][0] == 'I') {
      scanf(" %d", value + i);
      leafs.push_back(i);
    } else {
      int c;
      scanf("%d", &c);
      c--;
      adj[i].push_back(c);
      if (name[i][0] != 'N') {
        scanf("%d", &c);
        c--;
        adj[i].push_back(c);
      }
    }
  }
  dfs1(0);
  dfs2(0);
  string ans(leafs.size(), value[0] + '0');
  for (auto u : st) {
    int p = lower_bound(leafs.begin(), leafs.end(), u) - leafs.begin();
    ans[p] = 1 - value[0] + '0';
  }
  cout << ans << endl;
}
