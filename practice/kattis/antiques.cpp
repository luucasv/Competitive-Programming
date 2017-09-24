#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;
const int mv = 44;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

ll adj[mv], eco[mv];
ll maxi[22][1 << 21], ans;
int m2, n, m, k;

void bt(int v, ll mask, ll cost){
	if(__builtin_popcount(int(mask&((1LL << m2) - 1))) > k)
		return;
	if(v == m2){
		mask &= ((1LL << m2) - 1);
		int ma = mask, c = __builtin_popcountll(mask);
		maxi[c][ma] = max(maxi[c][ma], cost);
		return;
	}
	bt(v+1, mask | (1LL << v), cost + eco[v]);
	if((mask >> v)&1)
		return;
	ll aux = adj[v] & ((1LL << v) - 1);
	if((aux | mask) == mask)
		bt(v+1, mask | adj[v], cost);
	
}

void bt2(int v, ll mask, ll cost){
	if(v == m){
		int ma = (mask & ((1LL << m2) - 1));
		mask &= ~((1LL << m2) - 1);
		int c = __builtin_popcountll(mask);
		if(c > k)
			return;
		ans = max(ans, cost + maxi[min(m2, k-c)][ma]);
		return;
	}
	bt2(v+1, mask | (1LL << v), cost + eco[v]);
	if((mask >> v)&1)
		return;
	ll aux = (adj[v] & ((1LL << v) - 1)) & (~((1LL << m2)-1));
	if((aux | mask) == mask)
		bt2(v+1, mask | adj[v], cost);
}

int main(){
	ios::sync_with_stdio(0);
	memset(maxi, ~0x3f, sizeof maxi);
	cin >> n >> m >> k;
	ll cost = 0;
	fr(i, 0, n){
		int a, p, b, q;
		cin >> a >> p >> b >> q;
		--a, --b;
		adj[a] |= (1LL << b);
		adj[b] |= (1LL << a);
		cost += max(p, q);
		eco[a] += max(p, q) - p;
		eco[b] += max(p, q) - q;
	}
	m2 = (m + 1) / 2;
	bt(0, 0, 0);
	fr(q, 1, min(k, m2)+1){
		for(int ma = (1 << m2) - 1; ma > -1; --ma){
			if(__builtin_popcount(ma) >= q)
				continue;
			maxi[q][ma] = max(maxi[q][ma], maxi[q-1][ma]);
			fr(v, 0, m2){
				maxi[q][ma] = max(maxi[q][ma], maxi[q][ma | (1 << v)]);
			}
		}
	}
	ans = ~inf;
	bt2(m2, 0, 0);
	if(ans < 0)
		ans = -1;
	else
		ans = cost - ans;
	cout << ans << endl;
	return 0;
}