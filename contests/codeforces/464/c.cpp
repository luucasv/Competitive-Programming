#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ms = 5e5 + 10;
const ll mod = 1e9 + 7;

struct Digit {
  ll val;
  ll size;

  Digit(ll val = 0, ll size = 0) :val(val), size(size){}
};

Digit ds[1000];

ll fexp(ll b, ll e) {
  ll r = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) r = r * b % mod;
    b = b * b % mod;
  }
  return r;
}

int main() {
  string s;
  int n;
  cin >> s >> n;
  vector<string> v;
  vector<char> d;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    char ch, a, b;
    string ss;
    getline(cin, ss);
    ch = ss[0], a = ss[1], b = ss[2];
    ss = ss.substr(3);
    while (ss.size() and ss.back() == ' ') ss.pop_back();
    d.push_back(ch);
    v.push_back(ss);
    assert(a == '-' && b == '>' and '0' <= ch and ch <= '9');
  }
  reverse(v.begin(), v.end());
  reverse(d.begin(), d.end());
  for (char i = '0'; i <= '9'; i++) {
    ds[i] = Digit(i - '0', 10);
  }
  for (int i = 0; i < n; i++) {
    ll val = 0;
    ll pot = 1;
    for (auto ch : v[i]) {
      val = val * ds[ch].size % mod;
      val = (val + ds[ch].val) % mod;
      pot = pot * ds[ch].size % mod;
    }
    ds[d[i]] = Digit(val, pot);
  }
  ll val = 0;
  for (auto ch : s) {
    val = val * ds[ch].size % mod;
    val = (val + ds[ch].val) % mod;
  }
  cout << val << endl;
}