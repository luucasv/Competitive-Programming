/*
	Codeforces: 446C. DZY Loves Fibonacci Numbers
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef int ll;

const ll mod = ll(1e9) + 9;
const int Q = 550, ms = Q*Q;

ll fib[ms], sum_fib[ms], sum_buck[Q], a[ms], la[Q][2];
void lazy(int bk){
	if(la[bk][0] + la[bk][1] == 0LL)
		return;
	ll va = la[bk][0], vb = la[bk][1];
	fr(i, bk*Q, (bk+1)*Q){
		a[i] = (a[i] + va)%mod;
		ll c = (va + vb)%mod;
		va = vb;
		vb = c;
	}
	la[bk][0] = la[bk][1] = 0;
}

inline ll val(int i){
	int b = i/Q, p = i - b*Q;
	if(p < 2){
		return (la[b][p] + a[i])%mod;
	}
	--p;
	return (( ( (long long)la[b][0] ) *fib[p]) + (( (long long) la[b][1])*fib[p+1]) + a[i])%mod;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	fib[1] = 1;
	sum_fib[1] = 1;
	fr(i, 2, n+2){
		fib[i] = (fib[i-1] + fib[i-2])%mod;
		sum_fib[i] = (sum_fib[i-1] + fib[i])%mod; 
	}
	
	fr(i, 0, n){
		scanf("%d", a+i);
		sum_buck[i/Q] = (sum_buck[i/Q] + a[i])%mod; 
	}
	
	fr(dasda, 0, m){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		--l, --r;
		int bl = l/Q, br = r/Q;
		if(2 == t){
			ll ans = 0;
			fr(i, bl+1, br)
				ans = (ans + sum_buck[i])%mod;
			
			for(int i = l; i/Q == bl && i <= r; ++i)
				ans = (ans + val(i))%mod;
			if(bl != br){
				for(int i = br*Q; i <= r; ++i)
					ans = (ans + val(i))%mod;
			}
			printf("%d\n", ans);
		}
		else{
			for(int i = l; i/Q == bl && i <= r; ++i){
				a[i] = (fib[i-l+1] + a[i])%mod;
				sum_buck[bl] = (sum_buck[bl] + fib[i-l+1])%mod; 
			}
			if(bl != br){
				for(int i = br*Q; i <= r; ++i){
					a[i] = (fib[i-l+1] + a[i])%mod;
					sum_buck[br] = (sum_buck[br] + fib[i-l+1])%mod; 
				}
			}
			fr(i, bl+1, br){
				la[i][0] = (la[i][0] + fib[i*Q-l+1])%mod;
				la[i][1] = (la[i][1] + fib[i*Q-l+2])%mod;
				sum_buck[i] = (((sum_buck[i] + sum_fib[(i+1)*Q - l])%mod - sum_fib[i*Q - l ]) %mod + mod)%mod;
			}
		}
	}
	return 0;
}