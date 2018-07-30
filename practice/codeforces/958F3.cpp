#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos(-1.0);

struct Complex {
  ld real, imag;
  Complex(ld a = 0, ld b = 0) : real(a), imag(b) {}
  Complex operator+(Complex p) { return Complex(real + p.real, imag + p.imag); }
  Complex operator-(Complex p) { return Complex(real - p.real, imag - p.imag); }
  Complex operator*(Complex p) {
    return Complex(real * p.real - imag * p.imag,
                   real * p.imag + imag * p.real);
  }
  Complex conj() { return Complex(real, -imag); }
};

const int ms = 1 << 20;
Complex aux1[ms], aux2[ms];

void fft(Complex p[], int n) {
  for (int i = 1, j = 0; i < n - 1; ++i) {
    for (int s = n; j ^= s >>= 1, ~j & s;)
      ;
    if (i < j) swap(p[i], p[j]);
  }
  Complex wn, w;
  for (int d = 0; (1 << d) < n; ++d) {
    int m = 1 << d, m2 = m << 1;
    ld p0 = pi / m;
    wn = Complex(cos(p0), sin(p0));
    for (int i = 0; i < n; i += m2) {
      w = 1;
      for (int j = 0; j < m; ++j) {
        Complex &p1 = p[i + j + m], &p2 = p[i + j];
        Complex t = w * p1;
        p1 = p2 - t;
        p2 = p2 + t;
        w = w * wn;
      }
    }
  }
}

vector<ll> operator*(const vector<ll> &a, const vector<ll> &b) {
  int n = a.size(), m = b.size();
  int N = 1;
  while (N < n + m) N <<= 1;
  for (int i = 0; i < N; ++i) {
    aux1[i] = Complex(i < n ? a[i] : 0);
    aux2[i] = Complex(i < m ? b[i] : 0);
  }
  fft(aux1, N);
  fft(aux2, N);
  Complex scale(1.0 / N);
  for (int i = 0; i < N; ++i) {
    aux1[i] = aux1[i] * aux2[i];
    aux1[i] = aux1[i] * scale;
  }
  for (int i = 0; i < (N >> 1); i++) {
    swap(aux1[i], aux1[(N - i) % N]);
  }
  fft(aux1, N);
  vector<ll> ans(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    ans[i] = aux1[i].real + 0.5;
    ans[i] %= 1009;
  }
  return ans;
} 

ostream& operator<<(ostream &os, vector<ll> v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

vector<ll> pols[ms];
int cnt[ms];

vector<ll> mult(int l, int r) {
  if (l == r) return pols[l];
  int m = (l + r) / 2;
  vector<ll> ans = mult(l, m) * mult(m + 1, r);
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    cnt[v - 1]++;
  }
  for (int i = 0; i < m; i++) {
    pols[i].assign(cnt[i] + 1, 1LL);
  }
  vector<ll> ans = mult(0, m - 1);
  assert(k < ans.size());
  cout << ans[k] << endl;
}

