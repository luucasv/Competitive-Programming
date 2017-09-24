#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;

int cnt[500];

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	fr(i, 0, n){
		char c;
		cin >> c;
		cnt[c]++;
	}

	fr(i, 'a', 'z'+1){
		if(cnt[i] > k){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
