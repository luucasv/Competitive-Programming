#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a); i < (b); ++i)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define X first
#define Y second
#define pb push_back
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define scs(a) scanf("%s", a)
#define mp make_pair

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long int ll;

const int ms = 21, inf = 0x3f3f3f3f;
int comb[ms][ms];
int n, k;

void go(int at, int left){
	cout << "+" << at+1;
	if(n - at - 1 >= k-1)
		go(at+1, k-1);
	if(n-at-1 >= k){
		cout << "++" << at+1;
		go(at+1, k);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	s
}