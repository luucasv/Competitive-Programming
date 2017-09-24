#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

int a[31], cnt[200];

int main(){
	fr(i, 0, 6)
		cin >> a[i];
	fr(i, 0, 6){
		int b;
		cin >> b;
		fr(j, 0, 6){
			cnt[a[j] + b]++;
		}
	}
	int ans = 0;
	fr(i, 1, 200){
		if(cnt[ans] < cnt[i]){
			ans = i;
		}
	}
	cout << ans << endl;
}