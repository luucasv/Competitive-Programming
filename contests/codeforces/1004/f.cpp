#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

typedef pair<int, int> ii;
typedef long long ll;

int x;

struct Node {
  vector<ii> prefix, suffix;
  ll ans;

  Node() {
    ans = 0;
  }

  Node(int v) {
    prefix = suffix = {ii(v, 1)};
    if (v >= x) ans = 1;
    else ans = 0;
  }

  void insertPrefix(ii v) {
    if (prefix.size()) {
      v.first |= prefix.back().first;
    }
    if (prefix.empty() or v.first != prefix.back().first) {
      prefix.push_back(v);
    } else {
      prefix.back().second += v.second;
    }
  }

  void insertSuffix(ii v) {
    if (suffix.size()) {
      v.first |= suffix.back().first;
    }
    if (suffix.empty() or v.first != suffix.back().first) {
      suffix.push_back(v);
    } else {
      suffix.back().second += v.second;
    }
  }
};

Node operator+(const Node &lhs, const Node &rhs) {
  Node ret;
  ret.ans = lhs.ans + rhs.ans;
  ll q = 0; 
  int j = int(rhs.prefix.size()) - 1;
  for (int i = 0; i < lhs.suffix.size(); i++) {
    while (j > -1 and (lhs.suffix[i].first | rhs.prefix[j].first) >= x) {
      q += rhs.prefix[j].second;
      j--; 
    }
    ret.ans += lhs.suffix[i].second * q;
  }
  ret.prefix = lhs.prefix;
  ret.suffix = rhs.suffix;
  for (auto &it : rhs.prefix) ret.insertPrefix(it);
  for (auto &it : lhs.suffix) ret.insertSuffix(it);
  return ret;
}

struct SegmentTree {
  vector<Node> tree;
  int n;

  SegmentTree(vector<int> v) {
    n = v.size();
    tree.assign(n + n, Node());
    for (int i = 0; i < n; i++) {
      tree[i + n] = Node(v[i]);
    }
    for (int i = n - 1; i > 0; i--) {
      tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
  }

  void update(int p, int v) {
    p += n;
    tree[p] = Node(v);
    for (p >>= 1; p > 0; p >>= 1) {
      tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
  }

  ll query(int l, int r) {
    Node left, right;
    l += n;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        left = left + tree[l++];
      }
      if (r & 1) {
        right = tree[--r] + right;
      }
    }
    return (left + right).ans;
  }
};

int main() {
  int n, m;
  cin >> n >> m >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  SegmentTree seg(v);
  while (m--) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    if (t == 1) {
      seg.update(a - 1, b);
    } else {
      printf("%lld\n", seg.query(a - 1, b));
    }
  }
}