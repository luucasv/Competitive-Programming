#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

string toupper(string a){
	fr(i, 0,  a.size()){
		a[i] = toupper(a[i]);
	}
	return a;
}

int main(){
	ios::sync_with_stdio(0);
	map<string, int> mp;
	string str, a, up;
	while(getline(cin, str)){
		stringstream oi(str.c_str());
		bool fs = 1;
		while(oi >> a){
			if(!fs)
				cout << " ";
			fs = 0;
			
			up = toupper(a);
			if(mp[up]){
				cout << ".";
			}
			else{
				cout << a;
				mp[up] = 1;
			}
		}
		cout << endl;
	}
	return 0;
}
