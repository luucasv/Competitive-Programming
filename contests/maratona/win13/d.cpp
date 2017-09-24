#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = 111, mt = 25111;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios::sync_with_stdio(0);
	int n;
	int oi = 0;
	while(cin >> n, n){
	
		if(oi) cout << endl;
		oi = 1;
		int p[3] = {0, 0, 0};
		fr(i, 0, n){
			string s;
			int m;
			cin >> s >> m;
			if(s == "DROP"){
				cout << "DROP 1 " << m << endl;
				p[1] += m;
			}
			else{
				if(p[2] >= m){
					cout << "TAKE 2 " << m << endl;
					p[2] -= m;
				}
				else{
					if(p[2]) cout << "TAKE 2 " << p[2] << endl;
					cout << "MOVE 1->2 " << p[1] << endl;
					cout << "TAKE 2 " << m - p[2] << endl;
					p[2] += p[1];
					p[2] -= m;
					p[1] = 0;
				}
			}
		}
	}
	return 0;
}







