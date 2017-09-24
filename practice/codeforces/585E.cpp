/*
	Solving Codeforces 585E. Present for Vitalik the Philatelist
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long long ll;
const int mod = ll(1e9) + 7;
const int mv = int(1e7) + 2, ms = int(5e5) + 7;
int ls[mv];
int div_cnt[mv];
bool twice[mv];
short cnt[mv];

int a[ms], pot[ms];
vector<int> primes[ms];

int main(){
	ios::sync_with_stdio(0);
	int n;
	fr(i, 2, mv){
		if(ls[i])
			continue;
		for(int j = i; j < mv; j += i){
			ls[j] = i;
			++cnt[j];
		}
	}
	fr(i, 2, int(1e4)){
		if(ls[i] != i)
			continue;
		for(int j = i*i; j < mv; j += i*i){
			twice[j] = 1;
		}
	}
	pot[0] = 1;
	fr(i, 1, ms){
		pot[i] = (pot[i-1]*2)%mod;
	}
	cin >> n;
	fr(i, 0, n){
		cin >> a[i];
		int aux = a[i];
		while(aux != 1){
			int p = ls[aux];
			primes[i].push_back(p);
			while(aux%p == 0) aux /= p;
		}
		
		fr(m, 0, (1 << primes[i].size())){
			int res = 1;
			fr(j, 0, primes[i].size()){
				if((m >> j)&1)
					res *= primes[i][j];
			}
			div_cnt[res]++;
		}
	}
	int g1 = 0;
	fr(i, 1, mv){
		if(twice[i])
			continue;
		int val = (pot[div_cnt[i]] + mod - 1)%mod;
		if(cnt[i]&1)
			val = (mod - val)%mod;
		g1 = (g1 + val)%mod;
	}
	int ans = 0;
	fr(i, 0, n){
		int mg = g1, ma = 0;
		fr(m, 0, (1 << primes[i].size())){
			int res = 1, c = 0;
			fr(j, 0, primes[i].size()){
				if((m >> j)&1){
					++c;
					res *= primes[i][j];
				}
			}

			if(c&1){
				mg = ((mg + pot[div_cnt[res]] -  pot[div_cnt[res] - 1])%mod + mod)%mod;
				ma = (ma + pot[div_cnt[res] - 1] - 1)%mod;
			}
			else{
				mg = ((mg - pot[div_cnt[res]] +  pot[div_cnt[res] - 1])%mod + mod)%mod;
				if(m != 0) ma = (ma + mod - pot[div_cnt[res] - 1] + 1)%mod;
			}
		}
		ans = ((ans + pot[n-1] - mg - ma - 1)%mod + mod)%mod;
	}
	cout << ans << endl;
	return 0;
}
