#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

const int inf = 0x3f3f3f3f, ms = 11111;
const double PI = acos(-1.0), EPS = 1e-8;
int n;
vdd v[ms];

vdd get_out(vdd vet){
	vdd out;
	double ls = 0.0;
	int st = 0;
	if(vet[0].X < EPS){
		ls = vet[0].Y + EPS;
		st = 1;
	}

	fr(i, st, vet.size()){
		out.push_back(dd(ls, vet[i].X - EPS));
		ls = vet[i].Y + EPS;
	}
	if(ls < 2*PI - EPS)
		out.push_back(dd(ls, 2*PI - EPS));
	return out;
}

bool inter(dd a, dd b){
	double be = max(a.X, b.X), ed = min(a.Y, b.Y);
	return be < ed || fabs(be - ed) < EPS;
}

dd get_inter(dd a, dd b){
	double be = max(a.X, b.X), ed = min(a.Y, b.Y);
	return dd(be, ed); 
}

vdd extend(vdd at, double ang){
	vdd ans;
	fr(i, 0, at.size()){
		at[i].X -= ang;
		at[i].Y += ang;
	}

	dd it = at[0];
	fr(i, 1, at.size()){
		if(inter(it, at[i])){
			it.Y = at[i].Y;
		}
		else{
			ans.push_back(it);
			it = at[i];
		}
	}
	ans.push_back(it);


	int ok = 0, n = int(ans.size()) - 1;
	if(ans[0].X < 0.0){
		ans.push_back(dd(ans[0].X + 2*PI, 2*PI - EPS));
		ans[0].X = 0.0;
		--n;
	}
	if(n >= 0 && ans[n].Y > 2*PI){
		double oi = ans[n].Y;
		ans[n].Y = 2*PI - EPS;
		ans.push_back(dd(0.0, oi - 2*PI));
	}

	sort(ans.begin(), ans.end());
	vdd res;
	it = ans[0];
	fr(i, 1, ans.size()){
		if(inter(it, ans[i])){
			it.Y = ans[i].Y;
		}
		else{
			res.push_back(it);
			it = ans[i];
		}
	}
	res.push_back(it);
	return res;
}

vdd inter(vdd at, vdd ne){
	int i = 0, j = 0, n = at.size(), m = ne.size();
	vdd ans;
	while(i < n && j < m){
		if(inter(at[i], ne[j])){
			ans.push_back(get_inter(at[i], ne[j]));
		}
		if(i+1 == n && j+1 == m)
			break;

		if(j+1 == m || (i+1 < n && ne[j+1] > at[i+1]))
			++i;
		else
			++j;
	}
	return ans;
}

void show(vdd a){
	dbg("begin")
	fr(i, 0, a.size())
		dbg(a[i].X _ a[i].Y)
	dbg("end")	
}

bool can(double t){
	double ang = 2*PI*t;
	vdd at = v[0];
	fr(i, 1, n){
		at = extend(at, ang);
		// dbg("extend")
		// show(at);
		at = inter(at, v[i]);
		// dbg("inter")
		// show(at);
		if(at.size() == 0)
			return 0;
	}
	return 1;
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		cout << "Case #" << cas++ << ": ";
		cin >> n;
		fr(i, 0, n){
			int k;
			cin >> k;
			v[i].clear();
			fr(j, 0, k){
				double a, b;
				cin >> a >> b;
				if(a > b){
					v[i].push_back(dd(a, 2*PI - EPS));
					v[i].push_back(dd(0.0, b));
				}
				else{
					v[i].push_back(dd(a, b));
				}
			}

			if(k){
				sort(v[i].begin(), v[i].end());
				v[i] = get_out(v[i]);
			}
			else{
				v[i].push_back(dd(0.0, 2*PI - EPS));
			}
		}

		// dbg("can" _ can(0));
		// continue;

		double lo = 0.0, hi = 1.0;
		fr(lala, 0, 200){
			double m = (lo + hi) / 2.0;
			if(can(m))
				hi = m;
			else
				lo = m;
		}

		cout << setprecision(4) << fixed << hi << endl;
	}
	return 0;
}