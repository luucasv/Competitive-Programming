#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>>> " << x << endl;
#define _ << " , " <<
using namespace std;
int p[101];

bool check(int p[], int n, int l){
  fr(i, 0, n){
    if(i+l >= n)
        return true;
    if(p[i] < p[i+l])
      return false;
  }
  return true;
}

int main(){
  int n, k;
  cin >> n >> k;
  if(n == 2){
    puts("2 1");
    return 0;
  }
  if(k <= (n-1)/2){
    puts("0");
    return 0;
  }
  int l = (n-1)/2+1;
  fr(i, 0, n/2){
    p[i] = 2*(i+1);
  }
  if(n&1){
    p[n/2] = n;
  }
  int st = n/2 + n%2;
  fr(i, st, n){
    p[i] = 2*(i - st) + 1;
  }
  int at = n/2 - 1;
  while(l < k){
    int aa = p[n-1];
    for(int i = n-1; i > at; i--){
      p[i] = p[i-1];
    }
    p[at] = aa;
    --at;
    ++l;
  }
  cout << p[0];
  fr(i, 1, n)
    cout << " " << p[i];
  cout << endl;
}