#include <bits/stdc++.h>
#define fr(a, b, c) for(int (a) = (b), __ = c; a < __; ++a);

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x, y;
	cin >> x >> y;
	int dx = abs(x1 - x2), dy = abs(y1-y2);
	if(dx%x == 0 && dy%y == 0 && (dx/x)%2 == (dy/y)%2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}