#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
const int ms = int(1e5) + 100;

vector<int> con[ms];
int rt[ms], val[ms];

void init(int n){
	fr(i, 0, n){
		rt[i] = i;
		val[i] = 0;
		con[i] = vector<int>(1, i);
	}
}

int root(int i){
	if(rt[i] == i)
		return i;
	return rt[i] = root(rt[i]);
}

void conn(int i, int j, int diff){
	int pi = root(i), pj = root(j);
	if(pi == pj){
		assert(val[j] - val[i] == diff);
		return;
	}
	
	if(con[pi].size() < con[pj].size()){
		swap(pi, pj);
		swap(i, j);
		diff *= -1;
	}
	
	int add = diff - (val[j] - val[i]);
	for(int k : con[pj]){
		con[pi].push_back(k);
		rt[k] = pi;
		val[k] += add;
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n, m;
	while(cin >> n >> m, n+m){
		init(n);
		while(m--){
			char t;
			int a, b;
			cin >> t >> a >> b;
			--a, --b;
			if(t == '?'){
				if(root(a) != root(b)){
					cout << "UNKNOWN\n";
				}
				else{
					cout << val[b] - val[a] << endl;
				}
			}
			else{
				int w;
				cin >> w;
				conn(a, b, w);
			}
		}
	}
	return 0;
}






