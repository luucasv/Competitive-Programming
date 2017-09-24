/*
	Codeforces: 100994E. Maximal sum
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int ms = 111111;
const ll inf = ll(1e15) + 10;

pli a[ms], b[ms];
ll ans[ms];

struct node{
	ll prefix, sufix, sum, maxSum;
	node(){
		prefix = sufix = sum = maxSum = -inf;
	}

	node(ll a){
		prefix = sufix = sum = maxSum = a;
	}

	node operator+(const node &a){
		node ans;
		ans.prefix = max(prefix, sum + a.prefix);
		ans.sufix = max(a.sufix, a.sum + sufix);
		ans.sum = max(sum + a.sum, -inf);
		ans.maxSum = max(max(maxSum, a.maxSum), max(sufix + a.prefix, ans.sufix));
		ans.maxSum = max(ans.maxSum, ans.prefix);
		ans.maxSum = max(ans.maxSum, ans.sum);
		return ans;
	}
};


class seg_tree{
public:
	seg_tree(vector<node> _vet){
		vet = _vet;
		n = vet.size();
		st.assign(4*n, node());
		build(1, 0, n-1);
	}

	void del(int i){
		return del(1, 0, n-1, i);
	}

	ll maxSum(){
		if(st[1].maxSum == -inf)
			return 0;
		return st[1].maxSum;
	}
private:
	vector<node> st, vet;
	int n;
	inline int L(int x){return x << 1;}
	inline int R(int x){return L(x) + 1;}
	void build(int id, int l, int r){
		if(l == r){
			st[id] = vet[l];
			return;
		}
		int md = (l+r)/2;
		build(L(id), l   , md);
		build(R(id), md+1,  r);
		st[id] = st[L(id)] + st[R(id)];
	}

	void del(int id, int l, int r, int i){
		if(l > i || r < i){
			return;
		}
		if(l == r){
			st[id] = node();
			return;
		}

		int md = (l+r)/2;
		del(L(id), l   , md, i);
		del(R(id), md+1,  r, i);
		st[id] = st[L(id)] + st[R(id)];
	}

};




int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<node> v(n);
	fr(i, 0, n){
		cin >> a[i].X;
		a[i].Y = i;
		v[i] = node(a[i].X);
	}
	fr(i, 0, m){
		cin >> b[i].X;
		b[i].Y = i;
	}
	
	sort(a, a+n);
	sort(b, b+m);
	int aid = 0;

	seg_tree seg(v);
	fr(bid, 0, m){
		while(aid < n && a[aid].X < b[bid].X){
			seg.del(a[aid].Y);
			++aid;
		}

		ans[b[bid].Y] =  seg.maxSum();
	}

	cout << ans[0];
	fr(i, 1, m)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}