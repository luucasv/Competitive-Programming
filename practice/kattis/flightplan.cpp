#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long double ld;
const ld PI = acos(-1.0), EPS = 1e-10, R = 6370;

int sign(ld x){
	if(fabs(x) < EPS)
		return 0;
	if(x < 0)
		return -1;
	return 1;
}

struct PT{
	ld lat, lon, x, y, z;
	PT(){}
	PT(int lat, int lon){
		this->lat = (lat * PI) / 180.0;
		this->lon = (lon * PI) / 180.0; 
		x = cos(this->lat) * cos(this->lon);
		y = cos(this->lat) * sin(this->lon);
		z = sin(this->lat);
	}
	PT(ld x, ld y, ld z){
		this->x = x;
		this->y = y;
		this->z = z;
		this->lat = atan2(z, sqrt(x * x + y * y));
		this->lon = atan2(y, x);
	}

	PT operator-() const {
		return PT(-x, -y, -z);
	}

	PT operator%(const PT& p) const {
		return PT(y * p.z - z * p.y, - x * p.z + z * p.x, x * p.y - y * p.x);
	}

	PT operator*(const ld c) const {
		return PT(x * c, y * c, z * c);
	}

	ld operator*(const PT& p) const {
		return x*p.x + y*p.y + z*p.z;
	}

	ld operator!() const {
		return sqrt(x*x + y*y + z*z);
	}

	bool operator==(PT p){
		return fabs(p.lat - lat) < EPS && fabs(p.lon - lon) < EPS;
	}
};

struct Arc{
	PT p1, p2;
	Arc(PT p1, PT p2):p1(p1), p2(p2){}
	
	ld size(){
		ld ans = R * acos(cos(p1.lat) * cos(p1.lon) * cos(p2.lat) * cos(p2.lon)
			+ cos(p1.lat) * sin(p1.lon) * cos(p2.lat) * sin(p2.lon) 
			+ sin(p1.lat) * sin(p2.lat));
		return ans;
	}

	pair<bool, PT> inter(Arc ac){
		PT p = p1 % p2;
		PT q = ac.p1 % ac.p2;
		PT t = p % q;
		t = t * (1 / !(t));
		int s1 = - sign((p1 % p) * t),
		s2 = sign((p2 % p) * t),
		s3 = - sign((ac.p1 % q) * t),
		s4 = sign((ac.p2 % q) * t);
		if(s1 == s2 && s2 == s3 && s3 == s4){
			if(s1 == 1){
				return make_pair(true, t);
			}
			else if(s1 == -1){
				return make_pair(true, -t);
			}
			else{
				return make_pair(false, PT());
			}
		}
		else{
			return make_pair(false, PT());
		}
	}
};

PT findIt(Arc ac, const vector<vector<Arc>> pols){
	PT ans = ac.p2;
	for(auto pol : pols){
		for(Arc a : pol){
			auto it = ac.inter(a);
			if(it.first){
				if(Arc(ac.p1, ans).size() > Arc(ac.p1, it.second).size()){
					// dbg(ac.size() _ Arc(ac.p1, it.second).size() + Arc(it.second, ac.p2).size())
					ans = it.second;
				}
			}
		}
	}
	return ans;
}

int main(){
	int c;
	cin >> c;
	vector<vector<Arc>> pols(c);
	fr(i, 0, c){
		int q;
		cin >> q;
		int lat, lon;
		cin >> lat >> lon;
		PT st(lat, lon), ls = st;
		fr(k, 1, q){
			cin >> lat >> lon;
			PT at(lat, lon);
			pols[i].push_back(Arc(ls, at));
			ls = at;
		}
		pols[i].push_back(Arc(ls, st));
	}
	ld total = 0, water = 0;
	int q, w = 0;
	cin >> q;
	int lat, lon;
	cin >> lat >> lon;
	PT ls(lat, lon);
	fr(i, 1, q){
		cin >> lat >> lon;
		PT at(lat, lon);
		while(!(ls == at)){
			PT it = findIt(Arc(ls, at), pols);
			ld sz = Arc(ls, it).size();
			total += sz;
			if(w){
				water += sz;
			}
			if(!(it == at)){
				w = 1 - w;
			}
			ls = it;
		}	
	}
	cout << fixed << setprecision(10) << total << ' ' << (water / total) * 100 << endl;
}