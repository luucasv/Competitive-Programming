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

const int inf = 0x3f3f3f3f;
const int ms = 35, mp = 311;

iii see[ms];
int memo[ms][ms][ms][mp], mark[ms][ms][ms][mp], step;
int n, m, k, c;

int dp(int at, int ls, int als, int p){
	if(p < 0)
		return -inf;
	if(see[ls].X.Y == n)
		return 0;
	if(p == 0)
		return -inf;
	if(at == m+2)
		return -inf;
	if(see[ls].X.Y + 1 < see[at].X.X)
		return -inf;

	int &ans = memo[at][ls][als][p], &mk = mark[at][ls][als][p];
	if(mk == step)
		return ans;
	mk = step;
	if(see[at].X.Y <= see[ls].X.Y)
		return ans = dp(at+1, ls, als, p);
	else if(see[als].X.Y + 1 >= see[at].X.X)
		return ans = dp(at+1, ls, als, p);
	else
		ans = max(dp(at+1, ls, als, p), see[at].Y + dp(at+1, at, ls, p - see[at].Y));
	// dbg(at _ ls _ als _ p _ ans)
	return ans;
}

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	see[0] = iii(ii(-10000, -1), 0);
	see[1] = iii(ii(-1000, 0), 0);
	while(t--){
		++step;
		cout << "Case #" << cas++ << ": ";
		cin >> n >> m >> k;
		fr(i, 2, m+2){
			cin >> see[i].X.X >> see[i].X.Y >> see[i].Y;
		}
		sort(see + 2, see + m+2);
		ll ans = 0;
		
		fr(i, 0, k){
			int a, b;
			cin >> a >> b;
			fr(oi, a, min(b+1, mp)){
				ans += max(0, dp(2, 1, 0, oi));
			}
			int ma = dp(2, 1, 0, mp - 1);
			if(b >= mp){
				ans += ll(b - max(a, mp) + 1)*ma;
			}
		}
		cout << ans << endl;
	}
	return 0;
}