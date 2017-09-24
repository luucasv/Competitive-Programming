#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;

queue<int> fi[2019];

int main(){
	ios::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	int m = n * x;
	if(n <= x){
		puts("-1");
		return 0;
	}
	fr(i, 1, m+1){
		fi[i%n].push(i);
	}
	fr(i, 0, n){
		fr(j, 0, x){
			cout << i + j*n + 1 << ' ';
		}
		int c = 0;
		for(int k = (i+1)%n; c < x; k = (k+1)%n){
			if((i+1)%n == k)
				continue;
			if(fi[k].empty())
				continue;
			if(c)
				cout << ' ';
			cout << fi[k].front();
			fi[k].pop();
			c++;
		}
		cout << endl;
	}
}