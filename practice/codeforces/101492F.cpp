#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long double ld;


int main(){
	int r;
	cin >> r;
	r *= r;
	int ans = 0;
	fr(k, 0, 3){
		int x, y;
		cin >> x >> y;
		int d = x*x + y*y;
		int aux = r, i = 0;
		while(i < 10 && d > aux){
			i++;
			aux = (i+1)*(i+1)*r;
		}
		ans += 10 - i;
	}
	cout << ans << endl;
}