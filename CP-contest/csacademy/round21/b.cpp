#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " _

using namespace std;

int cnt(int a){
	int ans = 0;
	for(int i = 2; a > 1 && i*i <= a; ++i){
		while(a % i == 0){
			ans++;
			a /= i;
		}
	}
	if(a != 1)
		++ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	int g = __gcd(a, b);
	a /= g;
	b /= g;
	cout << cnt(a) + cnt(b) << endl;
	return 0;
}