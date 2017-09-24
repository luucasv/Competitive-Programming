#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int ms = 111111;

int getId(char ch){
	if(ch == 'A')
		return 0;
	if(ch == 'C')
		return 1;
	if(ch == 'G')
		return 2;
	return 3;
}

void add(int B[], int p, int val){
	while(p < ms){
		B[p] += val;
		p += p&-p;
	}
}

int get(int B[], int p){
	int ans = 0;
	while(p > 0){
		ans += B[p];
		p -= p&-p;
	}
	return ans;
}

int get(int B[], int l, int r){
	return get(B, r+1) - get(B, l);
}

int BIT[11][11][5][ms];


int main(){
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	for(char &it : s){
		it = getId(it);
	}
	fr(m, 1, 11){
		fr(c, 0, 4){
			fr(i, 0, s.size()){
				add(BIT[m][i%m][c], i+1, s[i] == c ? 1 : 0);
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			char c;
			cin >> x >> c;
			--x;
			c = getId(c);
			fr(m, 1, 11){
				add(BIT[m][x%m][s[x]], x+1, -1);
			}
			fr(m, 1, 11){
				add(BIT[m][x%m][c], x+1, 1);
			}
			s[x] = c;
		}
		else{
			int l, r;
			string e;
			cin >> l >> r >> e;
			--l, --r;

			for(char &it : e){
				it = getId(it);
			}
			int m = e.size();
			int ans = 0;
			fr(i, 0, e.size()){
				char c = e[i];
				ans += get(BIT[m][(i + l)%m][c], l, r);
			}
			cout << ans << endl;
		}
	}
	return 0;
}