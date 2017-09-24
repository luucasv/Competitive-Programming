#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int ms = int(1e5) + 100;

ll ans;
int v[ms];

int get(int a[]){
	int res = 0;
	if(a[0] != -1)
		res = max(res, v[a[0]]);
	if(a[1] != -1)
		res = max(res, v[a[1]]);
	return res;
}

void go(set<ii>& sh, int dir[][2], int y[], int i){
	auto it1 = sh.insert(ii(y[i], i)).first;
	int to = -1;
	if(sh.begin() != it1){
		auto it2 = it1;
		it2--;
		int k = it2->second;
		int ant = get(dir[k]) + get(dir[i]);
		dir[k][1] = i;
		dir[i][0] = k;
		int dps = get(dir[k]) + get(dir[i]);
		ans += dps - ant;
	}
	it1++;
	if(sh.end() != it1){
		int k = it1->second;
		int ant = get(dir[k]) + get(dir[i]);
		dir[k][0] = i;
		dir[i][1] = k;
		int dps = get(dir[k]) + get(dir[i]);
		ans += dps - ant;
	}
}
int x[ms], y[ms];
int ho[ms][2], ve[ms][2];
map<int, set<ii> > hor, ver;


int main(){
	ios::sync_with_stdio(0);
	memset(ho, -1, sizeof ho);
	memset(ve, -1, sizeof ve);
	int n;
	cin >> n;
	fr(i, 0, n){
		cin >> x[i] >> y[i] >> v[i];
	}
	fr(i, 0, n){
		go(hor[x[i]], ho, y, i);
		go(ver[y[i]], ve, x, i);
		cout << ans << endl;
	}
}