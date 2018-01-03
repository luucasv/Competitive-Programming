#include <bits/stdc++.h>

using namespace std;


int main() {
  int n, k;
  cin >> n >> k;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int cur = 1 - (i&1);
    total += (n + cur) / 2;
  }
  if (total < k) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (k > 0 && ((i + j) % 2 == 0)) {
          printf("L");
          --k;
        } else {
          printf("S");
        }
      }
      puts("");
    }
  }
}