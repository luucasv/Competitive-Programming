#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int mv = 111111, me = 2*mv;
int ant[me], to[me], adj[mv];
int cap[me];

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	
}

int main(){
	ios::sync_with_stdio(0);
	/*fr(i, 99999, 100000)
		fr(j, 1, 10)
			cout << i _ j _ solve(i, j) << endl;*/
	int k, n;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}