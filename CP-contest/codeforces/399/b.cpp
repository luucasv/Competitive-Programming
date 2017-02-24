#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
ll n, l, r, ans = 0;

int get(ll a){
	fr(i, 0, 51){
		if((1LL << i)&a)
			return i;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> l >> r;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}

	int maior = 0;
	fr(i, 0, 51){
		if((1LL << i)&n)
			maior = i;
	}
	for(ll i = l; i <= r; ++i){
		ans += (n >> (maior - get(i)))&1;
	}

	cout << ans << endl;
	return 0;
}