#include <bits/stdc++.h>
#define fr(a, b, c) for(ll a = b, __ = c; a < __; ++a)
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
int dist[20001],dad[20001];
int find(int x){
	if(dad[x]==-1)return x;
	int a=dad[x];
	dad[x]=find(dad[x]);
	dist[x]+=dist[a];
	return dad[x];
}
void unite(int a,int b){
	int A=find(a);
	int B=find(b);
	if(A!=a){swap(A,B);swap(a,b);}
	dad[a]=B;
	dist[a]=dist[b]+abs(a-b)%1000;
}
int main() {
	int t;
	freopen ("network.in","r+",stdin);
	freopen ("network.out","w+",stdout);
	scanf("%d", &t);
	fr(i,0,t){
		int x;
		scanf("%d", &x);
		memset(dad,-1,(x + 1) * sizeof(int));
		memset(dist,0,(x + 1) * sizeof(int));
		char s;
		while(scanf(" %c", &s), s != 'O'){
			if(s=='E'){
				int a;
				scanf("%d", &a);
				find(a);
				printf("%d\n", dist[a]);
			}else if(s=='I'){
				int a,b;
				scanf("%d %d", &a, &b);
				unite(a,b);
			}else break;
		
			
		}
	}
}