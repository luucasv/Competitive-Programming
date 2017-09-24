#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;

vector<long double> sol[1 << 9];
long double mat[10][10], f[10];

int pot(int a, int p){
	int res = 1;
	fr(i, 0, p)
		res *= a;
	return res;
}

void print(vector<long double> a, int mask){
	cout << "uma sol, mask = " << mask << ": " << setprecision(7) << fixed << a[0];
	fr(i, 1, a.size())
		cout << "  " <<  setprecision(7) << fixed << a[i];
	cout << endl;
}

bool diff(vector<long double> a, vector<long double> b){
	if(a.size() != b.size())
		return 1;
	fr(i, 0, a.size()){
		if(fabs(a[i] - b[i]) > 1e-2)
			return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	int d;
	while(cin >> d, d){
		fr(i, 0, d+3)
			cin >> f[i];
		fr(mask, 0, (1 << (d+3))){
			if(__builtin_popcount(mask) != d+1)
				continue;
			int at = 0;
			fr(i, 0, d+3){
				if((mask >> i)&1){
					fr(k, 0, d+1){
						mat[at][k] = (long double) pot(i, k);
					}
					mat[at][d+1] = f[i];
					at++;
				}
			}
			assert(at == d+1);
			fr(i, 0, d+1){
				int j;
				for(j = i; j < d+1 && fabs(mat[j][i]) < 1e-6; j++);
				assert(j < d+1);
				if(j != i){
					fr(k, 0, d+2)
						swap(mat[i][k], mat[j][k]);
				}
				
				long double m = mat[i][i];
				fr(j,0,d+2)
					mat[i][j] /= m;
				
				fr(k, 0, d+1){
					if(k == i)
						continue;
					m = mat[k][i];
					fr(j, 0, d+2){
						mat[k][j] -= m * mat[i][j]; 
					}
				}
			}
			sol[mask] = vector<long double>(d+1);
			fr(i, 0, d+1){
				sol[mask][i] = mat[i][d+1];
				// dbg(mask _ mat[i][d+1])
			}
		}
		fr(i, 0, d+3){
			vector<long double> at(0);
			bool found = 1;
			// dbg("==============" _ i _ "=================")
			fr(mask, 0, (1 << (d+3))){
				if(__builtin_popcount(mask) != d+1 || ((mask >> i)&1))
					continue;
				// print(sol[mask], mask);
				if(at.size() == 0){
					at = sol[mask];
				}
				else{
					if(diff(at, sol[mask]))
						found = 0;
				}
				if(!found)
					break;
			}
			// dbg(found)
			if(found){
				cout << i << endl;
				break;
			}
		}
		// dbg("opa")
	}
	return 0;
}






