#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

char mat[10][10];

bool can(int x, int y){
	if(x < 0 || x > 3 || y < 0 || y > 3)
		return 0;
	return mat[x][y] == 'x';
}

bool check(){
	fr(i, 0, 4){
		fr(j, 0, 4){
			int a, b, c, d;
			a = b = c = d = 0;
			fr(k, 0, 3){
				if(can(i+k, j+k))
					++a;
				if(can(i+k, j))
					++b;
				if(can(i, j+k))
					++c;
				if(can(i+k, j-k))
					++d;
			}

			if(a == 3 || b == 3 || c == 3 || d == 3)
				return 1;
		}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	fr(i, 0, 4)
		cin >> mat[i];

	bool  ok = 0;

	fr(i, 0, 4){
		fr(j, 0, 4){
			if(mat[i][j] == '.'){
				mat[i][j] = 'x';
				if(check())
					ok = 1;
				mat[i][j] = '.';
			}
		}
	}

	puts(ok ? "YES" : "NO");
	return 0 ;
}