#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int v[111111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> v[i];

	sort(v, v+n);
	int ok = 0;
	fr(i, 0, n-2){
		if(v[i] + v[i+1] > v[i+2]){
			ok = 1;
		}
	}

	puts(ok ? "YES" : "NO");
	return 0;
}