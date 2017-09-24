#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define X first
#define Y second
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

int getspt(string s){
  fr(i,0,s.size()){
    if(s[i]=='-')return i;
  }
}
int main() {
  vector<string> l;
  map<string,int> mapa;
  string s,t;
  ull x;cin>>x;
  getline(cin,s);
  fr(i,0,x){
    getline(cin,s);
    l.pb(s);
    fr(k,0,20){
      string st;
      getline(cin,st);
      int y,ss=getspt(st);
      s=st.substr(0,ss);
      y=atoi(st.substr(ss+1,s.size()-ss-1).c_str());
      //cout<<"("<<s<<")"<<"("<<y<<")";
      mapa[s]+=y;
    }
  }
  vector<pair<int,string> > vc;
  for(map<string,int>::iterator k = mapa.begin(); k != mapa.end(); k++){
    vc.pb(make_pair(-k->Y,k->X));
  }
  sort(vc.begin(),vc.end());
  cout<<"Os 10 melhores do ano de ";
  if(l.size()==1){
    cout<<l[0];
  }else{
    sort(l.begin(),l.end());
    fr(i,0,l.size()-2)cout<<l[i]<<", ";
    cout<<l[l.size()-2]<<" e "<<l[l.size()-1];
  }
  cout<<":"<<endl;
  fr(i,0,10){
    cout<<i+1<<" - "<<vc[i].Y<<"- "<<-vc[i].X<<endl;
  }
}