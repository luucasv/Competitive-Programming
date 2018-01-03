#include <bits/stdc++.h>
using namespace std;

int win[1001];

int main() {
  int n;
  cin >> n;
  if (n & 1) {
    puts("Yes");
    for (int i = 0; i < n; i++) {
      int t = n - i - 1;
      int need = (n - 1) / 2 - win[i];
      int v[2];
      v[1] = need;
      v[0] = t - need;
      int st = 1 - (i&1);
      for (int j = 0; j < v[st]; j++) {
        printf("%d ", st);
        if (st == 0) {
          win[i + j + 1]++;
        }
      }
      for (int j = v[st]; j < t; j++) {
        printf("%d%c", 1 - st, " \n"[j + 1 == t]);
        if (st == 1) {
          win[i + j + 1]++;
        }
      }
    }
  } else {
    puts("No");
  }
}