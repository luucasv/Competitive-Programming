#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long int ll;

int n, c, s;

int p[212345];
bool vis[212345];

void bfs(int at){
	while(!vis[at]){
		vis[at] = 1;
		at = p[at];
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n){
		cin >> p[i];
		--p[i];
	}
	
	fr(i, 0, n){
		int a;
		cin >> a;
		s += a;
	}

	s = s&1;
	s = 1 - s;

	fr(i, 0, n){
		if(!vis[i]){
			bfs(i);
			++c;
		}
	}

	if(c == 1)
		c = 0;
	
	cout << c + s << endl;;

	return 0;
}