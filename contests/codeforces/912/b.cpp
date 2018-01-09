#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long n,k;
  cin >> n >> k;
  int i = 0;
  while ((1ULL << (i + 1)) <= n) {
    i++;
  }
  if (k == 1) {
    cout << n << '\n';
  } else {
    cout << (1ULL << (i + 1)) - 1 << '\n';
  }
}