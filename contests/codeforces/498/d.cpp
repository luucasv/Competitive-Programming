#include <bits/stdc++.h>

using namespace std;

const int md = 60;

struct Node {
  int ans[md];

  Node (int a) {
    for (int i = 0; i < md; i++) {
      if (i % a == 0) ans[i] = 2;
      else ans[i] = 1;
    }
  }

  Node() {
    memset(ans, 0, sizeof ans);
  }
};

Node operator+(const Node &lhs, const Node &rhs) {
  Node ans;
  for (int i = 0; i < md; i++) {
    int out = (lhs.ans[i] + i) % md;
    ans.ans[i] = lhs.ans[i] + rhs.ans[out];
  }
  return ans;
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

  int query(int l, int r) {
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
    return (left + right).ans[0];
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  SegmentTree seg(v);
  int q;
  cin >> q;
  while (q--) {
    char c;
    int x, y;
    scanf(" %c %d %d", &c, &x, &y);
    if (c == 'A') {
      x--;
      y--;
      printf("%d\n", seg.query(x, y));
    } else {
      x--;
      seg.update(x, y);
    }
  }
}
