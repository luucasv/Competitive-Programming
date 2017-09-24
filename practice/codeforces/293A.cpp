#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s, t;
	cin >> s  >> t;
	int fs = 0, sd = 0, bo = 0;
	int a = 0, b = 0;
	for(int i = 0; i < 2*n; i++){
		if(s[i] == '1' && t[i] == '1'){
			++bo;
		}
		else if(s[i] == '1'){
			++fs;
		}
		else if(t[i] == '1'){
			++sd;
		}
	}
	while(fs+sd+bo > 0){
		if(bo){
			bo--;
			a++;
		}
		else if(fs){
			a++;
			fs--;
		}
		else{
			sd--;
		}
		if(fs+sd+bo == 0){
			break;
		}
		if(bo){
			bo--;
			b++;
		}
		else if(sd){
			b++;
			sd--;
		}
		else{
			fs--;
		}
	}
	if(a > b){
		cout << "First";
	}
	else if(b > a){
		cout << "Second";
	}
	else{
		cout << "Draw";
	}
}