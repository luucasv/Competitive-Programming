#include <bits/stdc++.h>

using namespace std;

const int mv = 122;

int dist[mv][mv];

int main() {
  int n, k;
  cin >> n >> k;
  int m;
  cin >> m;
  memset(dist, 0x3f, sizeof dist);
  for (int i = 0; i < m; i++) {
    int h1, d1, h2, d2;
    scanf("%d.%d - %d.%d", &h1, &d1, &h2, &d2);
    int id1 = h1 * n + d1, id2 = h2 * n + d2;
    dist[id1][id2] = dist[id2][id1] = 1;
  }
  int vv = n * (k + 1);
  for (int i = 0; i < vv; i++) {
    dist[i][i] = 0;
  }
  for (int iter = 0; iter < 10; iter++) {
    for (int k = 0; k < vv; k++) for (int i = 0; i < vv; i++) for (int j = 0; j < vv; j++) {
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    for (int a = 0; a < n; a++) {
      for (int b = 0; b < n; b++) {
        for (int c = 1; c <= k; c++) {
          dist[c * n + a][c * n + b] = min(dist[c * n + a][c * n + b], dist[a][b]);
        }
      }
    }
  }
  /*for (int i = 0; i < vv; i++) {
    for (int j = i; j < vv; j++) {
      printf("dist(%d.%d, %d.%d) = %d\n", i / n, i % n, j / n, j % n, dist[i][j]);
    }
  }*/
  int a, b;
  cin >> a >> b;
  if (dist[a][b] < 1e9) cout << dist[a][b] << endl;
  else cout << "no solution" << endl;
}
