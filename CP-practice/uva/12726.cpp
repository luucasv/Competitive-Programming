#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f;

string s;
int n, m, k;

int step;
int mask[21];
int dist[1 << 20], mark[1 << 20];

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		cout << "Case #" << cas++ << ": ";
		memset(mask, 0, sizeof mask);
		cin >> n >> m >> k;
		fr(i, 0, m){
			int a, b;
			cin >> a >> b;
			--a, --b;
			mask[a] |= 1 << b;
			mask[b] |= 1 << a;
		}
		++step;
		int ans = -1;
		queue<int> fila;
		dist[mask[0]] = 0;
		fila.push(mask[0]);
		
		while(!fila.empty()){
			int mk = fila.front();
			fila.pop();
			
			if((mk >> (n-1))&1){
				ans = dist[mk] - 1;
				break;
			}
			
			fr(i, 1, n){
				if((mk >> (i))&1)
					continue;
				
				int ne = mk | (1 << i);
				
				if(__builtin_popcount(mk & mask[i]) >= k && mark[ne] != step){
					mark[ne] = step;
					dist[ne] = 1 + dist[mk];
					fila.push(ne);
				}
			}
		}
		if((mask[0] >> (n-1))&1){
			ans = 0;
		}
		cout << ans << endl;
	}
	return 0;
}