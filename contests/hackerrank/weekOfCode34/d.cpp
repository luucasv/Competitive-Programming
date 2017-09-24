#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define md(x) ((x)%mod)

using namespace std;

typedef long long ll;
const ll mod = ll(1e9) + 7;
const int mv = int(2e5) + 100, me = 2*mv, mlog = 20, mf = int(5e7);
ll f[mf];
map<ll, ll> memo;
void mul(ll mat1[][2], ll mat2[][2]){
	ll ans[2][2] = {0};
	fr(i, 0, 2)
		fr(j, 0, 2)
			fr(k, 0, 2)
				ans[i][j] = md(ans[i][j] + mat1[i][k] * mat2[k][j]);
	fr(i, 0, 2)
		fr(j, 0, 2)
			mat1[i][j] = ans[i][j];
}

ll ans[2][2], mat[2][2];

ll fib(ll n){
	++n;
	if(n < 0){
		n = -n;
		ll sv = fib(n);
		if(n%2 == 0){
			sv = (mod - sv)%mod;
		}
		return sv;
	}
	if(n < mf){
		return f[n];
	}
    if(memo.count(n)){
        return memo[n];
    }
	ans[0][0] = ans[1][1] = 1;
	ans[0][1] = ans[1][0] = 0;
	mat[0][0] = 0;
	mat[0][1] = mat[1][1] = mat[1][0] = 1;
	for(; n; n >>= 1, mul(mat, mat)){
		if(n&1){
			mul(ans, mat);
		}
	}
	return memo[n] = ans[0][1];
}

int ant[me], to[me], adj[mv], z;
int prox[me];

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z;
	prox[ant[z]] = z, prox[z] = -1, z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z;
	prox[ant[z]] = z, prox[z] = -1, z++;
}

ll c[mv];
ll A[mv], B[mv];

ll solve(int u, int p){
	ll ans = 0;
	A[u] = fib(c[u]);
	B[u] = fib(c[u] - 1);
	for(int i = adj[u]; i > -1; i = ant[i]){
		int v = to[i];
		if(v == p)
			continue;
		ans = md(ans + solve(v, u));
		ans = md(ans + md(A[u]*A[v]) + md(B[u] * B[v]));
		A[u] = md(A[u] + md(A[v]*fib(c[u])) + md(B[v]*fib(c[u] - 1)));
		B[u] = md(B[u] + md(A[v]*fib(c[u] - 1)) + md(B[v]*fib(c[u] - 2)));
	}
	return ans;
}

int main(){
	memset(adj, -1, sizeof adj);
	f[0] = 0;
	f[1] = 1;
	fr(i, 2, mf)
		f[i] = md(f[i-1] + f[i-2]);
	int n;
	cin >> n;
	fr(i, 1, n){
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		add(a, b);
	}
	ll ans = 0;
	fr(i, 0, n){
		scanf("%lld", &c[i]);
		ans = md(ans + fib(c[i]));
	}
	printf("%lld\n", (ans + 2 * solve(0, 0))%mod);
	return 0;
}