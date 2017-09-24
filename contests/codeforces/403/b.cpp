#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = 11111;
ii v[ms];
string names[2*ms];

int ans[ms];
int vis[ms];
map<string, int> mp;
int rt[2*ms], sz[2*ms], ed[2*ms];
std::vector<int> has[2*ms], sd[2*ms];
int root(int i){
	if(i == rt[i])
		return i;
	return rt[i] = root(rt[i]);
}

int conn(int a, int b){
	a = root(a), b = root(b);
	if(a == b){
		++ed[b];
	}
	else{
		rt[a] = b;
		ed[b] += ed[a];
		sz[b] += sz[a] + 1;
	}

	return sz[b] < ed[b];
}

bool can(int a){
	bool good = 1;
	queue<int> fila;
	fila.push(a);
	std::vector<int> v2, ve;
	while(!fila.empty()){
		if(!good)
			break;
		int i = fila.front(); fila.pop();
		v2.push_back(i);
		fr(j, 0, has[i].size()){
			int k = has[i][j];
			if(ans[k])
				continue;
			if(vis[v[k].Y])
				good = 0;
			else
				fila.push(v[k].Y);
			
			vis[v[k].Y] = 1;
			ans[k] = v[k].Y;
			ve.push_back(k);
		}
		fr(j, 0, sd[i].size()){
			int k = sd[i][j];
			if(ans[k])
				continue;
			if(vis[v[k].X])
				good = 0;
			else
				fila.push(v[k].X);
			
			vis[v[k].X] = 1;
			ans[k] = v[k].X;
			ve.push_back(k);
		}
	}
	if(!good){
		fr(i, 0, ve.size())
			ans[ve[i]] = 0;
		fr(i, 0, v2.size())
			vis[v2[i]] = 0;
	}
	return good;
}

int main(){
	ios::sync_with_stdio(0);
	int n, aux = 1;
	cin >> n;
	fr(i, 0, n){
		string a, b, c, d;
		cin >> a >> b;
		c = a.substr(0, 3), d = a.substr(0, 2) + b[0];
		if(!mp.count(c)){
			names[aux] = c;
			mp[c] = aux++;
		}
		if(!mp.count(d)){
			names[aux] = d;
			mp[d] = aux++;
		}
		v[i] = ii(mp[c], mp[d]);
		has[mp[c]].push_back(i);
		sd[mp[c]].push_back(i);
	}

	bool good = 1;

	fr(i, 0, aux){
		if(has[i].size() > 1){
			fr(j, 0, has[i].size()){
				int k = has[i][j];
				if(vis[v[k].Y])
					good = 0;
				vis[v[k].Y] = 1;
				ans[k] = v[k].Y;
			}
			has[i].clear();
		}
	}


	queue<int> fila;
	fr(i, 0, aux){
		rt[i] = i;
		sz[i] = 1;
		ed[i] = 0;
		if(vis[i])
			fila.push(i);
	}

	while(!fila.empty()){
		if(!good)
			break;
		int i = fila.front(); fila.pop();
		fr(j, 0, has[i].size()){
			int k = has[i][j];
			if(ans[k])
				continue;
			if(vis[v[k].Y])
				good = 0;
			else
				fila.push(v[k].Y);
			
			vis[v[k].Y] = 1;
			ans[k] = v[k].Y;
		}
		has[i].clear();
		fr(j, 0, sd[i].size()){
			int k = sd[i][j];
			if(ans[k])
				continue;
			if(vis[v[k].X])
				good = 0;
			else
				fila.push(v[k].X);
			
			vis[v[k].X] = 1;
			ans[k] = v[k].X;
		}
		sd[i].clear();
	}

	fr(i, 0, n){
		if(ans[i])
			continue;
		if(conn(v[i].X, v[i].Y))
			good = 0;
	}

	if(!good){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	fr(i, 0, n){
		if(ans[i])
			continue;
		ans[i] = v[i].X;
		if(!can(v[i].X)){
			ans[i] = v[i].Y;
			can(v[i].Y);
		}
	}

	fr(i, 0, n)
		cout << names[ans[i]] << endl;
	return 0;
}