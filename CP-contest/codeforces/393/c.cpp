#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long int ll;

const int ms = 111111;

int t[ms];
ll sum[ms], at;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	fr(i, 0, n){
		cin >> p[i] >> t[i];
		if(t[i])
			cin >> v[i];
		else
			v[i] = -1;
	}

	return 0;
}