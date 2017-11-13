#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;

struct Range {
	int l, r;
	int id;
	Range(int l):l(l),r(-inf),id(0){}
	Range(int l, int r, int id):l(l), r(r), id(id){}
	bool operator<(const Range &re) const {
		if (l != re.l)
			return l < re.l;
		return r < re.r;
	}
};

int main(){
	set<Range> st;
	int n;
	cin >> n;
	int a;
	cin >> a;
	if (a > 1) {
		st.insert(Range(1, a-1, a));
	} 
	st.insert(Range(a+1, inf, a));
	fr(i, 1, n) {
		cin >> a;
		auto it = st.lower_bound(Range(a+1));
		it = prev(it);
		cout << it->id << endl;
		assert(a <= it->r);
		if (it->l <= a-1)
			st.insert(Range(it->l, a-1, a));
		if (a+1 <= it->r)
			st.insert(Range(a+1, it->r, a));
		st.erase(it);
	}
}