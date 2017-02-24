#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = int(1e5) + 10;
int mk[ms];

int f(int n){
	if(n == 1)
		return 1;
	int ans = 0;
	fr(i, 1, ((n)/2 + 1)){
		ans += (__gcd(i, n - i) == 1);
	}
	return ans;
}

int g(int n){
	int ans = 0;
	fr(i, 1, n+1){
		if(n%i == 0){
			ans += f(i);
			if(i*i < n)
				ans += f(n/i);
		}
		if(i*i > n)
			break;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	fr(n, 1, 1000)
		cout << f(n) << " ";
	cout << endl;
	fr(n, 1, 1000)
		cout << g(n) << " ";
	cout << endl;
	fr(n, 1, 1000)
		cout << f(g(n)) << " ";
	cout << endl;
	fr(n, 1, 1000){
		int ant = f(g(n));
		cout << "n = " << n << endl;
		cout << ant;
		fr(k, 2, 10){
			if(k&1)
				ant = f(ant);
			else
				ant = g(ant); 
			cout << " " << ant;
		}
		cout << endl;
	}
	return 0;
}