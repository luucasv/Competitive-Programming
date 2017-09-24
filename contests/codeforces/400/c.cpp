#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = int(1e5) + 10;
const ll mv = ll(1e15) + 20;
int n, k;
ll a[ms];
map<ll, ll> cnt;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	fr(i, 0, n)
		cin >> a[i];
	ll sum = 0, ans = 0;
	cnt[0]++;
	fr(i, 0, n){
		sum += a[i];
		for(ll pot = 1LL; llabs(pot) < mv; pot *= ll(k)){
			ll need = sum - pot;
			if(cnt.count(need))
				ans += cnt[need];
			if(k == 1)
				break;
			if(k == -1 && pot == -1LL)
				break;
		}
		cnt[sum]++;
	}
	cout << ans << endl;
	return 0;
}