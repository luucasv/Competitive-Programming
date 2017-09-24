#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

const int ms = 11111;
int c[ms];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> c[i];

	sort(c, c+n);
	if(n == 1){
		cout << c[0] << " 1\n";
		return 0;
	}
	int ans = 0;
	while(ans < n && c[ans] == c[0]) ++ans;
	if(ans > 1)
		cout << c[0] << ' ' << n << endl;
	else
		cout << min(c[0]*2, c[1]) << " " << 1 << endl;
	return 0;
}