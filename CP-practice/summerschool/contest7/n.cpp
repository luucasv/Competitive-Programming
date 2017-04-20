#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	double s, p;
	cin >> s >> p;
	int ans = -1;
	if(s == p)
		ans = 1;
	else if(4*p <= s*s)
		ans = 2;

	fr(i, 2, 10000){
		if(pow(s/i, i) >= p - 1e-5){
			if(ans == -1)
				ans = i;
		}
	}

	cout << ans << endl;

	return 0;
}