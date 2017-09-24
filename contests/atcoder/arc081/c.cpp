#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	map<long long, int> cnt;
	fr(i, 0, n){
		int a;
		cin >> a;
		cnt[a]++;
	}
	long long a = 0, b = 0;
	for(auto x : cnt){
		if(x.second >= 2){
			a = max(a, x.first);
		}
	}
	for(auto &x : cnt){
		if(x.first == a){
			x.second -= 2;
		}
	}
	for(auto x : cnt){
		if(x.second >= 2){
			b = max(b, x.first);
		}
	}
	cout << a * b << endl;
	return 0;
}