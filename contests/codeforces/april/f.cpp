#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	std::vector<int> v(n), a;
	fr(i, 0, n){
		cin >> v[i];
	}
	a = v;
	sort(a.begin(), a.end());
	ll cnt = 1e6;
	while(cnt){
		random_suffle(v.begin(), v.end());
		if(a == v)
			--cnt
	}
	fr(j, 0, n)
		cout << v[j] << " ";
}