#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
const int ms = int(1e5) + 100;

int mod;

struct Matrix{
	vector<vector<int>> mat;
	int n, m;
	Matrix(){}
	Matrix(int n, int m):n(n), m(m){
		mat.assign(n, vector<int>(m, 0));
	}
	
	vector<int>& operator[](int i){
		return mat[i];
	}
	
	Matrix operator*(Matrix &ma){
		assert(m == ma.n);
		Matrix ans(n, ma.m);
		fr(i, 0, n){
			fr(j, 0, ma.m){
				fr(k, 0, m){
					ans[i][j] = (ans[i][j] + mat[i][k] * ma[k][j])%mod;
				}
			}
		}
		return ans;
	}
};

int main(){
	ios::sync_with_stdio(0);
	int n, m, a, b, c, t;
	while(cin >> n >> m >> a >> b >> c >> t, n+t+m+a+c+b){
		mod = m;
		Matrix st(1, n), op(n, n), mu(n, n);
		fr(i, 0, n){
			cin >> st[0][i];
			if(i)
				op[i-1][i] = a;
			if(i+1 < n)
				op[i+1][i] = c;
			op[i][i] = b;
			mu[i][i] = 1;
		}
		
		for(; t; t >>= 1, op = op*op){
			if(t&1){
				mu = mu * op;
			}
		}
		Matrix res = st * mu;
		cout << res[0][0];
		fr(i, 1, n)
			cout << " " << res[0][i];
		cout << endl;
	}
	return 0;
}






