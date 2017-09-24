
#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < (b); i++)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define X first
#define Y second
#define pb push_back
#define sc(a) scanf("%d", &a)
#define mp make_pair

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> i4;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

const int inf = 0x3f3f3f3f;
const int ms = 26, mr = 100000;

bool mark[ms][mr];
double memo[ms][mr];

int n;

double dp(int a, int r){
	int b = n - a;
	if(b == 0 && r == 0)
		return 1.0;
	if(a == 0 || r == 0 || b == 0)
		return 0.0;

	if(mark[a][r])
		return memo[a][r];

	mark[a][r] = 1;

	double ans = a*b*(dp(a+1, r-1) + dp(a-1, r-1)) + a*(a-1)*dp(a, r-1) + b*(b-1)*dp(a, r-1);
	return memo[a][r] = ans / (n * (n-1));
}

int main(){
	ios::sync_with_stdio(0);
	string a;
	cin >> a;
	map<char, int> cnt;
	fr(i, 0, a.size())
		cnt[a[i]]++;

	n = a.size();

	double ans = 0.0;

	for(auto it : cnt){
		fr(i, 1, mr)
			ans += dp(it.second, i) * i;
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}