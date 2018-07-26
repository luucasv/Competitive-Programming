#include <bits/stdc++.h>

using namespace std;

const int ms = 1e6 + 20;

int main() {
  int n, k;
  cin >> n >> k;
  int g = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf(" %d", &a);
    if (a) g = __gcd(a, g);
  }
  g %= k;
  set<int> st;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    st.insert(sum);
    sum += g;
    if (sum >= k) sum -= k;
  }
  cout << st.size() << endl;
  for (auto it : st) {
    printf("%d ", it);
  }
  puts("");
}
