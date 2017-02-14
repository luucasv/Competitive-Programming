#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f;

string s;
int n, b;
vector<ii> rule[26];

int memo[111][111], mark[111][111], step;

int dp(int i, int j){
	if(j == b)
		return 0;
	if(i == n)
		return inf;
	
	int &ans = memo[i][j], &mk = mark[i][j];
	if(mk == step)
		return ans;
	mk = step;
	ans = dp(i+1, j);
	int p = j+1, id = s[i] - 'a', c = 0;
	fr(k, 0, rule[id].size()){
		if(p%rule[id][k].X == 0)
			c += (p/rule[id][k].X) * rule[id][k].Y;
	}
	return ans = min(ans, c + dp(i+1, j+1));
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		cout << "Case #" << cas++ << ": ";
		cin >> s >> b;
		n = s.size();
		
		fr(i, 0, 26){
			int q;
			cin >> q;
			rule[i] = vector<ii>(q, ii(0,0));
			fr(j, 0, q){
				cin >> rule[i][j].X >> rule[i][j].Y;
			}
		}
		++step;
		cout << dp(0, 0) << endl;
	}
	return 0;
}