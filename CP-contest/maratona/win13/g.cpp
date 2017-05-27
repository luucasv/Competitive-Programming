#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

const int ms = 111, mt = 25111;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

const int mv = 10011, me = 2*50011;

int ant[me], to[me], adj[mv], w[me], z;


inline void add(int a, int b, int c){
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
}


ll dist[mv];

ll dijkstra(int s, int ed = 0){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	pq.push(ii(0, s));
	while(!pq.empty()){
		ii tp = pq.top();
		pq.pop();
		if(tp.X > dist[tp.Y])
			continue;
		fre(i, tp.Y){
			ll d = tp.X + w[i];
			if(dist[to[i]] > d){
				dist[to[i]] = d;
				pq.push(ii(d, to[i]));
			}
		}
	}
	return dist[ed];
}


int q;

ll memo[(1 << 8)][10];
int mk[(1 << 8)][10], step;
ll ndist[8][8];
int p[8];

ll dp(int mask, int ls){
	if(mask == 0)
		return dist[p[ls]];
	if(mk[mask][ls] == step)
		return memo[mask][ls];
	mk[mask][ls] = step;
	ll ans = inf;
	fr(i, 0, q){
		if((mask >> i)&1){
			ans = min(ans, ndist[ls][i] + dp(mask & (~(1 << i)), i));
		}
	}
	return memo[mask][ls] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){	
		++step;
		int n, m;
		cin >> n >> m;
		memset(adj, -1, n*sizeof(int));
		z = 0;
		fr(i, 0, m){
			int a, b, l;
			cin >> a >> b >> l;
			add(a, b, l);
		}
		
		cin >> q;
		fr(i, 0, q)
			cin >> p[i];
		
		fr(i, 0, q){
			fr(j, i+1, q){
				ndist[i][j] = ndist[j][i] = dijkstra(p[i], p[j]);
			}
		}
		dijkstra(0);
		
		ll l;
		cin >> l;
		
		int ans = 0;
		fr(i, 0, (1 << q)){
			fr(j, 0, q){
				if((i >> j)&1)
					continue;
				if(dp(i, j) + dist[p[j]] <= l){
					ans = max(ans, __builtin_popcount(i) + 1);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}










