#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

#define L(x) (x << 1)
#define R(x) ((x << 1) + 1)

using namespace std;
typedef long long ll;
const int ms = 11, mv = 51111;
const ll mod = ll(1e9) + 7;

inline ll md(ll a){
	return a;
}

struct node{
	ll a[ms], ab[ms][ms], abb[ms][ms], bba[ms][ms], abba[ms][ms];
	node(){
		memset(a, 0, sizeof a);
		memset(ab, 0, sizeof ab);
		memset(abb, 0, sizeof abb);
		memset(bba, 0, sizeof bba);
		memset(abba, 0, sizeof abba);
	}
	node operator+ (node p){
		node ans;
		fr(i, 0, ms){
			ans.a[i] = md(a[i] + p.a[i]);
			fr(j, 0, ms){
				ans.ab[i][j]   = a[i]*p.a[j] + ab[i][j] + p.ab[i][j];
				ans.abb[i][j]  = a[i]*p.ab[j][j] + ab[i][j]*p.a[j] + abb[i][j] + p.abb[i][j];
				ans.bba[i][j]  = a[i]*p.ab[i][j] + ab[i][i]*p.a[j] + bba[i][j] + p.bba[i][j];
				ans.abba[i][j] = a[i]*p.bba[j][i] + ab[i][j]*p.ab[j][i] + abb[i][j]*p.a[i] + abba[i][j] + p.abba[i][j];
			}
		}
		return ans;
	}
	ll quant(){
		ll ans = 0;
		fr(i, 0, ms){
			ans = md(ans + abba[i][i]);
			fr(j, 0, ms){
				if(i == j)
					continue;
				ans = md(ans + abba[i][j]);
			}
		}
		return ans;
	}
};

node A[4*mv];
int str[mv];

void build(int idx, int l, int r){
	if(l == r){
		A[idx].a[str[l]]++;
		return;
	}
	
	int md = (l+r)/2;
	build(L(idx), l, md);
	build(R(idx), md+1, r);
	A[idx] = A[L(idx)] + A[R(idx)];
}

void update(int idx, int l, int r, int p, int v){
	if(l > p || r < p)
		return;
	if(l == r){
		A[idx].a[str[l]]--;
		A[idx].a[v]++;
		str[l] = v;
		return;
	}
	
	int md = (l+r)/2;
	update(L(idx), l, md, p, v);
	update(R(idx), md+1, r, p, v);
	A[idx] = A[L(idx)] + A[R(idx)];
}

node query(int idx, int l, int r, int i, int j){
	if(l > j || r < i)
		return node();
	if(l >= i && r <= j){
		return A[idx];
	}
	
	int md = (l+r)/2;
	node a = query(L(idx), l, md, i, j);
	node b = query(R(idx), md+1, r, i, j);
	return a + b;
}

int main(){
	ios::sync_with_stdio(0);
	string aux;
	cin >> aux;
	int n = aux.size();
	fr(i, 0, n)
		str[i] = aux[i] - '0';
	build(1, 0, n-1);
	int q;
	cin >> q;
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1)
			cout << query(1, 0, n-1, a-1, b-1).quant()%mod << endl;
		else
			update(1, 0, n-1, a-1, b);
	}
}