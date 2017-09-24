#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ios::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	if(a == b){
		cout << -1 << endl;
	}
	else{
		cout << max(a.size(), b.size()) << endl;
	}

	return 0;
}