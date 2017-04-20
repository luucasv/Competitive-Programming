/*
	Codeforces: 796C. Bank Hacking
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int inf = int(1e9) + 10;

int val[311111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	map<int, int> cnt;
	vector<ii> v(3, ii(-inf, -1)), ma(n, ii(-inf, -1));
	vector<vector<int> > adj(n);
	fr(i, 0, n){
		ii a;
		cin >> a.first;
		val[i] = a.first;
		a.second = i;
		v.push_back(a);
		sort(v.begin(), v.end(), greater<ii>());
		v.pop_back();
		cnt[val[i]]++;
	}
	fr(i, 1, n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(val[b]);
		adj[b].push_back(val[a]);
		ma[a] = max(ma[a], ii(val[b], b));
		ma[b] = max(ma[b], ii(val[a], a));
	}
	if(n <= 2){
		cout << max(v[0].first, v[1].first + 1) << endl;
		return 0;
	}
	int ans = inf;
	fr(i, 0, n){
		int k = ma[i].second, maior;
		fr(j, 0, 3){
			if(v[j].second != i && v[j].second != k){
				maior = v[j].first;
				break;
			}
		}
		if(maior > ma[i].first){
			ans = min(ans, max(val[i], max(ma[i].first + 1, maior + 2)));
		}
		else{
			int c = 0;
			for(auto it : adj[i]){
				if(it == maior)
					++c;
			}
			if(maior == val[i])
				++c;
			if(c == cnt[maior]){
				ans = min(ans, max(val[i], val[k]+1));
			}
			else{
				ans = min(ans, max(val[i], max(val[k] + 1, maior+2)));
			}
		}
	}
	cout << ans << endl;
	return 0;
}