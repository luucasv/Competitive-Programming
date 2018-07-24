#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

typedef long long ll;

int a[ms];

int main() {
 ll x1, x2, y1, y2;
 cin >> x1 >> y1 >> x2 >> y2;
 int n;
 cin >> n;
 int ans = 0;
 for (int i = 0; i < n; i++) {
  ll a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  ll me = a * x1 + b * y1 + c;
  ll uni = a * x2 + b * y2 + c;
  me = me / abs(me);
  uni = uni / abs(uni);
  if (me != uni) ans++;
 }
 cout << ans << endl;
}
