#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	std::vector<int> v[3];
	int n, x;
	cin >> n;
	fr(k, 0, 3){
		x = k;
		fr(i, 0, 6){
			if(i&1){
				if(x == 1)
					x = 2;
				else if(x == 2)
					x = 1;
			}
			else{
				if(x == 0)
					x = 1;
				else if(x==1)
					x = 0;
			}
			v[k].push_back(x);
		}
	}
	cin >> x;
	--n;
	n %= 6; 
	fr(i, 0, 3){
		if(v[i][n] == x){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}