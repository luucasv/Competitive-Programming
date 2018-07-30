#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

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
int a[ms], b[ms];
Complex aux[ms];

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

void mult(int a[], int &n, int b[], int m) {
  int N = 1;
  while (N < n + m) N <<= 1;
  for (int i = 0; i < N; ++i) {
    aux[i].real = i < n ? a[i] : 0;
    aux[i].imag = i < m ? b[i] : 0;
  }
  fft(aux, N);
  Complex scale(0, -0.25 / N);
  for (int i = 0; i <= (N >> 1); ++i) {
    int j = (N - i) & (N - 1);
    aux[j] = (aux[i] * aux[i] - (aux[j] * aux[j]).conj()) * scale;
    aux[i] = aux[j].conj();
  }
  fft(aux, N);
  n += m - 1;
  for (int i = 0; i < n; ++i) {
    a[i] = aux[i].real + 0.5;
  }
} 

vector<int> operator*(vector<int> p1, vector<int> p2) {
  int n = p1.size(), m = p2.size();
  vector<int> r(n + m - 1);
  for (int i = 0; i < n; i++) a[i] = p1[i];
  for (int i = 0; i < m; i++) b[i] = p2[i];
  mult(a, n, b, m);
  for (int i = 0; i < n; i++) r[i] = min(a[i], 1);
  return r;
}

vector<int> fexp(vector<int> p, int e) {
  vector<int> r(1, 1);
  for (; e; e >>= 1) {
    if (e & 1) {
      r = r * p;
    }
    p = p * p;
  }
  return r;
}

int main() {
  int n, k;
  vector<int> p(1001, 0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p[a] = 1;
  }
  p = fexp(p, k);
  for (int i = 0; i < p.size(); i++) {
    if (p[i]) {
      printf("%d ", i);
    }
  }
  puts("");
}
