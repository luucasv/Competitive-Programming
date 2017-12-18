#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  fr(i, 0, n) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  int sum = 0;
  fr(i, 1, v.size() - 1) {
    sum += v[i];
  }
  cout << sum / (n - 2) << endl;
}