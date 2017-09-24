#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int um = v1 * s + 2*t1, dois = v2 * s + 2 * t2;
	if(um  < dois)
		cout << "First\n";
	else if(dois < um)
		cout << "Second\n";
	else
		cout << "Friendship\n";
	return 0;
}