#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int mv = 1e5 + 10, me = 2*mv;
int adj[mv], to[me], ant[me], z;

inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
  swap(a, b);
  ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

ll fastExp(ll x, ll e) {
  ll ans = 1;
  for (; e; e >>= 1){
    if (e&1) {
      ans = ans * x % mod;
    }
    x = x * x % mod;
  }
  return ans;
}

ll res;
int n, x, k, m;
ll prep[2][mv][3][11];

int dfs(int u, int p) {
  fr(i, 0, x+1) {
    prep[0][u][0][i] = i == 1 ? 1 : 0;
    prep[0][u][1][i] = i == 0 ? (k-1) : 0; // menor
    prep[0][u][2][i] = i == 0 ? (m - k) : 0; // maior

    /*fr(oi, 0, 3) {
      dbg(u _ oi _ i _ prep[0][u][oi][i])
    }*/
  }
  int at = 0;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    int v = to[i];
    if (v == p) {
      continue;
    }
    int f = dfs(v, u);

    fr(l, 0, x+1) {
      prep[1 - at][u][0][l] = prep[1 - at][u][1][l] = prep[1 - at][u][2][l] = 0;
      fr(j, 0, l+1) {
        prep[1 - at][u][0][l] += prep[at][u][0][l - j] * prep[f][v][1][j];
        prep[1 - at][u][1][l] += prep[at][u][1][l - j] * (prep[f][v][1][j] + prep[f][v][2][j] + prep[f][v][0][j]);
        prep[1 - at][u][2][l] += prep[at][u][2][l - j] * (prep[f][v][1][j] + prep[f][v][2][j]);
        prep[1 - at][u][0][l] %= mod;
        prep[1 - at][u][1][l] %= mod;
        prep[1 - at][u][2][l] %= mod;
      }
      /*fr(oi, 0, 3) {
        dbg(u _ oi _ l _ prep[1 - at][u][oi][l])
      }*/
    }
    at = 1 - at;
  }
  return at;
}

int main() {
  cin >> n >> m;
  memset(adj, -1, sizeof adj);
  fr(i, 1, n) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    add(u, v);
  }
  cin >> k >> x;
  int f = dfs(0, 0);
  ll ans = 0;
  fr(i, 0, x+1) {
    fr(k, 0, 3) {
      ans += prep[f][0][k][i];
    }
  }
  ans %= mod;
  cout << ans << endl;
}