#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cout << ">>> " << x << endl;
#define _ << " , " <<

#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const int ms = int(1e5) + 10, Q = 400;

struct query{
	int i, j, k, id;
	query(){}
	query(int i, int j, int k, int id) : i(i), j(j), k(k), id(id){}
	bool operator< (query a) const {
		if(i/Q != a.i/Q)
			return i/Q < a.i/Q;
		return j < a.j;
	}
};


int BITa[ms], BITb[ms];

void adda(int p, int v){
	if(p >= ms)
		return;
	while(p < ms){
		BITa[p] += v;
		p += p&-p;
	}
}

void addb(int p, int v){
	if(p >= ms)
		return;
	while(p < ms){
		BITb[p] += v;
		p += p&-p;
	}
}

int suma(int p){
	if(p >= ms)
		return 0;
	int ans = 0;
	while(p > 0){
		ans += BITa[p];
		p -= p&-p;
	}
	return ans;
}


int sumb(int p){
	if(p >= ms)
		return 0;
	int ans = 0;
	while(p > 0){
		ans += BITb[p];
		p -= p&-p;
	}
	return ans;
}

int equala(int i){
	return suma(i) - suma(i-1);
}

int equalb(int i){
	return sumb(i) - sumb(i-1);
}

query que[ms];
ll ans[ms];

int A[ms], B[ms];

int main(){
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	
	fr(i, 0, n)
		cin >> A[i];
	fr(i, 0, n)
		cin >> B[i];
	
	fr(id, 0, q){
		int i, j, k;
		cin >> i >> j >> k;
		--i, --j;
		que[id] = query(i, j, k, id);
	}
	
	sort(que, que+q);
	
	int l = 0, r = -1;
	fr(i, 0, q){
		while(r < que[i].j){
			++r;
			addb(B[r], 1);
			adda(A[r], 1);
		}
		while(r > que[i].j){
			addb(B[r], -1);
			adda(A[r], -1);
			r--;
		}
			
		while(l < que[i].i){
			adda(A[l], -1);
			addb(B[l], -1);
			l++;
		}
		while(l > que[i].i){
			--l;	
			adda(A[l], 1);
			addb(B[l], 1);
		}
		ll &a = ans[que[i].id];
		int aux = 0;
		int k = que[i].k;
		int j;
		for(j = 1; j*j <= k; ++j){
			a += ll(equala(j)) * sumb(k/j);
			aux += equala(j);
		}
		fr(l, 1, j){
			a += ll(equalb(l)) * (suma(k/l) - aux);
		}
	}
	
	fr(i, 0, q)
		cout << ans[i] << endl;
	
	return 0;
}