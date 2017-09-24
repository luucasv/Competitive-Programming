/*
	Solving icpc archive 2755
	O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef __int128 ll;
const int ms = 1e4 + 30;

ll my_sqrt(ll x) {
	ll lo = 0, hi = 1;
	while (hi * hi < x) {
		lo = hi;
		hi <<= 1;
	}
	while (hi - lo > 0) {
		ll md = (lo + hi) / 2;
		if (md * md == x){
			return md;
		}	else if (md * md < x) {
			lo = md + 1;
		} else {
			hi = md - 1;
		}
	}
	return lo;
}

struct PT {
	ll x, y;
	void read() {
		int a, b;
		cin >> a >> b;
		x = a, y = b;
	}
	ll dist(const PT &p) {
		ll dx = x - p.x, dy = y - p.y;
		return my_sqrt(dx * dx + dy * dy);
	}
};

ll dist[ms], acc[ms];
PT pts[ms];

int main() {
	int t;
	cin >> t;
	cout << setprecision(2) << fixed;
	while(t--) {
		int n;
		cin >> n;
		pts[0].read();
		fr(i, 1, n) {
			pts[i].read();
			dist[i - 1] = pts[i].dist(pts[i-1]);
		}
		dist[n-1] = pts[0].dist(pts[n-1]);
		ll a = n, b = 0, c = 0;
		acc[0] = 0;
		fr(i, 1, n) {
			acc[i] = dist[i-1] - acc[i-1]; // dist[i] O(2e4), acc[i] O(1e8)
			if (i&1) {
				b -= 2 * acc[i];
			} else {
				b += 2 * acc[i]; // b é O(2e16)
			}
			c += acc[i] * acc[i]; // c eh
		}
		if (n&1) {
			ll A2=(dist[n-1] - acc[n-1]);
			int ok = 1;
			fr(i,0,n){
				if(i&1){
					if(acc[i]*2-A2 < 0 || acc[i]*2-A2 > dist[i]*2 || acc[i]*2-A2 > 2*dist[i-1]){
						ok = 0;
					}
				}
				else {
					if(acc[i]*2+A2 < 0 || acc[i]*2+A2 > dist[i]*2 || acc[i]*2+A2 > 2*dist[(i + n - 1)%n]){
						ok = 0;
					}
				}
			}
			if(!ok) {
				puts("IMPOSSIBLE");
				continue;
			}
			long double A = A2 / 2.0L;
			cout << acosl(-1.0) * (A*A*a+b*A+c) << endl;
			fr(i,0,n){
				if(i&1){
					cout << max(0.0L,acc[i]-A) << endl;
				}
				else { 
					cout << max(0.0L,acc[i]+A) << endl;
				}
			}
		} else {
			ll lo = 0, hi = min(dist[0], dist[n-1]);
			fr(i,1,n){
				if(i&1){
					lo = max(lo,-dist[i]+acc[i]);
					lo = max(lo,-dist[i-1]+acc[i]);
					hi = min(hi,acc[i]);
				}else{
					hi = min(hi,dist[i]-acc[i]);
					hi = min(hi,dist[i-1]-acc[i]);
					lo = max(lo,-acc[i]);
				}
			}
			if(hi < lo) {
				puts("IMPOSSIBLE");
				continue;
			}
			ll AA = -b;
			if(AA < 2 * n * lo) {
				AA = lo * 2 * n;
			} else if (AA > 2 * n * hi) {
				AA = hi * 2 * n;
			}
			long double A = AA / (2.0L * a);
			cout << acosl(-1.0) * (A*A*a+b*A+c) << endl;
			fr(i,0,n){
				if(i&1){
					cout << max(0.0L,acc[i]-A) << endl;
				}
				else { 
					cout << max(0.0L,acc[i]+A) << endl;
				}
			}
		}
	}
}

