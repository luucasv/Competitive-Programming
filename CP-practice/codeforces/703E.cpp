/*
	Codeforces: 703E. Mishka and Divisors
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int mv = 1111, ms = 11111;
const short int shinf = 1e3 + 100;
const ll inf = ll(1e18);
map<ll, int> mp;
ll divs[ms];
vector<ll> primes;
vector<int> value_pot[ms];
vector<vector<ll>> prime_pot;

ll a[mv], memo[mv][ms], k;
int id[mv], cnt, n;
bool way[mv][ms];
short int quant[mv][ms];


ll gcd(int i, int j){
	ll ans = 1;
	fr(k, 0, primes.size()){
	 	ans *= prime_pot[k][min(int(prime_pot[k].size()) - 1, value_pot[i][k] + value_pot[j][k])];
	}
	return ans;
}

int main(){
	scanf("%d %lld", &n, &k);
	for(ll i = 1; i*i <= k; ++i){
		if(k%i)
			continue;
		mp[i];
		if(i*i < k){
			mp[k/i];
		}
	}

	for(auto &it : mp){
		it.second = cnt;
		divs[cnt++] = it.first;
	}

	ll aux = k;
	for(ll i = 2; i*i <= aux; ++i){
		if(aux%i)
			continue;
		vector<ll> pt;
		pt.push_back(1);
		ll p = 1;
		while(aux%i == 0){
			p *= i;
			pt.push_back(p);
			aux /= i;
		}
		primes.push_back(i);
		prime_pot.push_back(pt);
	}
	if(aux != 1){
		primes.push_back(aux);
		vector<ll> v(2, aux);
		v[0] = 1;
		v[1] = aux;
		prime_pot.push_back(v);
	}
	fr(i, 0, cnt){
		ll sht = divs[i];
		for(auto pr : primes){
			int q = 0;
			while(sht%pr == 0){
				++q;
				sht /= pr;
			}
			value_pot[i].push_back(q);
		}
	}

	fr(i, 0, n){
		scanf("%lld", a+i);
		ll sht = __gcd(a[i], k);
		id[i] = mp[sht];
	}

	if(k == 1){
		ll ans = inf;
		int ansi;
		fr(i, 0, n){
			if(a[i] < ans){
				ans = a[i];
				ansi = i+1;
			}
		}
		printf("1\n%d\n", ansi);
		return 0;
	}

	for(int i = n; i > -1; --i){
		for(int d = cnt-1; d > -1; --d){
			if(d == cnt-1){
				continue;
			}
			else if(i == n){
				quant[n][d] = shinf;
			}
			else{
				int to = mp[gcd(id[i], d)];
				short int &ans = quant[i][d], a2 = 1 + quant[i+1][to];
				ans = quant[i+1][d];
				memo[i][d] = memo[i+1][d];
				ll sum = memo[i+1][to] + a[i];
				if(ans > a2 || (ans == a2 && memo[i][d] > sum)){
					memo[i][d] = sum;
					ans = a2;
					way[i][d] = true;
				}
			}
		}
	}
	short int ans = quant[0][0];
	if(ans >= shinf){
		puts("-1");
		return 0;
	}	

	printf("%d\n", ans);
	
	int d = 0;
	fr(i, 0, n){
		if(way[i][d]){
			printf("%d ", i+1);
			d = mp[gcd(d, id[i])];
		}
	}

	puts("");
}