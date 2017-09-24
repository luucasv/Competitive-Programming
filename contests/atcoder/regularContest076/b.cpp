#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
const ll inf = ll(1e9) + 7;
const int ms = 1111111;

int rt[ms];
ii x[ms];
ii y[ms];
iii v[2*ms];

void init(int n){
	fr(i, 0, n+1)
		rt[i] = i;
}

int root(int a){
	if(rt[a] == a)
		return a;
	return rt[a] = root(rt[a]);
}

void conn(int a, int b){
	// dbg(a _ b)
	a = root(a), b = root(b);
	if(a == b)
		return;
	rt[a] = b;
}

bool check(int a, int b){
	return root(a) == root(b);
}


int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n){
		int a, b;
		cin >> a >> b;
		x[i] = ii(a, i);
		y[i] = ii(b, i);
	}

	sort(x, x+n);
	sort(y, y+n);

	ll ans = 0;
	init(n);
	fr(i, 0, n-1){
		v[i] = iii(x[i+1].X - x[i].X, ii(x[i].Y, x[i+1].Y));
	}
	fr(i, 0, n-1){
		v[n-1+i] = iii(y[i+1].X - y[i].X, ii(y[i].Y, y[i+1].Y));
	}
	sort(v, v + 2*(n-1));
	fr(k, 0, 2*(n-1)){
		ii a = v[k].Y;
		if(!check(a.X, a.Y)){
			ans += v[k].X;
			conn(a.X, a.Y);
		}
	} 
	cout << ans << endl;
	return 0;
}