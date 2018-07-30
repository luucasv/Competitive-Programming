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

vector<int> operator*(const vector<int> &a, const vector<int> &b) {
  int n = a.size(), m = b.size();
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
  vector<int> ans(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    ans[i] = aux[i].real + 0.5;
  }
  return ans;
} 

ostream& operator<<(ostream &os, vector<int> v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

int get_id(char ch) {
  if (ch == 'V') return 0;
  if (ch == 'K') return 1;
  return 2;
}

char s[ms];

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n;
    scanf("%d %s", &n, s);

    // cout << n << ' ' << s << endl;
    vector<int> p[2];
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 2; k++) {
        p[k].push_back(get_id(s[i]) == k);
      }
    }
    vector<int> miss1, miss2, ans;
    reverse(p[1].begin(), p[1].end());
    miss1 = p[0] * p[1];
    reverse(p[1].begin(), p[1].end());
    reverse(p[0].begin(), p[0].end());
    miss2 = p[0] * p[1];
    // cout << p[0] << endl << p[1] << endl << miss1 << endl << miss2 << endl;
    for (int i = 1; i <= n; i++) {
      int ok = 1;
      for (int j = i; j < n; j += i) {
        ok = ok and miss1[n - j - 1] == 0 and miss2[n - j - 1] == 0;
        // cout << j << ' ' << n - j - 1 << ' ' << ok << endl;
      }
      if (ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
  }
}
