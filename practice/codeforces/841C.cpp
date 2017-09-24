#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int ms = 211111;
int a[ms], ans[ms];
ii b[ms];

int main(){
	ios::sync_with_stdio(0);
	int m;
	cin >> m;
	fr(i, 0, m){
		cin >> a[i];
	}
	fr(i, 0, m){
		cin >> b[i].X;
		b[i].Y = i;
	}
	sort(b, b+m);
	sort(a, a+m, greater<int>());
	fr(i, 0, m){
		ans[b[i].Y] = a[i];
	}
	fr(i, 0, m)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
