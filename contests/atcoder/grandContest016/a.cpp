#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>>> " << x << endl;
#define _ << " , " <<  

using namespace std;

const int inf = 400;
int bef[inf], af[inf], v[inf];

int go(const string &s, char ch){
	v[s.size()] = 0;
	for(int i = s.size() - 1; i > -1; i--){
		if(s[i] == ch){
			af[i] = 0;
		}
		else if(i + 1 < s.size()){
			af[i] = 1 + af[i+1];
		}
		else{
			af[i] = inf;
		}
		v[i] = af[i];
	}
	fr(i, 1, s.size()){
		v[i] = max(v[i], v[i-1]);
	}
	int ma = inf;
	fr(i, 0, s.size()){
		v[i] = max(int(s.size()) - i - 1, v[i]);
		ma = min(v[i], ma);
	}
	if(ma == -1)
		ma = inf;
	return ma;
}

int main(){
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int ans = inf;
	fr(i, 'a', 'z'+1){
		ans = min(ans, go(s, i));
	}
	cout << ans << endl;
	return 0;
}