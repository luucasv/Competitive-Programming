#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	if((n / k)&1)
		puts("YES");
	else
		puts("NO");
	return 0;
}