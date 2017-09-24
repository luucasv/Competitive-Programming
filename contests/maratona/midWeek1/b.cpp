#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define X first
#define Y second
#define _ << " , " <<
#define pb push_back
using namespace std;
const double EPS=1e-12;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ii,ii> elem;// precisa,delta,valor
vector<elem> up ,down;
elem process(string s, int i){
  int c=0,p=0;
  for(auto k:s){
    if(k==')')c--;
    else c++;
  }
  if(c<0){
    reverse(s.begin(),s.end());
    int mgc=0;
    for(auto k:s){
      if(k=='('){
        if(mgc==0)p++;
        else mgc--;
      }else mgc++;
    }
  }else{
    int mgc;
    for(auto k:s){
      if(k==')'){
        if(mgc==0)p++;
        else mgc--;
      }else mgc++;
    }
  }
  return elem(ii(p, i),ii(c,s.size()));
}
int knapup[1000][5010],knapdown[1000][5010];
int main() {
  int n;
  cin>>n;
  fr(i,0,n){
    string s;
    cin>>s;
    elem x=process(s,i);
    if(x.Y.X>=0)up.pb(x);
    else down.pb(x);
  }
  memset(knapup,~(0x3f),sizeof knapup);
  knapup[0][0]=0;
  sort(up.begin(),up.end());
  for(int oi = 1; oi <= up.size(); oi++){
    elem k = up[oi-1];
    fr(i,0,5001)
      knapup[oi][i]=knapup[oi-1][i];
    for(int i=5000;i>=k.X.X+k.Y.X;i--){
      if(knapup[oi][i] < knapup[oi-1][i-k.Y.X]+k.Y.Y){
        knapup[oi][i] = knapup[oi-1][i-k.Y.X]+k.Y.Y;
      }
    }
  }
  
  memset(knapdown,~(0x3f),sizeof knapdown);
  knapdown[0][0]=0;
  sort(down.begin(),down.end());
  for(int oi = 1; oi <= down.size(); oi++){
    elem k = down[oi-1];
    fr(i,0,5001)
      knapdown[oi][i]=knapdown[oi-1][i];
    for(int i=5000;i>=k.X.X-k.Y.X;i--){
      if(knapdown[oi][i] < knapdown[oi-1][i+k.Y.X]+k.Y.Y){
        knapdown[oi][i] = knapdown[oi-1][i+k.Y.X]+k.Y.Y;
      }
    }
  }
  int mx=0, best = 0;
  int upk=max(int(up.size()),0);
  int dwk=max(int(down.size()),0);
  fr(i,0,5001){
    if(mx < knapup[upk][i]+knapdown[dwk][i]){
      best = i;
      mx=knapup[upk][i]+knapdown[dwk][i];
    }
  }
  vector<int> ans;
  int xx=int(up.size()),yy=best;
  while(xx>0){
    if(xx){
      if(knapup[xx][yy]!=knapup[xx-1][yy]){
        ans.pb(up[xx-1].X.Y);
        yy-=up[xx-1].Y.X;
      }
    }
    xx--;
  }
  reverse(ans.begin(), ans.end());
  xx=int(down.size()),yy=best;
  while(xx>=0){
    if(xx){
      if(knapdown[xx][yy]!=knapdown[xx-1][yy]){
        ans.pb(down[xx-1].X.Y);
        yy+=down[xx-1].Y.X;
      }
    }
    xx--;
  }
  cout<<mx << ' ' << ans.size() <<endl;
  if(ans.size())
    cout << ans[0]+1;
  fr(i, 1, ans.size()){
    cout << ' ' << ans[i]+1;
  }
  cout << endl;
}