#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

double memo[11111][1111];
int mk[11111][1111];
int k, q;
double dp(int d, int a){
	if(d < a)
		return 0.0;
	if(a == 0)
		return 1.0;
	if(mk[d][a])
		return memo[d][a];
	mk[d][a] = 1;

	double ans = a * dp(d-1, a-1)  + (k - a) * dp(d-1, a);
	return memo[d][a] = ans / k;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> k >> q;
	fr(i, 0, q){
		double p;
		cin >> p;
		int lo = 0, hi = 11110;
		while(hi - lo > 1){
			int m = (hi+lo)/2;
			if(dp(m, k)*2000 < p)
				lo = m;
			else
				hi = m;
		}
		if(dp(lo, k) < p)
			lo = hi;
		cout << lo << endl;
	}
	return 0;
}