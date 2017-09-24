#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	string s, t;
	int a, b;
	cin >> a >> b;
	cin >> s >> t;
	int ans = a+100, st;
	fr(i, 0, b){
		if(i + a-1 >= b)
			break;
		int c = 0;
		fr(j, 0, a){
			if(s[j] == t[i+j])
				++c;
		}
		if(a - c < ans){
			st = i;
			ans = a - c;
		}
	}
	cout << ans << endl;
	fr(j, 0, a){
		if(s[j] != t[st+j])
			cout << j+1 << ' ';
	}
	cout << endl;
	return 0;
}