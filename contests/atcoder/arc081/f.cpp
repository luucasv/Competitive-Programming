#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int ls[50];
int dp[211111], to[211111];
char go[211111];
int main(){
	ios::sync_with_stdio(0);
	int h, w;
	cin >> h >> w;
	fr(i, 0, h)
		cin >> map[i];
	fr(i, 0, h)
		fr(j, 0, w)
			mat[i][j] = map[i][j] == '#' ? 1 : 0;

	return 0;
}