#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cout << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<int, set<int> > is;

int n;
int mk[11111], step;
int me[100][100];

int dp(int v, int mi){
	if(v == 0)
		return 0;

	if(me[v][mi] != -1)
		return me[v][mi];

	fr(i, mi, v+1){;
		dp(v-i, i+1);
	}
	++step;
	fr(i, mi, v+1){;
		mk[dp(v-i, i+1)] = step;
	}
	int ans = 0;
	while(mk[ans] == step) ++ans;
	me[v][mi] = ans;
	return me[v][mi] = ans;
}


int main(){
	ios::sync_with_stdio(0);
	memset(me, -1, sizeof me);
	cin >> n;
	int xr = 0;
	fr(i, 0, n){
		int s;
		cin >> s;
		xr ^= dp(s, 1);
	}

	if(xr)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}