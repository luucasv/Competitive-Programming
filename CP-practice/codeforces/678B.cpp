/*
	Codeforces: 67B. Remainders Game
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

long long lcm(long long a, long long b){
	return a*b / __gcd(a, b);
}

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	long long at = 1;
	fr(i, 0, n){
		long long c;
		cin >> c;
		at = __gcd(lcm(at, c), (long long) k);
	}
	if(at%k == 0)	
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}