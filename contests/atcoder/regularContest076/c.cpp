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

struct Point{
	ll x, y;
	int id;
	Point(ll x, ll y, int id):x(x), y(y), id(id){}
	
	ll operator%(Point &p) const {
		return x*p.y - y*p.x;
	}

	ll operator!(){
		return x*x + y*y;
	}
};

bool operator<(Point p1, Point p2){
	ll pv = p1 % p2;
	if(pv == 0){
        if(p1.y == 0)
			return !(p1) > !(p2);
        else 
        	return !(p1) < !(p2);
	}
	else{
		return pv > 0;
	}
}

int mk[ms];

int main(){
	ios::sync_with_stdio(0);
	int r, c, n;
	cin >> r >> c >> n;
	vector<Point> v;
	fr(i, 0, n){
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bool b1 = x1 == 0 || x1 == r || y1 == 0 || y1 == c,
		b2 = x2 == 0 || x2 == r || y2 == 0 || y2 == c;
		if(b1 && b2){
			v.push_back(Point(x1, y1, i));
			v.push_back(Point(x2, y2, i));
		}
	}
	sort(v.begin(), v.end());
	bool ok = 1;
	stack<int> pilha;
	for(Point p : v){
		if(pilha.empty()){
			pilha.push(p.id);
		}
		else if(pilha.top() != p.id){
			pilha.push(p.id);
		}
		else{
			pilha.pop();
		}
	}
	puts(pilha.empty() ? "YES" : "NO");
	return 0;
}