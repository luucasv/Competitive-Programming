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
	int n, m;
	while(cin >> n >> m, n+m){
		int q;
		cin >> q;
		fr(i, 0, q){
			cin >> v[i].X >> v[i].Y;
			mat[v[i].X][v[i].Y] = i;
		}
	}
}