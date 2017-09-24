#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define md(x) ((x)%mod)

using namespace std;

typedef long long ll;
const int mn = 8111;

int v[mn];
int n, q;
vector<int> lista[mn];
ll counter[2*mn];
int mk[2*mn], step;

ll solve(int a, int b){
	int zero = mn;
	ll ans = 0;
	int i = 0, j = 0;
	int ls = -1, val;
	while(i < lista[a].size() || j < lista[b].size()){
		if(mk[zero] != step){
			counter[zero] = 0;
			mk[zero] = step;
		}
		// counter[zero]++;
		if(j == lista[b].size()){
			val = lista[a][i];
			++i;
		}
		else if(i == lista[a].size()){
			val = lista[b][j];
			++j;
		}
		else if(lista[a][i] < lista[b][j]){
			val = lista[a][i];
			++i;
		}
		else{
			val = lista[b][j];
			++j;
		}

		int d = val - ls - 1;
		ans += d * counter[zero];
		counter[zero] += d;
		ans += (ll(d) * (d + 1)) / 2;
		ls = val;
		counter[zero]++;
		if(v[val] == a){
			zero++;
		}
		else{
			zero--;
		}
		if(mk[zero] != step){
			counter[zero] = 0;
			mk[zero] = step;
		}
		ans += counter[zero];
	}
	int d = n-1 - ls;
	ans += d * counter[zero];
	counter[zero] += d;
	ans += (ll(d) * (d + 1)) / 2;
	return ans;
}

int aux;
map<int, int> mp;
map<pair<int, int>, int> memo;
int getId(int val, bool create){
	if(mp.count(val))
		return mp[val];
	if(create)
		return mp[val] = aux++;
	else
		return aux;
}
int main(){
	ios::sync_with_stdio(0);
	int aux = 0;
	map<int, int> mp;
	cin >> n >> q;
	fr(i, 0, n){
		cin >> v[i];
	}
	fr(i, 0, n){
		v[i] = getId(v[i], true);
		lista[v[i]].push_back(i);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		x = getId(x, false);
		y = getId(y, false);
		pair<int, int> p = make_pair(min(x, y), max(x, y));
		if(x == y){
			cout << (ll(n) * (n+1)) / 2 << endl;
			continue;
		}
		else if(memo.count(p)){
			cout << memo[p] << endl;
			continue;
		}
		++step;
		cout << (memo[p] = solve(x, y)) << endl;
	}
	return 0;
}