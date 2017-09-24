#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > mat(n, vector<int>(m)), st(n, vector<int>(m, n-1));
	vector<int> ma(n, 0);
	fr(i, 0, n)
		fr(j, 0, m)
			cin >> mat[i][j];
	
	ma[n-1] = n-1;
	for(int i = n-2; i >= 0; --i){
		fr(j, 0, m){
			if(mat[i][j] <= mat[i+1][j]){
				st[i][j] = st[i+1][j];
			}
			else{
				st[i][j] = i;
			}
			ma[i] = max(ma[i], st[i][j]);
		}
	}

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		--l, --r;
		puts(ma[l] >= r ? "Yes" : "No");
	}

	return 0;
}