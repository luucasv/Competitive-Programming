#include <bits/stdc++.h>

using namespace std;

const int ms = 2e5 + 200;

int a[ms];
int is_sq[ms];

int my_sq(int a) {
  long long lo = 0, hi = 1;
  while (hi * hi < a) {
    lo = hi;
    hi <<= 1;
  }
  while (hi - lo > 1) {
    long long md = (hi + lo) / 2;
    if (md * md > a) hi = md - 1;
    else if (md * md < a) lo = md;
    else return md;
  }
  if (hi * hi > a) return lo;
  return hi;
}

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> sqs, nsqs;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    long long s = my_sq(a[i]);
    if (s * s == a[i]) {
      if (a[i] == 0) sqs.push(2);
      else sqs.push(1);
    } else {
      nsqs.push(min(a[i] - s * s, (s + 1) * (s + 1) - a[i]));
    }
  }
  long long ans =  0;
  while (sqs.size() > n / 2) {
    ans += sqs.top();
    sqs.pop();
  }
  while (nsqs.size() > n / 2) {
    ans += nsqs.top();
    nsqs.pop();
  }
  cout << ans << endl;
}
