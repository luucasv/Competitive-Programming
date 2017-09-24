#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

int v[11111];

int main(){
	ios::sync_with_stdio(0);
	int n, s = 0, sum = 0;
	cin >> n;

	fr(i, 0, n){
		cin >> v[i];
		s += (v[i] == 0);
		sum += v[i];
	}

	if(s == n){
		puts("NO");
		return 0;
	}

	cout << "YES\n"; 

	int ns = 0, i = 0;
	while(ns == 0){
		ns += v[i++];
	}

	if(i == n || sum != 0){
		cout << "1\n1 " << n << endl;
		return 0;
	}

	cout << "2\n";
	cout << "1 " << i << endl;
	cout << i+1 << " " << n << endl;


	return 0;
}