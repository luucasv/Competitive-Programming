#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define dbg(x) cerr << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
const int mv = 1111111, me = 2*mv;

typedef long long int ll;
typedef pair<ll, int> ii;
typedef pair<ii, int> iii;

int ant[me], to[me], w[me], adj[mv];
int s[mv];
int n, k, l, z;

ll dist[mv], dist2[mv];
int from[mv], from2[mv];

void add(int a, int b, int c){
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, w[z] = c, adj[a] = z++;
}

void solve(){
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	memset(dist, 0x3f, sizeof dist);
	memset(dist2,0x3f, sizeof dist2);
	memset(from, -1, sizeof from);
	memset(from2, -1, sizeof from2);
	fr(i, 0, n){
		pq.push(iii(ii(0, s[i]), s[i]));
		if(dist[s[i]] != 0x3f3f3f3f3f3f3f3fLL){
			dist2[s[i]] = 0;
			from2[s[i]] = s[i];

		}
		else{
			dist[s[i]] = 0;
			from[s[i]] = s[i];
		}
	}
	
	while(!pq.empty()){
		iii tp = pq.top();
		pq.pop();

		if(dist2[tp.X.Y] < tp.X.X)
			continue;

		int u = tp.X.Y, fr = tp.Y;
		ll d = tp.X.X;

		fre(i, u){
			int v = to[i];
			ll ndist = d + w[i];
			if(ndist < dist[v]){
				if(from[v] != fr){
					dist2[v] = dist[v];
					from2[v] = from[v];
				}
				dist[v] = ndist;
				from[v] = fr; 
				pq.push(iii(ii(ndist, v), fr));
			}
			else if(ndist < dist2[v]){
				if(from[v] != fr){
					dist2[v] = ndist;
					from2[v] = fr;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	cin >> n >> k >> l;
	fr(i, 0, n){
		cin >> s[i];
		--s[i];
	}
	fr(i, 0, l){
		int a, b, c;
		cin >> a >> b >> c;
		--a,--b;
		add(a, b, c);
	}

	solve();

	ll ans = dist[0] + dist2[0];
	fr(i, 0, k){
		ans = min(ans, dist[i] + dist2[i]);
	}

	cout << 3*ans << endl;
}