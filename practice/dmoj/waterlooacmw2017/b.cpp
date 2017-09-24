#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>>> " << x << endl;
#define _ << " , " <<
using namespace std;
int cnt[50];

int main(){
  int n, k;
  string a;
  cin >> n >> k >> a;
  string b = string(a.size(), 'A');
  if(k > n){
    cout << "WRONGANSWER" << endl;
  }
  else if(k == n){
    cout << a << endl;
  }
  else{
    std::vector<pair<int, int>> v;
    fr(i, 0, n){
      cnt[a[i] -  'a']++;
    }
    fr(i, 'a', 'z'+1){
      v.push_back(make_pair(cnt[i - 'a'], i));
    }
    sort(v.begin(), v.end());
    int c = 0;
    if(v[0].first > k){
      cout << "WRONGANSWER" << endl;
      return 0;
    }
    int i = 0;
    while(c < k){
      fr(j, 0, n){
        if(a[j] == v[i].second && c < k){
          // dbg(a[j] _ char(v[i].second))
          b[j] = a[j];
          c++;
        }
      }
      i++;
    }
    fr(i, 0, n){
      if(b[i] == 'A'){
        b[i] = v[0].second;
      }
    }
    cout << b << endl;
  }
}