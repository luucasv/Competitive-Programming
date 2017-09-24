#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;

bitset<201> ori[201], merg[201];

int main(){
	#ifdef ONLINE_JUDGE
		freopen("settling.in", "r", stdin);
		freopen("settling.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		ori[a][b] = 1;
	}

	int ans = 0;
	for(int i = n-1; i > -1; --i){
		merg[i] = ori[i];
		fr(j, i+1, n){
			if(merg[i][j])
				merg[i] |= merg[j];
		}
		ans += merg[i].count();
	}

	cout << ans << endl;

	int k;
	cin >> k;
	while(k--){
		char ch;
		int i, j;
		cin >> ch >> i >> j;
		--i, --j;
		if(ch == '?'){
			cout << (merg[i][j] ? "YES" : "NO") << endl;
		}
		else{
			if(ch == '+')
				ori[i][j] = 1;
			else
				ori[i][j] = 0;

			ans = 0;
			for(int i = n-1; i > -1; --i){
				merg[i] = ori[i];
				fr(j, i+1, n){
					if(merg[i][j])
						merg[i] |= merg[j];
				}
				ans += merg[i].count();
			}
			cout << ans << endl;
		}
	}
}