#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 111111, inf = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef long long int ll;

ll a[ms];

int main(){
	ios::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	fr(i, 0, n)
		cin >> a[i];
	sort(a, a+n);
	ll has = 0;
	fr(i, 0, n){
		if(k >= (a[i] + 1)/ 2){
			k = max(k, a[i]);
		}
		else{
			++has;
			k *= 2;
		}
	}
	cout << has << endl;
	return 0;
}