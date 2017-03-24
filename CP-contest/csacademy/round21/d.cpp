#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
__int128 gera(int mask, int k){
	__int128 ans = 0;
	for(int i = 26; i > -1; --i){
		ans *= 10;
		if((mask >> i)&1){
			ans += k;
		}
	}
	return ans;
}

string show(__int128 a){
	string ans = "";
	unsigned long long fs = (a >> 64), ed = a;
	if(fs)
		ans += to_string(fs);
	ans += to_string(ed);
	return ans;
}

string solve(int n, int k){
	fr(i, 1, (1 << 26)){
		if(gera(i, k)%n == 0){
			return show(gera(i, k));
		}
	}
	return "0";
}

int main(){
	ios::sync_with_stdio(0);
	/*fr(i, 99999, 100000)
		fr(j, 1, 10)
			cout << i _ j _ solve(i, j) << endl;*/
	int k, n;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}