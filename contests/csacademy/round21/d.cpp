#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<string, int> si;

string memo[111111];
int mark[111111];
int n, k;


string bfs(){
	queue<si> fila;
	fila.push(si(to_string(k), k%n));
	while(1){
		si tp = fila.front();
		fila.pop();
		if(tp.second == 0)
			return tp.first;
		int a = (tp.second*10)%n;
		if(!mark[a]){
			mark[a] = 1;
			fila.push(si(tp.first + "0", a));
		}
		a = (tp.second*10 + k)%n;
		if(!mark[a]){
			mark[a] = 1;
			fila.push(si(tp.first + char('0' + k), a));
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	cout << bfs() << endl;
	return 0;
}