#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int ans = 0;
    int n;
    cin >> n;
    while (n--) {
      int a;
      cin >> a;
      ans = (ans + a) % 3;
    }
    puts(ans == 0 ? "YES" : "NO");
  }  
}