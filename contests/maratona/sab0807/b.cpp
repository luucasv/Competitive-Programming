#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " << 

using namespace std;
const int ml = 111, mm = 611;

int memo[mm][ml], mk[mm][ml], step;
vector<int> go[mm];
string comb[mm];

int n, l, m;

bool match(const string &a, const string &b){
	fr(i, 0, a.size() - 1){
		if(a[i+1] != b[i])
			return false;
	}
	return true;
}

int dp(int at, int sz){
	if(sz == l)
		return 1;
	if(sz >= l)
		return 0;
	if(mk[at][sz] == step)
		return memo[at][sz];
	mk[at][sz] = step;
	int ans = 0;
	for(auto i : go[at]){
		ans += dp(i, sz+1);
	}
	return memo[at][sz] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	while(cin >> n >> l >> m, n+l+m){
		++step;
		fr(i, 0, m){
			cin >> comb[i];
		}
		fr(i, 0, m){
			go[i].clear();
			fr(j, 0, m){
				if(match(comb[i], comb[j])){
					go[i].push_back(j);
				}
			}
		}
		int ans = 0;
		fr(i, 0, m)
			ans += dp(i, comb[i].size());
		cout << ans << endl;
	}

}