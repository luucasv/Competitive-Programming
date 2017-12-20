#include <bits/stdc++.h>

using namespace std;
const int ms = 1e5 + 20;

int a[ms], b[ms], v[ms];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i + 1 < n; i++) {
    if (a[i + 1] > a[i]) {
      printf("0");
    } else {
      printf("1");
    }
  }
  if (b[n-2] > b[n-1]) {
    printf("0");
  } else {
    printf("1");
  }
  puts("");
  return 0;
}