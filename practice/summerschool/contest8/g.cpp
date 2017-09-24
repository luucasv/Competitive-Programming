
#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < (b); i++)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define X first
#define Y second
#define pb push_back
#define sc(a) scanf("%d", &a)
#define mp make_pair

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> i4;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

const int inf = 0x3f3f3f3f;
const int ms = 1111, me = 41111;

int adj[ms], to[me], w[me], from[me], ant[me];

int dist[ms][ms], z;
int n, m;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, from[z] = a, adj[a] = z++;
}

void bfs(int d[], int s){
	d[s] = 0;
	queue<int> fila;
	fila.push(s);
	while(!fila.empty()){
		int u = fila.front(); fila.pop();
		fre(i, u){
			int v = to[i];
			if(d[v] == -1){
				fila.push(v);
				d[v] = d[u] + 1;
			}
		}
	}
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	memset(adj, -1, sizeof adj);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fr(i, 0, m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b);
	}

	memset(dist, -1, sizeof dist);

	fr(i, 0, n){
		bfs(dist[i], i);
	}

	int ans = 1;
	fr(i, 0, z){
		int cnt = 0;
		fr(x, 0, n){
			if(dist[from[i]][x] != -1 && dist[x][to[i]] != -1){
				++cnt;
			}
		}
		ans = max(ans, cnt);
	}

	std::vector<int> res;

	fr(i, 0, z){
		int cnt = 0;
		fr(x, 0, n){
			if(dist[from[i]][x] != -1 && dist[x][to[i]] != -1){
				++cnt;
			}
		}
		if(cnt == ans)
			res.push_back(i+1);
	}

	cout << ans << endl << res.size() << endl;
	fr(i, 0, res.size())
		cout << res[i] << " ";
	cout << endl;
	return 0;
}