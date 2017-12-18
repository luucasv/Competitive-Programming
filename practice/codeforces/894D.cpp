#include <bits/stdc++.h>
#define fr(a, b, c) for (int a = b, __ = c; a < __; a++)
#define dbg(c) cerr << ">>>>> " << c << endl;
#define _ << " , " <<
using namespace std;
typedef long long ll;

const int ms = 1e6 + 20;

struct Node {
  vector<int> vals;
  vector<ll> acc;
};

Node vec[ms];
int c[ms];
int n;

void build(int id) {
  if (id > n) {
    return;
  }
  build(2 * id);
  build(2 * id + 1);
  const Node &le = (2 * id <= n) ? vec[2 * id] : Node();
  const Node &ri = (2 * id + 1 <= n) ? vec[2 * id + 1] : Node();
  vec[id].vals.assign(le.vals.size() + ri.vals.size() + 1, 0);
  merge(le.vals.begin(), le.vals.end(), ri.vals.begin(), ri.vals.end(),
        vec[id].vals.begin() + 1);
  for (int &v : vec[id].vals) {
    v += c[id];
  }
  vec[id].acc.assign(vec[id].vals.size() + 1, 0LL);
  fr(i, 1, vec[id].acc.size()) {
    vec[id].acc[i] = vec[id].acc[i - 1] + vec[id].vals[i - 1];
  }
}

ll get(int id, ll h) {
  if (id > n) {
    return 0;
  }
  int pos = lower_bound(vec[id].vals.begin(), vec[id].vals.end(), h) -
            vec[id].vals.begin();
  return h * pos - vec[id].acc[pos];
}

int main() {
  int m;
  cin >> n >> m;
  fr(i, 2, n + 1) { 
    scanf("%d", c + i);
  }
  build(1);
  while (m--) {
    int a, h;
    scanf("%d %d", &a, &h);
    ll ans = get(2 * a, h) + get(2 * a + 1, h);
    while (a > 1 && h - c[a] > 0) {
      ans += h;
      h -= c[a];
      ans += get(a ^ 1, h);
      a >>= 1;
    }
    if (h > 0) {
      ans += h;
    }
    cout << ans << endl;
  }
}