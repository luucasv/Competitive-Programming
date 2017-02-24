#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = int(1e5) + 10;
int mk[ms];

int main(){
	ios::sync_with_stdio(0);
	fr(i, 2, ms){
		if(mk[i])
			continue;
		for(int j = i+i; j < ms; j += i)
			mk[j] = 1;
	}
	int n;
	cin >> n;
	if(n >= 3)
		cout << 2 << endl;
	else
		cout << 1 << endl;
	fr(i, 2, n+2){
		cout <<  mk[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}