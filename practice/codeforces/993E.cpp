#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> Polynomial;

ostream& operator<<(ostream &os, Polynomial v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

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

struct Node {
  Polynomial prefix, suffix, all;
  int sum;

  Node() {
    sum = 0;
  }

  Node(int val) {
    sum = val;
    all.assign(val + 1, 0);
    all[val] = 1;
    prefix = suffix = all;
  }
};

const ld pi = acos(-1.0);
const int ms = 1 << 20;

void fft(vector<Complex> &p) {
  int n = p.size();
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

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
  int n = a.size(), m = b.size();
  int N = 1;
  while (N < n + m) N <<= 1;
  vector<Complex> aux(N);
  for (int i = 0; i < N; ++i) {
    aux[i].real = i < n ? a[i] : 0;
    aux[i].imag = i < m ? b[i] : 0;
  }
  fft(aux);
  Complex scale(0, -0.25 / N);
  for (int i = 0; i <= (N >> 1); ++i) {
    int j = (N - i) & (N - 1);
    aux[j] = (aux[i] * aux[i] - (aux[j] * aux[j]).conj()) * scale;
    aux[i] = aux[j].conj();
  }
  fft(aux);
  Polynomial ans(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    ans[i] = aux[i].real + 0.5;
  }
  return ans;
} 

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs) {
  Polynomial ans(max(lhs.size(), rhs.size()), 0);
  for (int i = 0; i < lhs.size(); i++) ans[i] += lhs[i];
  for (int j = 0; j < rhs.size(); j++) ans[j] += rhs[j];
  return ans;
}

Polynomial operator<<(const Polynomial lhs, int rhs) {
  Polynomial ans(lhs.size() + rhs, 0);
  for (int i = 0; i < lhs.size(); i++) {
    ans[i + rhs] = lhs[i];
  }
  return ans;
}
      

Node operator+(const Node &lhs, const Node &rhs) {
  Node ans;
  ans.sum = lhs.sum + rhs.sum;
  ans.prefix = lhs.prefix + (rhs.prefix << lhs.sum);
  ans.suffix = rhs.suffix + (lhs.suffix << rhs.sum);
  ans.all = lhs.all + rhs.all + lhs.suffix * rhs.prefix;
  // cout << lhs.all << endl << rhs.all << endl << lhs.suffix << endl << rhs.prefix << endl << lhs.suffix * rhs.prefix << endl;
  return ans;
}

int v[ms];

Node solve(int l, int r) {
  if (l == r) {
    return Node(v[l]);
  }
  int m = (l + r) / 2;
  return solve(l, m) + solve(m + 1, r);
}

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v[i] = a < x;
  }
  Polynomial ans = solve(0, n - 1).all;
  for (int i = 0;  i <= n; i++) {
    printf("%lld%c", i < ans.size() ? ans[i] : 0LL, " \n"[i == n]);
  }
}
