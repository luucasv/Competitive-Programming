#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long double ld;


int main(){
	int n;
	cin >> n;
	if(n%4 == 0 || n%4 == 3){
		int d = n/4;
		string str = "+--+", ans = "";
		if(n&1){
			ans = "--+";
		}
		fr(i, 0, d)
			ans += str;
		cout << ans << endl;
 	}
	else{
		cout << -1 << endl;
	}
}