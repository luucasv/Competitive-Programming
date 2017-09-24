#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;


bool lucky(int n){
	string s = to_string(n);
	return int(s[0]) + int(s[1]) + int(s[2]) == int(s[3]) + int(s[4]) + int(s[5]);
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, n+1, 1000000){
		if(lucky(i)){
			cout << i << endl;
			return 0;
		}
	}
	assert(0);
	return 0;
}