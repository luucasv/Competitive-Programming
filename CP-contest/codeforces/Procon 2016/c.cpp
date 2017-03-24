#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " <<

#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const int mv = 111111, me = 2*mv;
int adj[mv], to[me], ant[me], z;
int vis[mv], d[mv], step;
int l[mv], cnt[1 << 10];
ll c[mv], ans[mv], cost[mv];


int n, m, p, k;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

void bfs(int v, int c){
	queue<int> fila;
	fila.push(v);
	++step;
	vis[v] = step;
	d[v] = 0;
	while(!fila.empty()){
		v = fila.front(); fila.pop();
		cost[v] |= (1 << c); 
		fre(i, v){
			int u = to[i];
			if(vis[u] != step && d[v]+1 <= k){
				fila.push(u);
				vis[u] = step;
				d[u] = d[v]+1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	cin >> n >> m >> p >> k;
	fr(i, 0, p){
		cin >> l[i];
		--l[i];
	}
	fr(i, 0, p)
		cin >> c[i];
	
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}
	
	fr(i, 0, p){
		bfs(l[i], i);
	}
	
	fr(i, 0, (1 << p)){
		fr(j, 0, p){
			if((i >> j)&1)
				cnt[i] += c[j];
		}
	}
	
	fr(i, 0, n){
		ans[i] = (1 << p) - 1;
	}
	
	int s, t;
	cin >> s >> t;
	--s, --t;
	
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	ans[s] = 0;
	while(!pq.empty()){
		ii tp = pq.top();
		pq.pop();
		if(cnt[ans[tp.Y]] < tp.X)
			continue;
		if(tp.Y == t)
			break;
		fre(i, tp.Y){
			int v = to[i];
			if(cnt[ans[v]] > cnt[ans[tp.Y] | cost[tp.Y]]){
				ans[v] = ans[tp.Y] | cost[tp.Y];
				pq.push(ii(cnt[ans[v]], v));
			}
		}
	}
	
	cout << cnt[ans[t] | cost[t]] << endl;
	
	return 0;
}