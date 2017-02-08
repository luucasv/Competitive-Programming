#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long int ll;

const int ms = 111111;

int t[ms];
ll sum[ms], at;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	t[0] = -100000;
	sum[0] = 0;

	fr(i, 1, n+1){
		cin >> t[i];
		int nove = upper_bound(t, t+i, t[i] - 90) - t, hora = upper_bound(t, t+i, t[i] - 1440) - t;
		sum[i] = sum[i-1] + 20;
		sum[i] = min(sum[i], sum[nove - 1] + 50);
		sum[i] = min(sum[i], sum[hora - 1] + 120);
		cout << sum[i] - sum[i-1] << endl;
	}

	return 0;
}