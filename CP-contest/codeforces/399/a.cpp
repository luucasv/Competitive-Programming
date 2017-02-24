#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int v[111111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> v[i];

	sort(v, v+n);
	int i = 0, j = n-1;
	while(i < n && v[0] == v[i]) ++i;
	while(j >= i && v[n-1] == v[j]) --j;
	cout << j - i + 1 << endl;
	return 0;
}