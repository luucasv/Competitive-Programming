#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

ll v[111111];

int main(){
	int n;
	cin >> n;
	ll sum = 0;
	fr(i, 0, n){
		cin >> v[i];
	}
	sort(v, v+n);
	while(n > 3){
		sum += min(v[n-1] + v[n-2] + 2 * v[0], v[n-1] + 2 * v[1] + v[0]);
		n -= 2;
	}
	if(n < 3){
		cout << sum + v[n-1] << endl;
	}
	else{
		cout << sum + v[0] + v[1] + v[2] << endl;
	}
}