#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int inf = 0x3f3f3f3f;

string s;
int n, m;

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		cout << "Case #" << cas++ << ": ";
		cin >> s >> n >> m;
		while(n*m < s.size()){
			if(n < m)
				n += m;
			else
				m += n;
		}
		
		int l = s.size() / m, r = m - (int(s.size()) - l*m);
		
		vvi aux = vvi(m, vi(n, -1));
		vvi mat = vvi(n, vi(m, -1));
		vvi mk = vvi(n, vi(m, 0));
		
		if(l*m == s.size()){
			--l;
			r = 0;
		}
		
		int at = 0;
		fr(i, 0, m)
			fr(j, 0, n)
				if(j < l || (j == l && i >= r)){
					assert(at < s.size());
					aux[i][j] = s[at++];
				}
		assert(at == s.size());
		
		fr(i, 0, n)
			fr(j, 0, m){
				mat[i][j] = aux[m - j - 1][i];
			}
		
		fr(i, 0, n){
			if(i == l)
				break;
			fr(j, 0, m){
				if(mk[i][j]){
					continue;
				}
				if(j+1 == m && i+1 < l){
					swap(mat[i][j], mat[i+1][j]);
					mk[i][j] = mk[i+1][j] = 1;
				}
				else if(j+1 != m){
					swap(mat[i][j], mat[i][j+1]);
					mk[i][j] = mk[i][j+1] = 1;
				}
			}
			++i;
			if(i == l)
				break;
			for(int j = m-1; j >= 0; --j){
				if(mk[i][j]){
					continue;
				}
				if(j == 0 && i+1 < l){
					swap(mat[i][j], mat[i+1][j]);
					mk[i][j] = mk[i+1][j] = 1;
				}
				else if(j != 0){
					swap(mat[i][j], mat[i][j-1]);
					mk[i][j] = mk[i][j-1] = 1;
				}
			}
		}
		
		fr(i, 0, n)
			fr(j, 0, m)
				if(mat[i][j] != -1)
					mat[i][j] = ((mat[i][j] - 'a' - (i+j+2))%26 + 26)%26 + 'a';
		
		string ans = "";
		fr(i, 0, n)
			fr(j, 0, m)
				if(mat[i][j] != -1)
					ans += char(mat[i][j]);
		cout << ans << endl;
	}
	return 0;
}