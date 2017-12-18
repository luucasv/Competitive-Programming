#include <bits/stdc++.h>

using namespace std;

const int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int a[50];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < 12; i++) {
    int can = 1;
    int ok = 1;
    for (int d = 0; d < n; d++) {
      int at = (i + d) % 12;
      if (a[d] == 29) {
        if (at == 1 && can) {
          can = 0;
        } else {
          ok = 0;
        }
      } else {
        if (a[d] != m[at]) {
          ok = 0;
        }
      }
    }
    if (ok) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}