#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long double ld;

int gas[111111];

int main(){
	int n, m;
	cin >> n >> m;
	memset(adj, -1, sizeof adj);
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	
}