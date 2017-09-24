#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " << 

using namespace std;
char mat[20][20];

void change(char &a){
	a = a == 0 ? -1:a;
}

int main(){
	ios::sync_with_stdio(0);
	string str;
	while(cin >> str){
		memset(mat, 0, sizeof mat);
		int i = 0, j = 0;
		for(char ch : str){
			if(ch == '/'){
				++i;
				j = 0;
			}
			else if(ch >= '0' && ch <= '8'){
				j += ch - '0';
			}
			else{
				mat[i][j++] = ch;
			}
		}
		fr(i, 0, 8){
			fr(j, 0, 8){
				if(mat[i][j] <= 0)
					continue;
				char ch = tolower(mat[i][j]);

				if(ch == 'r' || ch == 'q'){
					int a = i+1;
					while(a < 8 && mat[a][j] <= 0){
						mat[a][j] = -1;
						++a;
					}
					a = i-1;
					while(a >= 0 && mat[a][j] <= 0){
						mat[a][j] = -1;
						--a;
					}
					a = j+1;
					while(a < 8 && mat[i][a] <= 0){
						mat[i][a] = -1;
						++a;
					}
					a = j-1;
					while(a >= 0 && mat[i][a] <= 0){
						mat[i][a] = -1;
						--a;
					}
				}
				if(ch == 'k'){
					if(i >= 1 && j >= 1){
						change(mat[i-1][j-1]);
					}
					if(i >= 1){
						change(mat[i-1][j]);
						change(mat[i-1][j+1]);
					}
					if(j >= 1){
						change(mat[i][j-1]);
						change(mat[i+1][j-1]);
					}
					change(mat[i+1][j]);
					change(mat[i+1][j+1]);
					change(mat[i][j+1]);
				}
				if(ch == 'b' || ch == 'q'){
					int a = i+1, b = j+1;
					while(a < 8 && b < 8 && mat[a][b] <= 0){
						mat[a][b] = -1;
						++a;
						++b;
					}
					a = i+1, b = j-1;
					while(a < 8 && b >= 0 && mat[a][b] <= 0){
						mat[a][b] = -1;
						++a;
						--b;
					}
					a = i-1, b = j-1;
					while(a >= 0 && b >= 0 && mat[a][b] <= 0){
						mat[a][b] = -1;
						--a;
						--b;
					}
					a = i-1, b = j+1;
					while(a >= 0 && b < 8 && mat[a][b] <= 0){
						mat[a][b] = -1;
						--a;
						++b;
					}
				}
				if(ch == 'n'){
					if(i >= 1 && j >= 2){
						change(mat[i-1][j-2]);
					}
					if(i >= 1){
						change(mat[i-1][j+2]);
					}
					if(i >= 2){
						change(mat[i-2][j+1]);
					}
					if(i >= 2 && j >= 1){
						change(mat[i-2][j-1]);
					}
					if(j >= 1){
						change(mat[i+2][j-1]);
					}
					if(j >= 2){
						change(mat[i+1][j-2]);
					}
					change(mat[i+1][j+2]);
					change(mat[i+2][j+1]);
				}
				if(mat[i][j] == 'P'){
					if(i >= 1 && j >= 1)
						change(mat[i-1][j-1]);
					if(i >= 1)
						change(mat[i-1][j+1]);
				}
				if(mat[i][j] == 'p'){
					if(j >= 1)
						change(mat[i+1][j-1]);
					change(mat[i+1][j+1]);
				}
			}
		}
		int ans = 0;
		fr(i, 0, 8)
			fr(j, 0, 8)
				if(mat[i][j] == 0)
					++ans;
		cout << ans << endl;
	}
}