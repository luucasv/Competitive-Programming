#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int s = 0;
	fr(i, 0, n){
		int a;
		cin >> a;
		s += a%2;
	}
	if(s == 0)
		puts("Second");
	else
		puts("First");
	return 0;
}
