#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int mat[12][111][111];

int main(){
	ios::sync_with_stdio(0);
	int n, q, c;
	cin >> n >> q >> c;
	c++;
	fr(i, 0, n){
		int x, y, s;
		cin >> x >> y >> s;
		fr(i, 0, c){
			mat[i][x][y] += (s + i)%c;
		}
	}
	fr(k, 0, c){
		fr(i, 1, 102){
			fr(j, 1, 102){
				mat[k][i][j] += mat[k][i-1][j] + mat[k][i][j-1] - mat[k][i-1][j-1];
			}
		}
	}
	fr(oi, 0, q){
		int t, x1,y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= c;
		cout << mat[t][x2][y2] - mat[t][x2][y1-1] - mat[t][x1-1][y2] + mat[t][x1-1][y1-1] << endl;
	}
	return 0;
}