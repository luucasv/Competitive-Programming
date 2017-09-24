#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>>> " << x << endl;
#define _ << " , " <<
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll memo[31][901], memo2[31][901];

ll dp2(int n,int k){
    if(n>k)return 0;
    if(n<0)return 0;
  if(n==k)return 1;
    if(n==0)return 1;
    if(memo2[n][k] != -1)
      return memo2[n][k];
    return memo2[n][k] = dp2(n,k-1)+dp2(n-1,k-1);
}
ll dp(int n, int k){
  if(n == 0)
    return (k == 0) ? 1 : 0;
  if(n == 1)
    return (k == 1) ? 1 : 0;
  if(n > k)
    return 0;
  if(memo[n][k] != -1)
    return memo[n][k];
 // if(n==k)return n==1;
  if(k>n*(n+1)/2)return 0;
  ll ans = 0;
  int nk = k - n;
  fr(i, 0, n){
    fr(kk, 0, nk+1){
      ans = (ans + ((dp2(i,n-1)*dp(i, kk))%mod) * dp(n-i-1, nk - kk))%mod;
      //ans = (ans + dp(i, nk - kk) * dp(n-i-1, kk))%mod;
    }
  }
  return memo[n][k] = ans;
}

int main(){
  int n, k;
  cin >> n >> k;
  memset(memo, -1, sizeof memo);
  memset(memo2, -1, sizeof memo2);
  cout << dp(n, k) << endl;
}