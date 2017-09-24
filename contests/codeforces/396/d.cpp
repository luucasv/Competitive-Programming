#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll mod = ll(1e9) + 7;
const int ms = 111111, inf  = 11111;

map<string, int> mp;
int n, m, q;

int rt[ms], op[ms];

int root(int i){
	if(i == -1)
		return -1;

	if(i == rt[i])
		return i;

	return rt[i] = root(rt[i]);
}

bool conn(int i, int j){
	if(i == -1 || j == -1)
		return 0;

	i = root(i), j = root(j);
	if(i == j)
		return 1;
	
	assert((i == root(op[j])) == (j == root(op[i])));

	if(root(i) == root(op[j]))
		return 0;

	if(op[j] == -1)
		op[j] = op[i];
	rt[i] = j;
	conn(op[j], op[i]);
	return 1;
}

bool cop(int i, int j){
	i = root(i), j = root(j);
	if(i == j)
		return 0;
	if(op[i] == -1)
		op[i] = j;
	if(op[j] == -1)
		op[j] = i;
	conn(i, op[j]);
	conn(j, op[i]);
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	memset(op, -1, sizeof op);
	cin >> n >> m >> q;
	fr(i, 0, n){
		string a;
		cin >> a;
		mp[a] = i;
		rt[i] = i;
	}

	fr(i, 0, m){
		string a, b;
		int t;
		cin >> t >> a >> b;
		if(t == 1)
			cout << (conn(mp[a], mp[b]) ? "YES" : "NO") << endl;
		else
			cout << (cop(mp[a], mp[b]) ? "YES" : "NO") << endl;
	}

	fr(i, 0, q){
		string a, b;
		cin >> a >> b;
		int ia = root(mp[a]), ib = root(mp[b]);
		// dbg(ia _ op[ia] _ ib _ op[ib])
		assert((root(ia) == root(op[ib])) == (root(ib) == root(op[ia])));
		if(root(ia) == root(ib))
			cout << "1\n";
		else if(root(ia) == root(op[ib]))
			cout << "2\n";
		else
			cout << "3\n";
	}


	return 0;
}