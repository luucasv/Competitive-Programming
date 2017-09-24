#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int ms = 111111;

int getId(char ch){
	if(ch == 'A')
		return 0;
	if(ch == 'C')
		return 1;
	if(ch == 'G')
		return 2;
	return 3;
}

void add(int B[], int p, int val){
	while(p < ms){
		B[p] += val;
		p += p&-p;
	}
}

int get(int B[], int p){
	int ans = 0;
	while(p > 0){
		ans += B[p];
		p -= p&-p;
	}
	return ans;
}

int get(int B[], int l, int r){
	return get(B, r+1) - get(B, l);
}

int BIT[11][11][5][ms];


int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		
	}
	return 0;
}