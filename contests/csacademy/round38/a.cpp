#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

int cnt[111][3];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n){
		int s;
		char ch;
		cin >> s >> ch;
		if(ch == 'L'){
			cnt[s][0]++;
		}
		else{
			cnt[s][1]++;
		}
	}
	int ans = 0;
	fr(i, 0, 111){
		ans += min(cnt[i][0], cnt[i][1]);
	}
	cout << ans << endl;
	return 0;
}