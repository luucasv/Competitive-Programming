#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

string 
	a[] = {"***", "***", "***", "***", "***"},
	b[] = {"*.*", "*.*", "*..", "*.*", "*.."},
	c[] = {"***", "***", "*..", "*.*", "***"},
	d[] = {"*.*", "*.*", "*..", "*.*", "*.."},
	e[] = {"*.*", "***", "***", "***", "***"},
	v[5][5] = {a, b, c, d, e};



int main(){
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	fr(j, 0, 5){
		fr(i, 0, n){
			cout << v[j][s[i] - 'A'];
		}
		cout << endl;
	}
}