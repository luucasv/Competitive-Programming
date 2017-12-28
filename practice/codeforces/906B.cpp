#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int n, int m) {
  vector<vector<int>> mat(n, vector<int>(m));
  vector<int> aux(m);
  for (int i = 0; i < n; i++) {
    int at = 1;
    for (int j = 0; j < m / 2; j++) {
      mat[i][j] = i * m + at + 1;
      at += 2;
      if (at >= m) at -= m;
    }
    at = 0;
    for (int j = m / 2; j < m; j++) {
      mat[i][j] = i * m + at + 1;
      at += 2;
      if (at >= m) at -= m;
    }
    if (i & 1) {
      if (m & 1) {
        int fs = m / 2;
        for (int k = 0; k < fs; k++) {
          aux[k + fs + 1] = mat[i][k];
        }
        for (int k = fs; k < m; k++) {
          aux[k - fs] = mat[i][k];
        }
        mat[i] = aux;
      } else {
        reverse(mat[i].begin(), mat[i].end());
      }
    }
  }
  return mat;
}

vector<vector<int>> solve2(int n, int m) {
  vector<vector<int>> mat(m, vector<int>(n));
  vector<int> aux(n);
  for (int i = 0; i < m; i++) {
    int at = 1;
    for (int j = 0; j < n / 2; j++) {
      mat[i][j] = at * m + i + 1;
      at += 2;
      if (at >= n) at -= n;
    }
    at = 0;
    for (int j = n / 2; j < n; j++) {
      mat[i][j] = at * m + i + 1;
      at += 2;
      if (at >= n) at -= n;
    }
    if (i & 1) {
      if (n&1) {
        int fs = n/2;
        for (int k = 0; k < fs; k++) {
          aux[k + fs + 1] = mat[i][k];
        }
        for (int k = fs; k < n; k++) {
          aux[k - fs] = mat[i][k];
        }
        mat[i] = aux;
      }
      else {
        reverse(mat[i].begin(), mat[i].end());
      }
    }
  }
  return mat;
}

vector<vector<int>> trans(const vector<vector<int>> &mat) {
  vector<vector<int>> ans(mat[0].size(), vector<int>(mat.size()));
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      ans[j][i] = mat[i][j];
    }
  }
  return ans;
}

pair<bool, vector<vector<int>>> brute(int n, int m) {
  vector<int> arr(n * m);
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n * m; i++) {
    arr[i] = i + 1;
  }
  do {
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i][j] = arr[i * m + j];
        if (i) {
          int a = min(ans[i - 1][j], ans[i][j]),
              b = max(ans[i - 1][j], ans[i][j]);
          if ((a + 1 == b && a % m != 0) || a + m == b) {
            ok = 0;
          }
        }
        if (j) {
          int a = min(ans[i][j - 1], ans[i][j]),
              b = max(ans[i][j - 1], ans[i][j]);
          if ((a + 1 == b && a % m != 0) || a + m == b) {
            ok = 0;
          }
        }
        if (!ok) break;
      }
      if (!ok) break;
    }
    if (ok) {
      return {ok, ans};
    }
  } while (next_permutation(arr.begin(), arr.end()));
  return {false, vector<vector<int>>(0)};
}

int main() {
  int n, m;
  vector<vector<int>> ans;
  cin >> n >> m;
  if (m >= 4) {
    ans = solve(n, m);
  } else if (n >= 4) {
    ans = solve2(n, m);
    ans = trans(ans);
  } else {
    bool can;
    tie(can, ans) = brute(n, m);
    if (!can) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d%c", ans[i][j], " \n"[j + 1 == m]);
    }
  }
}