typedef long long T;
const T INF = 1e18, EPS = 1;

struct Line {
  T m, b;
  
  Line(T m = 0, T b = INF): m(m), b(b){}
  T apply(T x) { return x * m + b; }
};

struct Node {
  Node *left, *right;
  Line line;
  Node(): left(NULL), right(NULL) {}
  ~Node() {
    if (left) delete left;
    if (right) delete right;
  }
};

struct LiChaoTree {
  Node root;
  T n;
  LiChaoTree(T n): n(n) {}
  void insert_line(T m, T b) { update(&root, 0, n, Line(m, b)); }
  T eval(T x) { return query(&root, 0, n, x); }
  void update(Node *cur, T l, T r, Line line) {
    T m = (l + r) / 2;
    bool left = line.apply(l) < cur->line.apply(l);
    bool mid = line.apply(m) < cur->line.apply(m);
    bool right = line.apply(r) < cur->line.apply(r);
    if (mid) {
      swap(cur->line, line);
    }
    if (r - l <= EPS) return;
    if (left == right) return;
    if (mid != left) {
      if (cur->left == NULL) cur->left = new Node();
      update(cur->left, l, m, line);
    } else {
      if (cur->right == NULL) cur->right = new Node();
      update(cur->right, m, r, line);
    }
  }
  T query(Node *cur, T l, T r, T x) {
    if (cur == NULL) return INF;
    if (r - l <= EPS) {
      return cur->line.apply(x);
    }
    T m = (l + r) / 2;
    T ans;
    if (x < m) {
      ans = query(cur->left, l, m, x);
    } else {
      ans = query(cur->right, m, r, x);
    }
    return min(ans, cur->line.apply(x));
  }
};
