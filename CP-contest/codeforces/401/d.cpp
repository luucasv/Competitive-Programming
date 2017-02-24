#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

string mat[511111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> mat[i];

	for(int i = n-2; i >= 0; --i){
		fr(j, 0, mat[i].size()){
			if(j == mat[i+1].size() || mat[i][j] > mat[i+1][j])
				mat[i][j] = 2;
			else if(mat[i][j] < mat[i+1][j])
				break;
		}
	}

	fr(i, 0, n){
		fr(j, 0, mat[i].size()){
			if(mat[i][j] == 2)
				break;
			cout << mat[i][j];
		}
		cout << endl;
	}
	return 0;
}