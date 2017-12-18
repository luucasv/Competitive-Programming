#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> mp;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    mp[a]++;
  }
  int ans = 0;
  for (auto it : mp) {
    if (it.first > it.second) {
      ans += it.second;
    } else if (it.first < it.second) {
      ans += it.second - it.first;
    }
  }
  cout << ans << endl;
}