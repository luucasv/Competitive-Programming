#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<
using namespace std;
typedef long long ll;
const int inf = int(1e7);
const int mm = 16;

ll v1[1 << mm], v2[1 << mm];
ll val[40];

ll calc(int mask, int off){
	ll ans = 0;
	fr(i, 0, mm){
		if(mask&(1 << i)){
			ans += val[i + off];
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	val[1] = 2;
	val[2] = 7;
	fr(i, 3, 34){
		if(i%2){
			val[i] = val[i-1] + 3 * val[i-2];
		}
		else{
			val[i] = val[i-1] + 7;
		}
	}
	int sz = 0;
	fr(i, 0, 1 << mm){
		v1[sz++] = calc(i, 1);
	}
	sz = 0;
	fr(i, 0, 1 << mm){
		v2[sz++] = calc(i, mm + 1);
	}
	sort(v1, v1 + sz);
	sort(v2, v2 + sz);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		bool ok = 0;
		fr(i, 0, sz){
			if(binary_search(v2, v2 + sz, n - v1[i])){
				ok = 1;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
} 