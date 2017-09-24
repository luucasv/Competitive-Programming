#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

char mat[11][111];

int main(){
	ios::sync_with_stdio(0);
	string key, mes;
	while(cin >> key, key != "THEEND"){
		cin >> mes;
		int l = mes.size() / key.size();
		int at = 0;
		fr(ch, 'A', 'Z'+1){
			fr(i, 0, key.size()){
				if(key[i] != ch)
					continue;
				fr(j, 0, l)
					mat[j][i] = mes[at++];
			}
		}
		fr(i, 0, l)
			fr(j, 0, key.size())
				cout << mat[i][j];
		cout << endl;
	}

}