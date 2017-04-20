#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;

typedef long long int ll;
typedef pair<ll, int> li;

const int mn = 1e5 + 100, mm = 5e4 + 100, ms = mn + mm + 100;
li q[mm];

int n, m;
set<li> at;
map<li, int> mp;
ll v[mn];
ll BIT[ms];

void add(int p, ll val){
	if(p == 0)
		return;
	while(p < ms){
		BIT[p] += val;
		p += p&-p;
	}
}

ll sum(int p){
	ll ret = 0;
	while(p > 0){
		ret += BIT[p];
		p -= p&-p;
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i, 0, n){
		cin >> v[i];
		at.insert(li(v[i], i));
		mp[li(v[i], i)];
	}

	cin >> m;
	fr(i, 0, m){
		cin >> q[i].Y >> q[i].X;
		--q[i].Y;
		mp[q[i]];
	}

	if(n == 1){
		fr(i, 0, m+1)
			cout << "1\n";
		return 0;
	}

	int cnt = 1;
	for(auto &it : mp){
		it.Y = cnt++;
	}

	for(auto it : at){
		add(mp[it], it.X);
	}


	fr(i, 0, m+1){
		int ans = 2;
		ll s = 0;
		auto it = at.begin();
		s += it->X;
		++it;
		s += it->X;

		while((it = at.lower_bound(li(s, -1))) != at.end()){
			if(it->X >= sum(mp[*it] - 1))
				++ans;
			s = sum(mp[*it]);
		}
		
		add(mp[li(v[q[i].Y], q[i].Y)], -v[q[i].Y]);

		at.erase(li(v[q[i].Y], q[i].Y));
		v[q[i].Y] = q[i].X;
		at.insert(q[i]);

		add(mp[q[i]], q[i].X);
	
		cout << ans << endl;
	}
	return 0;
}