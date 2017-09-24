#include <bits/stdc++.h>
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 
#define fr(a, b, c) for(int (a) = (b), __ = c; a < __; ++a)

using namespace std;
typedef long long ll;

ll getSum(ll x){
	ll sum = 0;
	while(x > 0){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	ll n, s;
	cin >> n >> s;
	if(n - getSum(n) < s){
		cout << "0\n";
		return 0;
	}
	ll num = n;
	ll pot = 1;
	while(n/pot > 9)
		pot *= 10;
	while(pot > 0){
		while(num/pot > 0 && (num - pot) - getSum(num-pot) >= s)
			num -= pot;
		pot /= 10;
	}
	cout << n - num + 1 << endl;
	return 0;
}