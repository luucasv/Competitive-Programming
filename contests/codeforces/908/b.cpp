#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

string b[60];
string s;

int mk[60][60], step;

int main() {
  int n, m;
  cin >> n >> m;
  int si, sj;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    for (int j = 0; j < m; j++) {
      if (b[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }
  cin >> s;
  int all[4] = {0, 1, 2, 3};
  int ans = 0;
  do {
    int i = si, j = sj;
    int k = 0;
    while (k < s.size() && i > -1 && j > -1 && i < n && j < m && b[i][j] != 'E' && b[i][j] != '#') {
      i = i + dx[all[s[k] - '0']];
      j = j + dy[all[s[k] - '0']];
      k++;
    }
    if (i > -1 && j > -1 && i < n && j < m && b[i][j] == 'E') ans++;
  } while(next_permutation(all, all + 4));
  cout << ans << endl;
  return 0;
}