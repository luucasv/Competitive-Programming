#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef pair<char, int> ci;

char ne[300];

int main(){
	int x0, y0, xf, yf;
	char d;
	ne['N'] = 'E';
	ne['E'] = 'S';
	ne['S'] = 'O';
	ne['O'] = 'N';
	cin >> x0 >> y0 >> d >> xf >> yf;
	vector<ci> ans;
	while(x0 != xf || y0 != yf){
		if(d == 'N' && yf > y0 || d == 'S' && yf < y0){
			ans.push_back(ci('A', abs(yf - y0)));
			y0 = yf;
		}
		else if(d == 'E' && xf > x0 || d == 'O' && xf < x0){
			ans.push_back(ci('A', abs(xf - x0)));
			x0 = xf;
		}
		else{
			ans.push_back(ci('D', 0));
			d = ne[d];
		}
	}
	cout << ans.size() << endl;
	for(auto it : ans){
		if(it.first == 'D'){
			cout << 'D' << endl;
		}
		else{
			cout << "A " << it.second << endl;
		}
	}
}