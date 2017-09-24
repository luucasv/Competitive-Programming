#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef pair<int, int> ii;

vector<ii> v[4*200*200];

int main(){
	ios::sync_with_stdio(0);
	int n, m;
	fr(i, -200, 200){
		fr(j, i, 200){
			int md = i*i + j*j;
			v[md].push_back(ii(i, j));
		}
	}
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int mod = n*n + m*m;
		bool ok = 1;
		for(int p = 2; p*p <= mod; p++){
			if(mod % p)
				continue;
			
			for(ii a : v[p]){
				int nmd = a.first*a.first + a.second*a.second;
				int v1 = a.first*n + a.second*m, v2 = a.first*m - a.second*n;
				if(v1 % nmd == 0 && v2 % nmd == 0)
					ok = 0;
				swap(a.first, a.second);
				v1 = a.first*n + a.second*m, v2 = a.first*m - a.second*n;
				if(v1 % nmd == 0 && v2 % nmd == 0)
					ok = 0;
				if(!ok)
					break;
			}
			
			if(!ok)
				break;
			if(p*p == mod)
				continue;
			
			for(ii a : v[mod / p]){
				int nmd = a.first*a.first + a.second*a.second;
				int v1 = a.first*n + a.second*m, v2 = a.first*m - a.second*n;
				if(v1 % nmd == 0 && v2 % nmd == 0)
					ok = 0;
				swap(a.first, a.second);
				v1 = a.first*n + a.second*m, v2 = a.first*m - a.second*n;
				if(v1 % nmd == 0 && v2 % nmd == 0)
					ok = 0;
				if(!ok)
					break;
			}
		}
		if(ok)
			cout << "P\n";
		else
			cout << "C\n";
	}
	return 0;
}
