#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

/*
	2 nada
	0 linha passada esquerda
	1 linha passada direita
*/
const int ms = 411, inf = 200*100 + 400;
int memo[ms][ms][5], mk[ms][ms][5], step;
int v[ms][2];
int n, k;
	
int dp(int at, int q, int ls){
	if(q == 0)
		return 0;
	if(at == n)
		return inf;
	if(mk[at][q][ls] == step)
		return memo[at][q][ls];
	mk[at][q][ls] = step;
	int ans = dp(at+1, q, 2);
	if(ls != 2){
		ans = min(ans, v[at][ls] + dp(at+1, q-1, ls));
	}
	else{
		ans = min(ans,  v[at][0] + dp(at+1, q-1, 0));
		ans = min(ans,  v[at][1] + dp(at+1, q-1, 1));
	}
	return memo[at][q][ls] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	while(cin >> n >> k, n+k){
		++step;
		int sum = 0;
		fr(i, 0, n){
			cin >> v[i][0] >> v[i][1];
			sum += v[i][0] + v[i][1];
		}
		cout << sum - dp(0, k, 2) << endl;
	}
	
	return 0;
}
