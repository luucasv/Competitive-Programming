/*
	Codeforces: 319C. Kalila and Dimna in the Logging Industry
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

string s;

int bb(int a, int b, int x, int y) {
	if (s == "LEFT") {
		int d = abs(y - b), need = (d + 1) / 2;
		x -= need;
		if (a < x) {
			d = abs(x - a);
			return need + d / 3 + (d % 3 != 0 ? 1 : 0);
		} else {
			return need + abs(x - a);
		}
	} else if (s == "RIGHT") { 
		int d = abs(y - b), need = (d + 1) / 2;
		x += need;
		if (a > x) {
			d = abs(x - a);
			return need + d / 3 + (d % 3 != 0 ? 1 : 0);
		} else {
			return need + abs(x - a);
		}
	} else if (s == "UP") {
		int d = abs(x - a), need = (d + 1) / 2;
		y += need;
		if (b > y) {
			d = abs(y - b);
			return need + d / 3 + (d % 3 != 0 ? 1 : 0);
		} else {
			return need + abs(y - b);
		}
	} else {
		int d = abs(x - a), need = (d + 1) / 2;
		y -= need;
		if (b < y) {
			d = abs(y - b);
			return need + d / 3 + (d % 3 != 0 ? 1 : 0);
		} else {
			return need + abs(y - b);
		}
	}
}

int main(){
	// ios::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	cin >> s;
	int n;
	string ans;
	int dans = 1e9;
	cin >> n;
	fr(i, 0, n) {
		string name;
		int a, b;
		cin >> name >> a >> b;
		if (bb(a, b, x, y) < dans) {
			dans = bb(a, b, x, y);
			ans = name;
		}
	}
	cout << ans << endl;
	return 0;
}