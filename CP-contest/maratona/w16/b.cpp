#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
const int ms = int(1e5) + 100, mod = 997;

int pot(int a, int p){
	int res = 1;
	fr(i, 0, p)
		res = (res * a)%mod;
	return res;
}

int pinter(vector<int> a, vector<int> b){
	int ans = 0;
	fr(i, 0, 3)
		ans += a[i] * b[i];
	return ans;
}

void print(vector<int> a){
}

int inv[mod+5], mat[100][100];

int main(){
	ios::sync_with_stdio(0);
	int p, q;
	fr(i, 1, mod){
		inv[i] = pot(i, mod-2);
	}
	while(cin >> p >> q, p+q){
		cin.ignore();
		vector<string> P(p), Q(q);
		fr(i, 0, p){
			getline(cin, P[i]);
			dbg(P[i])
		}
		fr(i, 0, q)
			getline(cin, Q[i]);
		int r = 0, s = 0, c = 0;
		fr(ii, 0, p){
			int k = 0;
			while(k < P[ii].size() && P[ii][k] == '.') ++k;
			mat[ii][0] = r;
			mat[ii][1] = s;
			mat[ii][2] = c;
			mat[ii][3] = k;
			fr(j, k, P[ii].size()){
				if(P[ii][j] == '(')
					++r;
				else if(P[ii][j] == ')')
					--r;
				else if(P[ii][j] == '[')
					++s;
				else if(P[ii][j] == ']')
					--s;
				else if(P[ii][j] == '{')
					++c;
				else if(P[ii][j] == '}')
					--c;
			}
			
			// print(vector<int>(mat[ii], mat[ii] + 4));
		}
		
		fr(i, 0, 3){
			int j;
			for(j = i; j < p && mat[j][i] == 0; j++);
			
			if(j == p){
				continue;
			}
			if(j != i){
				fr(k, 0, 4)
					swap(mat[i][k], mat[j][k]);
			}
			
			int m = mat[i][i];
			fr(j,0,4)
				mat[i][j] = (mat[i][j] * inv[m])%mod;
			
			fr(k, 0, p){
				if(k == i)
					continue;
				m = mat[k][i];
				fr(j, 0, 4){
					mat[k][j] = ((mat[k][j] - m * mat[i][j]) % mod + mod)%mod; 
				}
			}
		}
		
		vector<vector<int>> base;
		fr(i, 0, 3){
			vector<int> opa(mat[i], mat[i] + 4);
			bool ok = 0;
			fr(j, 0, 4)
				if(opa[j] != 0)
					ok = 1;
			if(ok){
				base.push_back(opa);
				// print(opa);
			}
		}
		
		if(base.size() != 3){
			vector<vector<int>> nbase;
			fr(i, 0, base.size()){
				bool ok = 1;
				int sum = 0;
				fr(j, 0, 3){
					sum += base[i][j];
					if(base[i][j] > 1){
						ok = 0;
					}
				}
				if(ok == 0 || sum == 1){
					nbase.push_back(base[i]);
					continue;
				}
				dbg(sum _ base[i][3] _ 20*sum)
				if(base[i][3] == sum || base[i][3] == 20*sum){
					dbg("oi")
					fr(j, 0, 3){
						vector<int> v(4, 0);
						if(base[i][j] == 1){
							v[j] = 1;
							v[3] = base[i][3] / sum;
							nbase.push_back(v);
						}
					}
				}
				else{
					nbase.push_back(base[i]);
				}
			}
			base = nbase;
		}
		
		r = 0, s = 0, c = 0;
		fr(ii, 0, q){
			int n = base.size();
			int v[] = {r, s, c, 0};
			fr(i, 0, n){
				fr(j, 0, n){
					mat[i][j] = pinter(base[i], base[j]);
				}
				mat[i][n] = pinter(base[i], vector<int>(v, v+4));
			}
			int ok = 1;
			fr(i, 0, n){
				int j;
				for(j = i; j < n && mat[j][i] == 0; j++);
			
				if(j == n){
					ok = 0;
					break;
				}
			
				if(j != i){
					fr(k, 0, n+1)
						swap(mat[i][k], mat[j][k]);
				}
			
				int m = mat[i][i];
				fr(j,0,n+1)
					mat[i][j] = (mat[i][j] * inv[m])%mod;
			
				fr(k, 0, n){
					if(k == i)
						continue;
					m = mat[k][i];
					fr(j, 0, n+1){
						mat[k][j] = ((mat[k][j] - m * mat[i][j]) % mod + mod)%mod; 
					}
				}
			}
			vector<int> meuv(3, 0);
			int ans = 0;
			fr(i, 0, n){
				ans += mat[i][n] * base[i][3];
				fr(j, 0, 3)
					meuv[j] += mat[i][n] * base[i][j];
			}
			if(!ok || (vector<int>(v, v+3) != meuv))
				ans = -1;
			if(ii)
				cout << " ";
			cout << ans;
			fr(j, 0, Q[ii].size()){
				if(Q[ii][j] == '(')
					++r;
				else if(Q[ii][j] == ')')
					--r;
				else if(Q[ii][j] == '[')
					++s;
				else if(Q[ii][j] == ']')
					--s;
				else if(Q[ii][j] == '{')
					++c;
				else if(Q[ii][j] == '}')
					--c;
			}
		}
		cout << endl;
	}
	return 0;
}






