#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define r1 ^
#define r2 |
#define r3 & 

using namespace std;
typedef long long ll;

int main(){
	int a, b, d, c;
	cin >> a >> b >> c >> d;
	cout << (((a r1 b) r3 (c r2 d)) r1 ((b r3 c) r2 (d r1 a))) << endl; 
}