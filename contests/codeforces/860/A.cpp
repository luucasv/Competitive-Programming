/*
  Solving icpc archive 2755
  O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

bool C(char c) {
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return false;
  return true;
}

int main() {
  string s, a = "";
  getline(cin, s);
  int cnt = 0;
  fr(i, 0, s.size()) {
    if (C(s[i])) {
      cnt++;
      if (cnt == 3) {
        if(s[i] == s[i-1] && s[i-1] == s[i-2])
          cnt--;
        else{
          cout << ' ';
          cnt = 1;
        }
      }
    } else {
      cnt = 0;
    }
    cout << s[i];
  }
  cout << endl;
}

