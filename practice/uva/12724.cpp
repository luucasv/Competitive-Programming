#include <bits/stdc++.h>
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)

using namespace std;
typedef long long ll;

map<string, string> mapa[30][30];

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << "Case #" << cas++ << ":\n";
		
		string str, a;
		fr(i, 0, n){
			cin >> str;
			int n = str.size();
			a = str;
			sort(a.begin(), a.end());
			mapa[str[0] - 'a'][str[n-1] - 'a'][a] = str;
		}
		cin.ignore();
		fr(i, 0, m){
			getline(cin, str);
			istringstream mine;
			mine.str(str);
			int fs = 0;
			while(mine >> a){
				int n = a.size(), s = a[0] - 'a', e = a[n-1] - 'a';
				sort(a.begin(), a.end());
				if(fs)
					cout << " ";
				cout << mapa[s][e][a];
				fs = 1;
			}
			cout << endl;
		}
	}
	return 0;
}