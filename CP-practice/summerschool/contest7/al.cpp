#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
const int iter=100000;
using namespace std;
double save[50][iter];
int mkd[50][iter];
int n;
double color(int a,int r){
    int b=n-a;
    if(a>n)return 0;
    if(b==0)return r;
    if(a==0)return 0;
    if(r==iter)return 0;
    if(mkd[a][r])return save[a][r];
    mkd[a][r]=1;
    return save[a][r]=((a*b)*color(a-1,r+1)+b*(b-1)*color(a,r+1)+(b*a)*color(a+1,r+1)+a*(a-1)*color(a,r+1))/double((a+b)*(a+b-1));
}
int arr[26];
int main(){
    string s;
    cin>>s;n=s.size();
    double tot=0;
    fr(i,0,s.size())arr[s[i]-'A']++;
    fr(i,0,26)tot+=color(arr[i],0);
    cout.precision(8);
    cout<<fixed<<tot<<endl;
}