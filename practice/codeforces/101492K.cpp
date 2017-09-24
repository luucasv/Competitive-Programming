#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long double ld;


int main(){
	int k;
	cin >> k;
	k++;
	cout << (1 << k) - 1 << endl;
}