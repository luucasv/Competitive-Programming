#include <bits/stdc++.h>
#define fr(a, b, c) for (int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int mv = 1e5, me = mv;
int adj[mv], ant[me], to[me], d[mv], z;
inline void add(int a, int b) {
  ant[z] = adj[a], to[z] = b, d[b]++, adj[a] = z++;
}

int main() {
  memset(adj, -1, sizeof adj);
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  vector<bool> eq(n, true);
  eq[0] = false;
  bool ok = 1;
  fr(i, 0, n) {
    fr(j, 0, m) {
      cin >> mat[i][j];
      if (eq[i]) {
        eq[i] = mat[i - 1][j] == mat[i][j];
        if (!eq[i]) {
          add(mat[i-1][j], mat[i][j]);
        }
      }
    }
    if (eq[i]) {
      ok = 0;
    }
  }
  queue<int> fila;
  vector<int> p(k);
  fr(i, 0, k) {
    if (d[i] == 0 && i != mat[0][0]) fila.push(i);
  }
  if (fila.empty()) ok = false;
  if (d[mat[0][0]] == 0) fila.push(mat[0][0]);
  int at = 0;
  while (!fila.empty()) {
    int v = fila.front();
    p[v] = at++;
    fila.pop();
    for (int i = adj[v]; i > -1; i = ant[i]) {
      d[to[i]]--;
      if (d[to[i]] == 0) {
        fila.push(to[i]);
      }
    }
  }
  if (ok && at == k) {
    cout << p[0];
    fr(i, 1, k) cout << " " << p[i];
    cout << endl;
  } else {
    puts("-1");
  }
} 