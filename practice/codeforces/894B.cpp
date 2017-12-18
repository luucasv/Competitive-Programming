#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __  = c; a < __; a++)

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll fastExp(ll b, ll e) {
  ll r = 1;
  for (; e; e >>= 1, b = b * b % mod) {
    if (e & 1) {
      r = r * b % mod;
    }
  }
  return r;
}

int main() {
  ll n, m;
  int k;
  cin >> n >> m >> k;
  if (k == -1 && (n + m)&1) {
    puts("0");
  } else {
    cout << fastExp(fastExp(2, n-1), m-1) << endl;
  }
}
