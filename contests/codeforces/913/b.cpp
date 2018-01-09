#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 20;

int p[ms];
int cnt[ms];
int le[ms];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d", p + i);
    --p[i];
    cnt[p[i]]++;
  }
  for (int i = 1; i < n; i++) {
    if (cnt[i] == 0) {
      le[p[i]]++;
    }
  }
  int ok = 1;
  for (int i = 0; i < n; i++) {
    if (cnt[i] != 0 && le[i] < 3) {
      ok = 0;
    }
  }
  puts(ok ? "Yes" : "No");
}