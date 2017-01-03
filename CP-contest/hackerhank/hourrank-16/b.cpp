#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

const int ms = 11111;
int c[ms];

int main(){
	ios::sync_with_stdio(0);
	int q;
	cin >> q;
	ll n;
	while(q--){
		cin >> n;
		int ok = 0;
		fr(i, 0, 4){
			if((n - i*7) > 0 && (n - i*7)%4 == 0)
				ok = 1;
		}
		puts(ok ? "yes" : "no");
	}
	return 0;
}