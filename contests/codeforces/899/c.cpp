#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    puts("1\n1 1");
  } else if (n == 2) {
    puts("1\n1 1");
  } else if (n == 3) {
    puts("0\n1 3");
  } else if (n & 1) {
    int d = (n + 1) / 2;
    if (d & 1) {
      puts("1");
      int q = (n - 1) / 2;
      cout << q + 1 << ' ' << 1;
      for (int i = 0; i < q / 2; i++) {
        cout << ' ' << i + 2 << ' ' << n - i;
      }
    } else {
      puts("0");
      int q = (n - 3) / 2;
      cout << q + 1 << ' ' << 3;
      for (int i = 0; i < q / 2; i++) {
        cout << ' ' << i + 4 << ' ' << n - i;
      }
    }
  } else {
    int d = n / 2;
    if (d & 1) {
      puts("1");
      cout << d << " 1";
      for (int i = 0; i < (d - 1) / 2; i++) {
        cout << ' ' << i + 3 << ' ' << n - i;
      }
    } else {
      puts("0");
      cout << d;
      for (int i = 0; i < d / 2; i++) {
        cout << ' ' << i + 1 << ' ' << n - i;
      }
    }
  }
  cout << '\n';
}