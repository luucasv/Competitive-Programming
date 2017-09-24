
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll f(ll a, ll b){
	if(a == 1)
		return b;
	if(b <= 0)
		return 0;
	dbg(a _ b)
	ll g = __gcd(a, b), x = a / g, mi = 1e15;
	// dbg(g)
	for(ll i = 2; i*i <= x; i++){
		if(x % i)
			continue;
		while(x%i == 0)
			x /= i;
		mi = min(mi, (b/g)%i);
	}
	if(x > 1){
		mi = min(mi, (b/g)%x);
	}
	if(mi == 1e15)
		mi = 1;
	if(a == g)
		mi = b / g;
	if(x == a && b < a){
		return b;
	}
	return mi + f(a, b - mi * g);
}

int main(){
	ios::sync_with_stdio(0);
	ll x, y;
	cin >> x >> y;
	cout << f(x, y) << endl;
}