#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ma = int(1e7);
typedef pair<int, int> ii;
int p[1111111];

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int a = n-1, x = a / k, j = a%k;
	int ans = 2*x;
	if(j > 0)
		++ans;
	if(j > 1)
		++ans;
	cout << ans << endl;
	fr(i, 0, k){
		cout << 1 << ' ' << i+2 << endl;
		p[i] = i+2;
	}
	int at = 0;
	fr(i, k+2, n+1){
		cout << p[at] << ' ' << i << endl;
		p[at] = i;
		at = (at + 1)%k;
	}
	return 0;
}