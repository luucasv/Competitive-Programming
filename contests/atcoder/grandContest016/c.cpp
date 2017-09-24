#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>>> " << x << endl;
#define _ << " , " <<  

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	vector<vector<int>> mat(H, vector<int>(W, 1));
	fr(i, 0, H-h){
		fr(j, 0, W-w){
			mat[i+h][j+w] = -h*w;
		}
	}
	long long gsum = 0;
	fr(i, 0, H)
		fr(j, 0, W)
			gsum += mat[i][j];
	bool ok = gsum > 0;
	fr(i, 0, H-h){
		fr(j, 0, W-w){
			long long sum = 0;
			fr(k, i, i+h){
				fr(l, j, j+w){
					sum += mat[k][k];
				}
			}
			if(sum >= 0){
				ok = 0;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	if(!ok)
		return 0;
	fr(i, 0, H){
		fr(j, 0, W){
			if(j)
				cout << " ";
			cout << mat[i][j];
		}
		cout << endl;
	}
	return 0;
}