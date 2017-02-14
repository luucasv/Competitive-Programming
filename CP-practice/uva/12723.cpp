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
int n, k;
double P[20], ex[511];

double memo[511];
int mark[511], step;

double dp(int i){
	if(i >= n)
		return 0.0;
	
	int &mk = mark[i];
	double &ans = memo[i]; 
	if(mk == step)
		return ans;
	
	mk = step;
	ans = ex[i];
	fr(j, 0, k){
		ans += P[j]*dp(i+j+1);
	}
	return ans;
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		cout << "Case #" << cas++ << ": ";
		cin >> n >> k;
		fr(i, 0, k)
			cin >> P[i];
		
		fr(i, 0, n){
			int q;
			cin >> q;
			ex[i] = 0.0;
			while(q--){
				double c, x;
				cin >> c >> x;
				ex[i] += c*x;
			}
		}
		
		++step;
		cout << setprecision(6) << fixed << dp(0) << endl;
	}
	return 0;
}