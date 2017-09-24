#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

struct voucher{
	int l, r, c;
	voucher(){}
	voucher(int l):l(l), r(0), c(0){}
};
bool operator<(voucher a, voucher b){
	if(a.l != b.l)
		return a.l < b.l;
	if(a.r != b.r)
		return a.r < b.r;
	return a.c < b.c;
}

const int ms = int(2e5) + 100;

voucher v[ms];
vector<voucher> dur[ms];
vector<int> pre[ms];

int main(){
	ios::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	fr(i, 0, n){
		cin >> v[i].l >> v[i].r >> v[i].c;
		dur[v[i].r - v[i].l + 1].push_back(v[i]);
	}

	fr(i, 0, x){
		if(dur[i].size() == 0)
			continue;
		sort(dur[i].begin(), dur[i].end());
		pre[i] = vector<int>(dur[i].size());
		pre[i][dur[i].size() - 1] = dur[i][dur[i].size() - 1].c;
		for(int j = int(dur[i].size()) - 2; j > -1; j--){
			pre[i][j] = min(pre[i][j+1], dur[i][j].c);
		}
	}
	int ans = int(2e9) + 100;
	fr(i, 0, n){
		int d = v[i].r - v[i].l + 1;
		if(d > x)
			continue;
		d = x - d;
		if(dur[d].size() == 0)
			continue;
		int j = lower_bound(dur[d].begin(), dur[d].end(), voucher(v[i].r+1)) - dur[d].begin();
		if(j >= dur[d].size())
			continue;
		ans = min(ans, pre[d][j] + v[i].c);
	}
	if(ans > int(2e9)){
		ans = -1;
	}
	cout << ans << endl;
	return 0;
}