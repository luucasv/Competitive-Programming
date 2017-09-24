#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 500, inf = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef long long int ll;

int c[ms], c2[ms];

ll can(int q){
	ll ans = 0;
	fr(i, 0, 400){
		ans += max(0LL, ll(q)*c2[i] - c[i]);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	fr(i, 0, s.size())
		c[s[i]]++;
	int inter = c['?'];
	fr(i, 0, t.size())
		c2[t[i]]++;
	int lo = 0, hi = 50 * s.size();
	while(hi - lo > 1){
		int m = (lo + hi) / 2;
		if(can(m) <= inter)
			lo = m;
		else
			hi = m;
	}
	if(can(hi) > inter)
		hi = lo;
	assert(can(hi) <= inter);
	int i = 0;
	fr(ch, 'a', 'z'+1){
		int q = max(0, hi * c2[ch] - c[ch]);
		while(q > 0 && i < s.size()){
			if(s[i] == '?'){
				s[i] = ch;
				--q;
			}
			++i;
		}
	}
	while(i < s.size()){
		if(s[i] == '?')
			s[i] = 'a';
		i++;
	}
	cout << s << endl;
	return 0;
}