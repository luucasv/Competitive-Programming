#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

struct coupon{
	int l, r, id;

	bool operator<(coupon a) const {
		if(l == a.l)
			return r < a.r;
		return l < a.l;
	}
};

coupon v[311111];

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	fr(i, 0, n){
		cin >> v[i].l >> v[i].r;
		v[i].id = i;
	}

	multiset<int> st;
	sort(v, v+n);

	fr(i, 0, k){
		st.insert(v[i].r);
	}

	int pos = k, be = v[k-1].l, ed = *st.begin();

	fr(i, k, n){
		st.erase(st.begin());
		st.insert(v[i].r);
		int ne = *st.begin();
		if(ed - be+1 <= ne - v[i].l+1){
			be = v[i].l;
			ed = ne;
			pos = i+1;
		}
	}

	if(ed - be + 1 <= 0){
		cout << "0\n1";
		fr(i, 1, k)
			cout << " " << i+1;
		cout << endl;
		return 0; 
	}

	cout << ed - be + 1 << endl;
	std::vector<int> vet;
	fr(i, 0, pos){
		if(v[i].r >= ed)
			vet.push_back(v[i].id+1);
	}

	fr(i, 0, k)
		cout << vet[i] << " ";
	cout << endl;

	return 0 ;
}