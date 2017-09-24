#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(0);
	ll a, s, k, x, y;
	cin >> a >> s >> k >> x >> y;
	ll den = x + y, num = k * y + s - a;
	if(num % den != 0){
		cout << "-1\n";
		return 0;
	}
	ll i = num / den, j = k - i;
	if(i < 0 || j < 0){
		cout << "-1\n";
	}
	else{
		cout << i << endl;
	}
	return 0;
}