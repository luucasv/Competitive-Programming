#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	string a, b, c, d;
	cin >> a >> b;
	int n;
	cin >> n;
	cout << a << " "  << b << endl;
	while(n--){
		cin >> c >> d;
		if(a == c)
			a = d;
		else
			b = d;
		cout << a << " "  << b << endl;
	}
	return 0;
}