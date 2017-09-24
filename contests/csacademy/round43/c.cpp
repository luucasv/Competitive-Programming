#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long double ld;

int gas[111111];

int main(){
	int d, l, n;
	cin >> d >> l >> n;
	fr(i, 0, n)
		cin >> gas[i];
	gas[n++] = 0;
	gas[n++] = d;
	long double p = 1.0 / ((long double) d); 
	sort(gas, gas + n);
	ld  ans = 0;
	fr(i, 0, n-1){
		int a = gas[i], b = gas[i+1];
		if(a + l >= b)
			continue;
		ld st = a+l, md = (a + l + b)/((ld) 2), ed = b;
		ld s1 = (md * md / 2 - l*md - a*md- (st * st / 2 - l*st - a*st))*p;
		ld s2 = (b*ed - ed * ed / 2 - (b*md - md * md / 2))*p;
		ans += s1 + s2;
	}
	cout << fixed << setprecision(10) << ans << endl;
}