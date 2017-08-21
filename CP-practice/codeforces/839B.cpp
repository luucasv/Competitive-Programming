#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int fours = 0, twos = 0, ones = 0;
	fr(i, 0, k){
        int a;
		cin >> a;
		fours += a / 4;
		a %= 4;
		if(a == 3){
			fours++;
		}
		else if(a == 2){
			twos++;
		}
		else if(a == 1){
			ones++;
		}
	}
	int u = min(twos, ones);
	twos -= u, ones -= u;
	fours += ones / 2;
	ones %= 2;
	twos += ones;
	fours += u;
	ones = 0;
	if(fours > n){
		int q = fours - n;
		twos += 2 * q;
		fours = n;
	}
	else if(fours < n){
		int q = n - fours;
		q /= 2;
		q = min(q, twos / 3);
		twos -= 3 * q;
		fours += 2 * q;
	}
	puts(fours + twos <= 3 * n ? "YES" : "NO");
	return 0;
}
