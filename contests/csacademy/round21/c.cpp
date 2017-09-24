#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " _

using namespace std;

int v[111111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> v[i];
	sort(v, v+n, greater<int>());
	fr(i, 1, n){
		if(i+1 >= n)
			break;
		swap(v[i], v[i+1]);
		++i;
	}
	cout << v[0];
	fr(i,1,n)
		cout << " " << v[i];
	cout << endl;
	return 0;
}