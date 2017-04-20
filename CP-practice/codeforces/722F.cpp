#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll lcm(ll a, ll b){
	return a / __gcd(a, b) * b;
}

pll euclides(ll a, ll b){
	if(b == 0) return pll(1, 0);
	if(a == 0) return pll(0, 1);
	pll p = euclides(b%a, a);
	return pll(p.second - p.first * (b / a), p.first);
}

ll inverse(ll a, ll b){
	pll p = euclides(a, b);
	return (p.first%b + b)%b;
}

ll mul(ll a, ll b, ll mod){
	ll q = (long double) a * (long double) b / (long double) mod;
	ll ans = a * b  - q * mod;
	return (ans + 5 * mod)%mod;
}

struct node{
	ll mod, reminder;
	bool solvable;
	int l, r; // left and right lines

	node(){}
	node(ll reminder, ll mod, bool solvable, int l = -1, int r = -1): mod(mod), reminder(reminder), solvable(solvable), l(l), r(r){}
	node operator+(node a){
		if(!solvable || !a.solvable){
			return node(0, 1, false);
		}
		
		if(l == r && l == -1){
			return a;
		}
		if(a.l == a.r && a.l == -1){
			return *this;
		}

		if(r+1 != a.l && a.r+1 != l){
			return node(0, 1, false);
		}
		ll gcd = __gcd(mod, a.mod);
		if((reminder - a.reminder)%gcd != 0){
			return node(0, 1, false);
		}

		node ans;
		ans.mod = lcm(mod, a.mod);
		ans.reminder = (mul(a.reminder - reminder, mul(inverse(mod, a.mod), mod/gcd, ans.mod), ans.mod) + reminder)%ans.mod;
		ans.solvable = true;
		ans.l = min(l, a.l);
		ans.r = max(r, a.r);
		return ans;
	}
};

class seg_tree{
private:
	vector<node> st, vet;
	int n;
	inline int L(int x){return x << 1;}
	inline int R(int x){return L(x) + 1;}
	void build(int id, int l, int r){
		if(l == r){
			st[id] = vet[l];
			// dbg(l _ r _ st[id].solvable)
			return;
		}
		int md = (l+r)/2;
		build(L(id), l   , md);
		build(R(id), md+1,  r);
		st[id] = st[L(id)] + st[R(id)];
		// dbg(l _ r _ st[id].solvable)
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
public:
	seg_tree(){}
	seg_tree(vector<node> _vet){
		vet = _vet;
		n = vet.size();
		st.assign(4*n, node(0, 1, true));
		build(1, 0, n-1);
	}

	bool query(int i, int j){
		return query(1, 0, n-1, i, j).solvable;
	}
};


int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<node> > mat(m);
	fr(i, 0, n){
		int k;
		cin >> k;
		fr(j, 0, k){
			int a;
			cin >> a;
			--a;
			mat[a].push_back(node(j, k, true, i, i));
		}
	}

	seg_tree seg;
	fr(i, 0, m){
		if(mat[i].size() == 0){
			cout << "0\n";
			continue;
		}
		seg = seg_tree(mat[i]);
		int l = 0, r = 0, ans = 0;
		while(r < mat[i].size()){
			while(!seg.query(l, r))
				++l;
			ans = max(ans, r - l + 1);
			++r;
		}
		cout << ans << endl;
	}
	return 0;
}