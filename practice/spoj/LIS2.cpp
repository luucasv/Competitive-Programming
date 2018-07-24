#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

vector<int> bit[ms];
vector<int> ys[ms];

void update(int x, int y, int v) {
  for (int i = x; i < ms; i += (i & -i)) {
    for (int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin(); j < ys[i].size(); j += (j & -j)) {
      bit[i][j] = max(bit[i][j], v);
    }
  }
}

int query(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= (i & -i)) {
    for (int j = upper_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin() - 1; j > 0; j -= (j & -j)) {
      ans = max(bit[i][j], ans);
    }
  }
  return ans;
}

int main() {
  map<int, int> mpx;
  vector<pair<int, int>> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v.emplace_back(x, y);
    mpx[x];
  }
  int aux = 2;
  for (auto &it : mpx) {
    it.second = aux++;
  }
  for (auto &it : v) {
    int x = mpx[it.first];
    it.first = x;
    while (x < ms) {
      ys[x].push_back(it.second);
      x += (x & -x);
    }
  }
  for (int i = 0; i < ms; i++) {
    ys[i].push_back(-1e9 - 20);
    sort(ys[i].begin(), ys[i].end());
    ys[i].resize(unique(ys[i].begin(), ys[i].end()) - ys[i].begin());
    bit[i].assign(ys[i].size() + 1, 0);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int ans = query(v[i].first - 1, v[i].second - 1) + 1;
    res = max(res, ans);
    update(v[i].first, v[i].second, ans);
  }
  cout << res << endl;
}
