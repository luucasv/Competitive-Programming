#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int ans = int(1e6);
	int n;
	cin >> n;
	fr(i, 0, n){
		int a, b, c;
		cin >> a >> b >> c;
		ans = min(ans, max(a, b) + c);
	}
	cout << ans << endl;
}