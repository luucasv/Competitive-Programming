#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 111111, inf = 0x3f3f3f3f;
const int di[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dj[] = {1, -1, 0, -1, 1, 0, -1, 1};
typedef pair<int, int> ii;
typedef long long int ll;



int main(){
	ios::sync_with_stdio(0);
	string mat[11];
	fr(i, 0, 10)
		cin >> mat[i];
	auto has = [mat](int x, int y){
		return x >= 0 && y >= 0 && x < 10 && y < 10 && mat[x][y] == 'X';
	};
	auto can = [mat](int x, int y){
		return x >= 0 && y >= 0 && x < 10 && y < 10 && mat[x][y] == '.';
	};
	bool ok = 0;
	fr(i, 0, 10){
		fr(j, 0, 10){
			int h[8] = {0}, c[8] = {0};
			fr(k, 0, 5){
				fr(d, 0, 8){
					int x = i + k * di[d], y = j + k * dj[d];
					if(has(x, y)){
						++h[d];
					}
					else if(can(x, y)){
						++c[d];
					}
				}
			}
			fr(d, 0, 8){
				if(h[d] == 4 && c[d] == 1)
					ok = 1;
			}
		}
	}
	puts(ok ? "YES" : "NO");
	return 0;
}