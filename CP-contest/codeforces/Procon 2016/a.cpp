#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int v[3], d;
	cin >> v[0] >> v[1] >> v[2] >> d;
	sort(v, v+3);
	if(v[2] + v[1] >= d)
		puts("YES");
	else
		puts("NO");
	return 0;
}