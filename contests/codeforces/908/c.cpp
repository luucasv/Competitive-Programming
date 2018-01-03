#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int ms = 1111;

int x[ms];
double y[ms];

int main() {
  int n, r;
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    scanf("%d", x + i);
  }
  y[0] = r;
  printf("%d", r);
  for (int i = 1; i < n; i++) {
    double g = r;
    for (int j = 0; j < i; j++) {
      double dx = x[i] - x[j];
      double a = 1, b = - 2 * y[j], c = dx * dx - 4 * r * r + y[j] * y[j];
      double d = b * b - 4 * a * c;
      if (d < 0) continue;
      d = sqrt(d);
      g = max(g, max((-b + d) / 2, (-b - d) / 2));
    }
    y[i] = g;
    printf(" %.10lf", y[i]);
  }
  puts("");
  return 0;
}