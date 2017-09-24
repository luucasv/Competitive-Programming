/*
  Solving icpc archive 2755
  O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

map<string, int> cnt;

int main() {
  int n;
  cin >> n;
  fr(k, 0, n){
    cin >> num[k]];
    set<string> st;
    fr(i, 0, 9) {
      fr(j, i, 9) {
        if(!st.count(num[k]].substr(i, j-i+1))){
          cnt[num[k]].substr(i, j-i+1)]++;
          st.insert(num[k]].substr(i, j-i+1));
        }
      }
    }
  }
  fr(k, 0, n){
    string ans = num[k];
    fr(i, 0, 9) {
      fr(j, i, 9) {
        if(cnt[num[k].substr(i, j-i+1)] == 1 && ans.size() > j-i+1) {
          ans = num[k].substr(i, j-i+1);
        }
      }
    }
    cout << ans << endl;
  }

}

