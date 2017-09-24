#include <bits/stdc++.h>
#define fr(a, b, c) for(int a  = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 111111, inf = 0x3f3f3f3f;
typedef pair<int, int> ii;

long long int B[ms];
ii v[ms];

void add(int p, int val){
	while(p < ms){
		B[p] += val;
		p += p&-p;
	}
}

long long int sum(int p){
	long long int ans = 0;
	while(p > 0){
		ans += B[p];
		p -= p&-p;
	}
	return ans;
}

long long int calc(int i, int j, int n){
	if(i <= j){
		return sum(j + 1) - sum(i);
	}
	else{
		return calc(i, n-1, n) + calc(0, j, n) ;
	}
}
int at = 0;
int n;

int dist(int val){
	if(val >= at)
		return (val - at);
	else{
		return n - at + val;
	}
}

bool cmp(ii a, ii b){
	return dist(a.second) < dist(b.second);
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i, 0, n){
		cin >> v[i].first;
		v[i].second = i;
		add(i+1, 1);
	}
	sort(v, v+n);
	long long int ans = 0;
	fr(i, 0, n){
		int j = i;
		while(j < n && v[i].first == v[j].first)
			++j;
		sort(v + i, v + j, cmp);
		// dbg("bef" _ ans _ i _ j _ v[i].first)
		fr(k, i, j){
			ans += calc(at, v[k].second, n);
			// dbg(v[k].second _ at)
			add(v[k].second+1, -1);
			at = (v[k].second+1)%n;
		}
		// dbg("af" _ ans)
		i = j-1;
	}
	cout << ans << endl;
	return 0;
}