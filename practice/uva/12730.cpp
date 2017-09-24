#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int inf = 0x3f3f3f3f, ms = 1111111;

int n, k;
double memo[ms], mesum[ms];
int mark[ms], masum[ms], step;

double dp(int i);
double sum(int i);

double sum(int i){
	if(i <= 0)
		return 0.0;

	double &ans = mesum[i];
	int &mk = masum[i];

	if(mk == step)
		return ans;
	mk = step;
	return ans = dp(i-k) + sum(i-1);
}

double dp(int i){
	if(i <= 0)
		return 0.0;
	if(i == 1)
		return 1.0;

	double &ans = memo[i];
	int &mk = mark[i];
	if(mk == step)
		return ans;
	mk = step;
	ans = sum(i-1);
	ans *= 2;
	ans += i;
	ans /= i;
	return ans;
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		++step;
		cout << "Case #" << cas++ << ": ";
		cin >> n >> k;
		cout << setprecision(4) << fixed << dp(n) << endl;
	}
	return 0;
}