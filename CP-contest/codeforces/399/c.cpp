#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

map<vector<int>, int> mk;
int n, k,x;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k >> x;
	fr(i, 0, n){
		int a;
		cin >> a;
		v.push_back(a);
	}
	int i = 0;
	sort(v.begin(), v.end());
	while(i < k && !mk.count(v)){
		mk[v] = i++;
		fr(k, 0, n){
			v[k] ^= x; 
			++k;
		}

		sort(v.begin(), v.end());
	}
	dbg(i _ mk[v])
	if(i == k){
		cout << v[n-1] << " " << v[0] << endl;
	}
	else{
		int t = i - mk[v];
		k -= mk[v];
		k %= t;
		k += mk[v];
		for(auto it : mk){
			if(it.second == k){
				cout << it.first[n-1] << " " << it.first[0] << endl;
				break;
			}
		}
	}
	return 0;
}