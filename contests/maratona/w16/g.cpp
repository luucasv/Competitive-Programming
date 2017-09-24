#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
const int ms = int(1e5) + 100;

int BIT[ms];

void add(int i, int v){
	while(i < ms){
		BIT[i] += v;
		i += i&-i;
	}
}

int get(int i){
	int ans = 0;
	while(i > 0){
		ans += BIT[i];
		i -= i&-i;
	}
	return ans;
}

int part(int i, int j){
	return get(j+1) - get(i);
}

int memo[ms], mk[ms], step;


int w, n;
int dp(int i){
	if(i == n)
		return 1;
	
	if(mk[i] == step)
		return memo[i];
	mk[i] = step;
	int lo = 2, hi = n-i;
	while(hi - lo > 1){
		int m = (lo + hi) / 2;
		if(part(i, i+m-1)-1 > w)
			hi = m;
		else
			lo = m;
	}
	if(part(i, i+hi-1)-1 > w)
		hi = lo;
	lo = 2;
	if(i + hi == n)
		return memo[i] = 1;
	
	while(hi - lo > 5){
		int d = (hi - lo) / 3;
		int m1 = lo + d, m2 = hi - d;
		int v1 = max(1 + (w + 1 - part(i, i+m1-1) + m1 - 2) / (m1 - 1), dp(i + m1));
		int v2 = max(1 + (w + 1 - part(i, i+m2-1) + m2 - 2) / (m2 - 1), dp(i + m2));
		if(v1 > v2)
			hi = m1;
		else
			lo = m2;
	}
	// dbg(i _ lo _ hi _ w)
	int ans = w;
	fr(m, lo, hi+1){
		//dbg(i _ m _ 1 + (w + 1 - part(i, i+m-1) + m - 2) / (m - 1) _ dp(i + m))
		ans = min(ans, max(1 + (w + 1 - part(i, i+m-1) + m - 2) / (m - 1), dp(i + m)));
		// dbg("a")
	}
	return memo[i] = ans;
}


int main(){
	ios::sync_with_stdio(0);
	while(cin >> w >> n, w+n){
		memset(BIT, 0, sizeof BIT);
		int sum = -1;
		int ans = 1, q = 0;
		fr(i, 0, n){
			int x;
			cin >> x;
			add(i+1, x+1);
		}
		++step;
		cout << dp(0) << endl;
	}
	return 0;
}






