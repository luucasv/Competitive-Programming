#include <bits/stdc++.h>
using namespace std;

const int ms = 800 + 20;
const int Q = 30;

struct range_tree {
  vector<vector<int>> rt;
  vector<int> v;
  int n;
  
  range_tree():n(0) {}

  range_tree(vector<int> v) : v(v), n(v.size()) {
    rt.assign(4 * n, vector<int>(0));
    build(1, 0, n - 1);
  }

  void build(int i, int l, int r) {
    if (l == r) {
      rt[i].push_back(v[l]);
      return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    rt[i].resize(r - l + 1);
    merge(rt[2 * i].begin(), rt[2 * i].end(),
          rt[2 * i + 1].begin(), rt[2 * i + 1].end(),
          rt[i].begin());
  }

  int query(int i, int j, int v) {
    return query(1, 0, n-1, i, j, v);
  }

  int query(int idx, int l, int r, int i, int j, int v) {
    if (r < i || l > j) return 0;
    if (i <= l && r <= j) {
      return upper_bound(rt[idx].begin(), rt[idx].end(), v) - rt[idx].begin();
    }
    int m = (l + r) / 2;
    return query(2 * idx, l, m, i, j, v) + query(2 * idx + 1, m + 1, r, i, j, v);
  }
};

struct buck {
  int n;
  vector<int> bks[Q];
  vector<int> v;
  buck(){}
  buck(vector<int> v) :v(v) {
    n = v.size();
    for (int i = 0; i < n; i++) {
      bks[i / Q].push_back(v[i]);
    }
    for (int i = 0; i < Q; i++) {
      sort(bks[i].begin(), bks[i].end());
    }
  }

  int query(int l, int r, int val) {
    int ql = l / Q, qr = r / Q;
    int ans = 0;
    for (int i = ql + 1; i < qr; i++) {
      ans += upper_bound(bks[i].begin(), bks[i].end(), val) - bks[i].begin();
    }
    for (int i = l; i < min(r + 1, (ql + 1) * Q); i++) {
      if (v[i] <= val) {
        ans++;
      }
    } 
    if (ql != qr) {
      for (int i = qr * Q; i <= r; i++) {
        if (v[i] <= val) {
          ans++;
        }
      }
    }
    return ans;
  }
};

map<int, int> mp;
int ret[ms * ms];

int get_id(int v) {
  if (!mp.count(v)) {
    int i = mp.size();
    mp[v] = i;
    ret[i] = v;
  }
  return mp[v];
}

buck ranges[ms];

int sum(int v, int x1, int y1, int x2, int y2) {
  int ans = 0;
  for (int i = x1; i < x2; i++) {
    ans += ranges[i].query(y1, y2, v);
  }
  return ans;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<vector<int>> m(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
      mp[m[i][j]];
    }
  }
  int aux = 0;
  for (auto &it : mp) {
    it.second = aux++;
    ret[aux - 1]  = it.first;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = mp[m[i][j]];
    }
    ranges[i] = buck(m[i]);
    m[i].clear();
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --y2;
    int lo = 0, hi = mp.size() - 1;
    int sz = (x2 - x1) * (y2 - y1 + 1);
    sz = (sz + 1) / 2;
    while (hi - lo > 0) {
      int md = (lo + hi) / 2;
      if (sum(md, x1, y1, x2, y2) >= sz) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    cout << ret[lo] << '\n';
  }
  
}