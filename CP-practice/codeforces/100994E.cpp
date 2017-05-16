/*
	Codeforces: 100994E. Maximal sum
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int ms = 111111;
const ll inf = ll(1e15) + 10;

ll a[ms], b[ms];

struct node{
	ll prefix, sufix, sum, minElem, maxSum;
	bool valid;
	node(){
		prefix = sufix = sum = minElem = maxSum = 0;
		valid = false;
	}

	node(ll a){
		prefix = sufix = sum = minElem = maxSum = a;	
		valid = true;
	}

	node operator+(const node &a){
		node ans;
		if(!a.valid){
			return *this;
		}
		if(!valid){
			return a;
		}
		ans.sufix = max(a.sufix, a.sum + sufix);
		ans.minElem = min(minElem, ans.minElem);
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
		st.assign(4*n, node(0, 1, true));
		build(1, 0, n-1);
	}

	bool query(int i, int j){
		return query(1, 0, n-1, i, j).maxSum;
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

	node query(int id, int l, int r, int i, int j){
		if(l > j || r < i)
			return node(0, 1, true);
		if(l >= i && r <= j){
			// dbg(l _ r _ st[id].solvable)
			return st[id];
		}
		int md = (l+r)/2;
		node ret = query(L(id), l, md, i, j) + query(R(id), md+1, r, i, j);
		// dbg(l _ r _ ret.solvable)
		return ret;
	}

};




int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	fr(i, 0, n)
		cin >> a[i];
	fr(i, 0, m)
		cin >> b[i];

	return 0;
}