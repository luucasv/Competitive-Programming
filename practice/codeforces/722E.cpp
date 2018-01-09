#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int mk = 2e3 + 100, mlog = 21;
const int mf = 2e5 + 500;
const ll mod = 1e9 + 7;

vector<ii> v;

ll memo[mk][mlog];
ll fat[mf];
ll ifat[mf];

ll paths(int si, int sj, int ei, int ej) {
  int di = ei - si, dj = ej - sj;
  if (di < 0 || dj < 0) return 0;
  return (fat[di + dj] * ifat[di] % mod) * ifat[dj] % mod;
}


ll dp(int i, int q) {
  if (i + 1 == v.size()) {
    if (q == -1) return 1;
    else return 0;
  }
  if (q == -1) return 0;
  ll &ans = memo[i][q];
  if (ans != -1) return ans;
  ans = paths(v[i].first, v[i].second, v.back().first, v.back().second);
  ll sub = 0;
  for (int j = i + 1; j < v.size(); j++) {
    sub = (sub + paths(v[i].first, v[i].second, v[j].first, v[j].second) * dp(j, q)) % mod;
  }
  for (int j = -1; j < q; j++) {
    sub = (sub + dp(i, j));
  }
  sub = mod - sub;
  ans = (ans + sub) % mod;
  return ans;
}

ll fexp(ll b, ll e) {
  ll r = 1;
  for (; e; e >>= 1) {
    if (e & 1) {
      r = r * b % mod;
    }
    b = b * b % mod;
  }
  return r;
}

int main() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  fat[0] = 1;
  ifat[0] = 1;
  for (int i = 0; i < n + m; i++) {
    fat[i + 1] = fat[i] * (i + 1) % mod;
    ifat[i + 1] = fexp(fat[i + 1], mod - 2);
  }
  int always = 0;
  
  for (int i = 0; i < k; i++) {
    int r, c;
    scanf("%d %d", &r, &c);
    if (r == 1 && c == 1) {
      always++;
    } else if (r == n && c == m) {
      always++;
    } else {
      v.emplace_back(--r, --c);
    }
  }
  
  memset(memo, -1, sizeof memo);

  v.emplace_back(0, 0);
  v.emplace_back(n-1, m-1);
  sort(v.begin(), v.end());
  for (int i = 0; i < always; i++) s = (s + 1) / 2;
  ll sum = paths(0, 0, n-1, m-1);
  for (int i = 0; i < mlog; i++) {
    sum = (sum + (s - 1) * dp(0, i)) % mod;
    s = (s + 1) / 2;
  }
  sum = (sum + mod) % mod;
  sum = sum * fexp(paths(0, 0, n-1, m-1), mod - 2) % mod;
  cout << sum << '\n';
}
