#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 111111, inf = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef long long int ll;

int main(){
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0, ans = 0;
	fr(i, 0, n){
		cnt = 0;
		int j = i;
		while(j < n && s[j] == '1') ++cnt, ++j;
		ans *= 10;
		ans += cnt;
		i = j;
	}
	if(s[n-1] == '0')
		ans *= 10;
	cout << ans << endl;
	return 0;
}