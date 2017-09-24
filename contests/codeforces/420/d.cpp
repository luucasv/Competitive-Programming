#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = int(1e4) + 10, inf = 0x3f3f3f3f;
const int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

set<int> byX[ms], byY[ms], onN, onM;
map<ii, int> mp;
ii v[ms];
int dist[ms];
int mk[ms];

int main(){
	ios::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	fr(i, 0, k){
		int x, y;
		cin >> x >> y;
		--x, --y;
		mp[ii(x, y)] = i;
		v[i] = ii(x, y);
		byX[x].insert(i);
		byY[y].insert(i);
	}
	if(!(mp.count(ii(n-1, m-1)))){
		mp[ii(n-1, m-1)] = k;
		v[k] = ii(n-1, m-1);
		byX[n-1].insert(k);
		byY[m-1].insert(k);
		mk[k] = 1;
		k++;
	}
	int st = mp[ii(0, 0)]; 
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, st));
	while(!pq.empty()){
		ii ft = pq.top();
		pq.pop();
		dbg(ft.second _ dist[k-1])
		if(ft.first > dist[ft.second])
			continue;

		int id = ft.second;
		fr(k, 0, 4){
			int x = v[id].first + di[k], y = v[id].second + dj[k];
			if(mp.count(ii(x, y))){
				int d = ft.first;
				int to = mp[ii(x, y)];
				if(d < dist[to]){
					dist[to] = d + mk[to];
					pq.push(ii(d, to));
				}
			}
		}

		for(auto to : byX[v[id].first]){
			int d = ft.first + 1;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byX[v[id].first].clear();
		for(auto to : byY[v[id].second]){
			int d = ft.first + 1;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byY[v[id].second].clear();
		for(auto to : byX[v[id].first + 1]){
			int d = ft.first + 1;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byX[v[id].first + 1].clear();
		for(auto to : byY[v[id].second + 1]){
			int d = ft.first + 1;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byY[v[id].second  + 1].clear();
		if(v[id].first){
			for(auto to : byX[v[id].first - 1]){
				int d = ft.first + 1;
				if(d < dist[to]){
					dist[to] = d;
					pq.push(ii(d, to));
				}
			}
			byX[v[id].first - 1].clear();
		}
		if(v[id].second){
			for(auto to : byY[v[id].second - 1]){
				int d = ft.first + 1;
				if(d < dist[to]){
					dist[to] = d;
					pq.push(ii(d, to));
				}
			}
			byY[v[id].second - 1].clear();
		}




		for(auto to : byX[v[id].first + 2]){
			int d = ft.first + 2;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byX[v[id].first + 2].clear();
		for(auto to : byY[v[id].second + 2]){
			int d = ft.first + 2;
			if(d < dist[to]){
				dist[to] = d;
				pq.push(ii(d, to));
			}
		}
		byY[v[id].second  + 2].clear();
		if(v[id].first - 2 >= 0){
			for(auto to : byX[v[id].first - 2]){
				int d = ft.first + 2;
				if(d < dist[to]){
					dist[to] = d;
					pq.push(ii(d, to));
				}
			}
			byX[v[id].first - 2].clear();
		}
		if(v[id].second - 2 >= 0){
			for(auto to : byY[v[id].second - 2]){
				int d = ft.first + 2;
				if(d < dist[to]){
					dist[to] = d;
					pq.push(ii(d, to));
				}
			}
			byY[v[id].second - 2].clear();
		}
	}
	int id = mp[ii(n-1, m-1)];
	if(dist[id] >= inf)
		dist[id] = -1;
	cout << dist[id] << endl;
	return 0;
}