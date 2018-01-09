#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> i3;

int n, m, r, k;

ll calc(int i, int j) {
  if (i < 0 || j < 0) return 0;
  if (i >= n || j >= m) return 0;
  int si = max(0, i - r + 1);
  int ei = si + r - 1;
  int sj = max(0, j - r + 1);
  int ej = sj + r - 1;
  ll di = min(r, min(i - si + 1, n - ei));
  ll dj = min(r, min(j - sj + 1, m - ej));
  // cout << i << ' ' << j << ' ' << di << ' ' << dj << ' ' << di * dj << '\n';
  return di * dj;
}

int main() {
  cin >> n >> m >> r >> k;
  priority_queue<i3> pq;
  set<ii> mk;
  int i = n / 2, j = m / 2;
  pq.push(i3(calc(i, j), ii(i, j)));
  pq.push(i3(calc(i - 1, j), ii(i - 1, j)));
  pq.push(i3(calc(i + 1, j), ii(i + 1, j)));
  pq.push(i3(calc(i, j - 1), ii(i, j - 1)));
  pq.push(i3(calc(i, j + 1), ii(i, j + 1)));
  mk.insert(ii(i - 1, j));
  mk.insert(ii(i + 1, j));
  mk.insert(ii(i, j - 1));
  mk.insert(ii(i, j + 1));
  mk.insert(ii(i, j));
  ll sum = 0;
  for (int adahda = 0; adahda < k; adahda++) {
    i3 eae = pq.top();
    pq.pop();
    sum += eae.first;
    i = eae.second.first;
    j = eae.second.second;
    assert(calc(i, j) == eae.first);
    cout << i << ' ' << j << ' ' << eae.first << '\n';
    if (!mk.count(ii(i - 1, j))) {
      mk.insert(ii(i - 1, j));      
      pq.push(i3(calc(i - 1, j), ii(i - 1, j)));
    }
    if (!mk.count(ii(i + 1, j))) {
      mk.insert(ii(i + 1, j));      
      pq.push(i3(calc(i + 1, j), ii(i + 1, j)));
    }
    if (!mk.count(ii(i, j - 1))) {
      mk.insert(ii(i, j - 1));      
      pq.push(i3(calc(i, j - 1), ii(i, j - 1)));
    }
    if (!mk.count(ii(i, j + 1))) {
      mk.insert(ii(i, j + 1));      
      pq.push(i3(calc(i, j + 1), ii(i, j + 1)));
    }
  }
  ll total = ll(n - r + 1) * (m - r + 1);
  cout << setprecision(12) << fixed << sum / (double)(total) << '\n';
}
