#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  if (n == 1 && t == 10) {
    cout << "-1\n";
  } else {
    cout << t;
    if (t == 10) n--;
    n--;
    while (n--) cout << "0";
    cout << '\n';
  }
}