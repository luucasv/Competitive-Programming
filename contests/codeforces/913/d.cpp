#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;

const int ms = 2e5 + 20;

i3 v[ms];
int n, t;

bool can(int k) {
  int cnt = 0;
  ll tt = 0;
  for (int i = 0; i < n && cnt < k; i++) {
    if (v[i].first.second >= k) {
      cnt++;
      tt += v[i].first.first;
    }
  }
  return cnt == k && tt <= t;
}

int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].first.second, &v[i].first.first);
    v[i].second = i;
  }
  sort(v, v + n);
  int lo = 0, hi = n;
  while (hi - lo > 1) {
    int md = (lo + hi) / 2;
    if (can(md)) {
      lo = md;
    } else {
      hi = md;
    }
  }
  if (!can(hi)) hi = lo;
  cout << hi << '\n';
  cout << hi << '\n';
  int cnt = 0;
  ll tt = 0;
  for (int i = 0; i < n && cnt < hi; i++) {
    if (v[i].first.second >= hi) {
      cnt++;
      printf("%d ", v[i].second + 1);
    }
  }
  puts("");
}