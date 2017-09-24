#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ma = int(1e7);
typedef pair<int, int> ii;
string t[1111111];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	std::vector<ii> v;
	fr(i, 0, n){
		cin >> t[i];
		int k, a;
		cin >> k;
		fr(oi, 0, k){
			cin >> a;
			v.push_back(ii(a-1, i));
			v.push_back(ii(a-2 + t[i].size(), i + ma));
		}
	}
	sort(v.begin(), v.end());
	set<ii> in;
	int i = 0, vi = 0;
	while(vi < v.size()){
		while(v[vi].first == i && v[vi].second < ma){
			in.insert(ii(v[vi].second, i));
			++vi;
		}
		if(in.empty()){
			cout << 'a';
		}
		else{
			ii p = *in.begin();
			cout << t[p.first][i - p.second];
		}
		while(vi < v.size() && v[vi].first == i){
			int id = v[vi].second - ma;
			in.erase(ii(id, i + 1 - t[id].size()));
			++vi;
		}
		++i;
	}
	cout << endl;
	return 0;
}