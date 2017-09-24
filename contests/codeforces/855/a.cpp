#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

int main() {
  set<string> st;
  string s;
  int n;
  cin >> n;
  fr(i, 0, n) {
    cin >> s;
    if (st.count(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    st.insert(s);
  }
}