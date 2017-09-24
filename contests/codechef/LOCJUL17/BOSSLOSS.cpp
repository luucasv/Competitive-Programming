#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;

ll sum(ll x){
	return (x * (x + 1)) / 2;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		ll n,m;
		cin >> n >> m;
		ll lo = 1, hi = min(ll(2e9 + 100), n);
		while(hi - lo > 1){
			ll md = (hi + lo) / 2;
			if(sum(md) >= m)
				hi = md;
			else
				lo = md;
		}
		if(sum(lo) < m)
			lo = hi;
		if(sum(lo) < m)
			lo = -1;
		cout << lo << endl;
	}
	return 0;
} 