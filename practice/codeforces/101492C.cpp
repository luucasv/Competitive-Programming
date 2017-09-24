#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int ms = 5e4 + 3, mv = 5e5 + 2;
int a[ms], ls[ms], ans[ms];
int mob[mv], cnt[mv], low[mv];
vector<int> divs[mv];

int main(){
	for(int i = 1; i < mv; i++){
		mob[i] = 1;
		low[i] = 1;
	}
	for(int i = 2; i < mv; i++){
		if(low[i] != 1)
			continue;
		for(int j = i; j < mv; j += i){
			mob[j] = -mob[j];
			low[j] *= i;
			if((j / i) % i == 0)
				mob[j] = 0;
		}
	}
	for(int i = 1; i < mv; i++){
		for(int j = i; j < mv; j += i){
			if(mob[j]){
				divs[j].push_back(i);
			}
		}
	}
	int n, m;
	cin >> n >> m;
	fr(i, 0, n){
		cin >> a[i];
		a[i] = low[a[i]];
	}
	long long total = 0;
	int l = 0, r = 0;
	while(l < n){
		while(r < n && total == 0){
			for(int d : divs[a[r]]){
				total += mob[d] * cnt[d];
				cnt[d]++;
			}
			// dbg("dentro" _ l _ r _ total)
			r++;
		}
		// dbg(l _ r-1 _ total)
		ls[l] = total ? r-1: r;
		for(int d : divs[a[l]]){
			cnt[d]--;
			total -= mob[d] * cnt[d];
		}
		l++;
	}
	fr(i, 0, m){
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << (ls[l] <= r ? "S" : "N") << endl;
	}
	return 0;
}