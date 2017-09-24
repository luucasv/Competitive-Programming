#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s, m;
	cin >> s >> m;
	multiset<char> md;
	fr(i, 0, n)
		md.insert(m[i]);
	fr(i, 0, n){
		if(md.lower_bound(s[i]) != md.end()){
			md.erase(md.lower_bound(s[i]));
		}
	}
	cout <<  md.size() << endl;
	md.clear();
	fr(i, 0, n)
		md.insert(m[i]);
	fr(i, 0, n){
		if(md.upper_bound(s[i]) != md.end()){
			md.erase(md.upper_bound(s[i]));
		}
	}
	cout << n - int(md.size()) << endl;
	return 0;
}