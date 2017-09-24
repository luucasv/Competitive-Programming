#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

int mat[100][100];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin  >> n;
	fr(i, 0, n)
		fr(j, 0, n)
			cin >> mat[i][j];
	int ans = 1;
	fr(x, 0, n)
		fr(y, 0, n){
			if(mat[x][y] == 1)
				continue;
			int ok = 0;
			fr(s, 0, n){
				fr(t, 0, n){
					if(mat[x][s] + mat[t][y] == mat[x][y]){
						ok = 1;
					}
				}
			}
			if(ok == 0)
				ans = 0;
		}

	puts(ans ? "Yes" : "No");
	return 0;
}