#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second
#define pb push_back
using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;
int arr[1002][1002];
int up[1002][1002];
int main() {
	int n,m;
	// freopen ("citygame.in","r+",stdin);
	// freopen ("citygame.out","w+",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%d%d", &n,&m);
		memset(arr,0,sizeof arr);
		memset(up,0,sizeof up);
		fr(i,0,max(n,m)+1){
			//cout<<i<<endl;
			arr[i][0]=1;
			arr[0][i]=1;
		}
		fr(i,0,n)fr(j,0,m){
			char c;
			scanf(" %c",&c);
			if(c=='R')arr[i+1][j+1]=1;
		}
		int best=0;
		stack<ii> v;/*
		fr(i,0,n+1){
			fr(j,0,m+1){
				cout<<arr[i][j];
			}
			cout<<endl;
		}*/
		fr(i,1,n+1){
			v.push(ii(0,0));
			fr(j,1,m+1){
				if(arr[i][j]) up[i][j]=0;
				else up[i][j]=up[i-1][j]+1;
				//cout<<i<<","<<j<<" "<<up[i][j]<<" "<<arr[i][j]<<endl;
				int lng=j;
				while(!v.empty() && v.top().X>=up[i][j]){
					best = max(best,v.top().X*(j-v.top().Y));
					lng = min(lng,v.top().Y);
					/*cout<<"i: "<<i<<"j: "<<j;
					cout<<"vx:"<<v.top().X;
					cout<<"vy:"<<v.top().Y;
					cout<<"up:"<<up[i][j];
					cout<<endl;*/
					v.pop();
					
				}
				v.push(ii(up[i][j],lng));	
			}
			while(!v.empty()){
				best=max(best,v.top().X*(m+1-v.top().Y));
				v.pop();
			}
		}
		cout<<best*3<<endl;
	}
}