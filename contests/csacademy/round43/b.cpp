#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
const int ms = 1e5  + 20;
int v[ms], hor[ms], dif[ms];

int main(){
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	fr(i, 0, n){
		cin >> hor[i+1];
	}
	fr(i, 0, m){
		cin >> v[i+1];
	}
	hor[n+1] = h;
	v[m+1] = w;
	sort(hor, hor + n + 2);
	sort(v, v + m + 2);
	fr(i, 0, n+1){
		dif[hor[i+1] - hor[i]]++;
		// cout << hor[i+1] - hor[i] << endl;
	}
	long long ans = 0;
	fr(i, 0, m+1){
		int d = v[i+1] - v[i];
		// cout << "d = " <<  d << endl;
		ans += dif[d];
	}
	cout << ans << endl;
}