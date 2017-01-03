/*
	Codeforces: E. Inversions After Shuffle
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b, c) for(int a = b, __ = c; a >= __; --a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

const int mv = 111111;
ll BIT[mv], v[mv];
int n;

void updt(int x, ll v){
	while(x <= n){
		BIT[x] += v;
		x += x & -x;
	}
}

ll sum(int x){
	ll ret = 0;
	while(x > 0){
		ret += BIT[x];
		x -= x & -x;
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i, 0, n)
		cin >> v[i];

	ll total = 0;
	fre(i, n-1, 0){
		total += sum(v[i]);
		updt(v[i], 1);
	}

	memset(BIT, 0, sizeof BIT);

	ll subtotal = 0, at = 0, acc = 0;
	fr(i, 1, n+1){
		at += ll(n - i + 1)*(i)*(i-1);
	}

	fre(i, n-1, 0){
		acc += sum(v[i]);
		subtotal += acc;
		updt(v[i], n - i);
	}

	printf("%.20lf\n", total + (- subtotal + at/4.0 )/double((ll(n)*(n+1LL))/2LL));
	return 0;
}