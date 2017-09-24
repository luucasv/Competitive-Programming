#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
const int ms = int(1e6) + 100;

bool marka[ms], markb[ms];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n){
		int a;
		cin >> a;
		marka[a] = 1;
	}
	fr(i, 0, n){
		int b;
		cin >> b;
		markb[b] = 1;
	}
	for(int g = ms - 1; g > -1; g--){
		int maiora = -1, maiorb = -1;
		for(int m = g; m < ms; m += g){
			if(marka[m]){
				maiora = max(maiora, m);
			}
			if(markb[m]){
				maiorb = max(maiorb, m);
			}
		}
		if(maiora > 0 && maiorb > 0){
			cout << maiora + maiorb << endl;
			return 0;
		}
	}
	assert(0);
	return 0;
}