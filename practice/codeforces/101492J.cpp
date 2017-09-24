#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int getSum(ll x){
	int ans = 0;
	while(x > 0){
		ans += x%10;
		x /= 10;
	}
	return ans;
}

int n_vet[20], x_vet[20], sumX;
ll memo[20][200][2][3];
int mk[20][200][2][3], step;

// count k <= n && sum(k) < sum(x) + k < x && sum(k) == sum(x)
// at = digit
// sum = partial sum
// lessN = 1 if already less then n, 0 if equal
// lessX = 0 if == x, 1 if < x, 2 if > x
ll dp(int at, int sum, int lessN, int greaterX){
	if(at == -1){
		return (sum < sumX || (greaterX == 1 && sum == sumX)) ? 1 : 0;
	}
	ll &ans = memo[at][sum][lessN][greaterX];
	if(mk[at][sum][lessN][greaterX] == step)
		return ans;
	mk[at][sum][lessN][greaterX] = step;
	ans = 0;
	fr(i, 0, 10){
		if(!lessN && i > n_vet[at])
			break;
		int nn = (lessN || i < n_vet[at]) ? 1 : 0;
		int nx = greaterX;
		if(greaterX == 0 && i != x_vet[at]){
			nx = i < x_vet[at] ? 1 : 2;
		}
		ans += dp(at-1, sum + i, nn, nx);
	}
	return ans;
}

void makeVet(int v[], ll val){
	memset(v, 0, 18 * sizeof(int));
	stack<int> pilha;
	while(val > 0){
		pilha.push(val%10);
		val /= 10;
	}
	int at = pilha.size() - 1;
	while(!pilha.empty()){
		v[at--] = pilha.top();
		pilha.pop();
	}
}

ll count(ll x){
	++step;
	makeVet(x_vet, x);
	return dp(18, 0, 0, 0);
}

int main(){
	ll n, k;
	cin >> n >> k;
	makeVet(n_vet, n);
	sumX = getSum(k);
	cout << count(k) << " ";


	fr(i, 1, 180){
		sumX = i;
		if(count(0) > k){
			sumX = i - 1;
			break;
		}
	}
	++step;
	ll lo = 1, hi = n;
	while(hi - lo > 1){
		ll md = (lo + hi) / 2;
		if(count(md+1)-1 < k)
			lo = md;
		else
			hi = md;
	}
	if(count(lo+1)-1 < k){
		lo = hi;
	}
	cout << lo << endl;
}