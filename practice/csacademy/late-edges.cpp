#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
const int mv = 5001, me = 2 * mv;
const ll inf = 1e17;
int adj[mv], to[me], ant[me], t[me], z;
ll dist[2 * mv];

inline void add(int a, int b, int c) {
  ant[z] = adj[a], to[z] = b, t[z] = c, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, t[z] = c, adj[a] = z++;
}

ll get_time(int from, ll in_time, int ed_time) {
  if (in_time > ed_time) {
    return in_time + 1;
  }
  int p_time = ed_time & 1LL;
  int p_from = from & 1;
  int add = p_time == p_from ? 0 : 1;
  return ed_time + 1 + add;
}

ll dijkstra(int src, int sink) {
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  memset(dist, 0x3f, sizeof dist);
  dist[0] = 0;
  pq.push(ii(0, 0));
  while (!pq.empty()) {
    ll d;
    int u;
    tie(d, u) = pq.top();
    pq.pop();
    if (dist[u] < d) continue;
    for (int i = adj[u >> 1]; i > -1; i = ant[i]) {
      ll nd = get_time(u, d, t[i]);
      int v = (to[i] << 1) | (nd & 1);
      if (dist[v] > nd) {
        dist[v] = nd;
        pq.push(ii(nd, v));
      }
    }
  }
  ll ans = min(dist[sink * 2], dist[2 * sink + 1]);
  if (ans >= inf)
    ans = -1;
  return ans;
}

int main() {
  int n, m;
  memset(adj, -1, sizeof adj);
  cin >> n >> m;
  fr(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    add(a, b, c);
  }
  cout << dijkstra(0, n-1) << endl;
}