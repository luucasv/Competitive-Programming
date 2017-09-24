#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

string s, a;
int good[500];
bool can(){
	if(a.size() + 1 < s.size())
		return 0;
	int i, j, au;	
	for(i = 0; i < a.size() && i < s.size() && s[i] != '*'; i++){
		if(s[i] == '?' && !good[a[i]]){
			return 0;
		}
		else if(s[i] != '?' && s[i] != a[i]){
			return 0;
		}
	}
	if(i == s.size() && i < a.size())
		return 0;
	if(i == a.size()){
		if(i == s.size() || (s[i] == '*' && i+1 == s.size()))
			return 1;
		return 0;
	}
	int n = s.size();
	for(j = a.size() - 1, au = 1; j >= i && au <= n && s[n - au] != '*'; au++, j--){
		if(s[n-au] == '?' && !good[a[j]]){
			return 0;
		}
		else if(s[n-au] != '?' && s[n-au] != a[j]){
			return 0;
		}
	}
	if(s[n - au] != '*')
		return 0;
	fr(k, i, j+1){
		dbg("oi")
		if(good[a[k]]){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> a >> s;
	fr(i, 0, a.size())
		good[a[i]] = 1;
	int n;
	cin >> n;
	fr(i, 0, n){
		cin >> a;
		if(can())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}