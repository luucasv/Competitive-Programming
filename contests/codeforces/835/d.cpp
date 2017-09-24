#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull base = 37;
ull h1[5111], h2[5111], pot[5111];
ull ans[5111];
bool memo[2][5001][5001];

ull sub(ull h[], int st, int sz){
	return h[st + sz ] - h[st] * pot[sz];
}

int TAM;

bool kpal(int k, int c, int sz){
	if(sz == 0)
		return false;
	if(k == 1){
		if(sz == 1){
			return memo[k][c][sz] = true;
		}
		int s1 = c - sz/2, s2 = c + sz/2;
		if(sz%2 == 0){
			s1++;
		}
		ull um = sub(h1, s1, sz/2), dois = sub(h2, TAM - 1 - s2, sz / 2);
		return memo[1][c][sz] = um == dois;
	}
	int q = sz / 2; 
	int s1 = c - q, s2 = c + q;
	if(sz%2 == 0)
		s1++;
	int c1 = s1 + q/2, c2 = s2 - q/2;
	if(q%2 == 0){
		c1--;
	}
	s2 = c+1;
	ull um = sub(h1, s1, q), dois = sub(h1, s2, q);
	return memo[k%2][c][sz] = um == dois && memo[1 - k%2][c1][q] && memo[1 - k%2][c2][q];
}

int main(){
	ios::sync_with_stdio(0);
	string s, rv;
	cin >> s;
	rv = s;
	reverse(rv.begin(), rv.end());
	int k = s.size();
	TAM = k;
	pot[0] = 1;
	fr(i, 0, k){
		h1[i+1] = h1[i] * base + ull(s[i] - 'a' + 1);
		h2[i+1] = h2[i] * base + ull(rv[i] - 'a' + 1);
		pot[i+1] = pot[i] * base;
	}
	fr(i, 1, min(14, k+1)){
		fr(sz, 1 << (i - 1), k+1){
			fr(st, 0, k){
				if(st + sz > k)
					break;
				int c = st + sz / 2;
				if(sz%2 == 0){
					c--;
				}
				bool oi = kpal(i, c, sz);
				if(oi){
					ans[i]++;
				}
			}
		}
	}
	fr(i, 1, k+1)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
