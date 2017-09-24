#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define X first
#define Y second

using namespace std;
typedef pair<double, double> dd;
int c[20];
int n;
vector<int> adj[20];
dd v[20];

int go(int i){
	if(i == n){
		int ans = 0;
		fr(u, 0, n){
			ans = max(ans, c[u]);
			for(int v : adj[u]){
				if(c[u] == c[v])
					return 5;
			}
		}
		return ans + 1;
	}
	int ans = 5;
	fr(j, 0, 4){
		c[i] = j;
		ans = min(ans, go(i+1));
	}
	return ans;
}

double dist(dd a, dd b){
	double x = a.X - b.X, y = a.Y - b.Y;
	return x*x + y*y;
}

int main(){
	ios::sync_with_stdio(0);
	int cas = 1;
	while(cin >> n, n){
		fr(i, 0, n)
			cin >> v[i].X >> v[i].Y;
		fr(i, 0, n){
			adj[i].clear();
			fr(j, 0, n){
				if(i == j)
					continue;
				if(dist(v[i], v[j]) <= 20*20){
					adj[i].push_back(j);
				}
			}
			assert(adj[i].size() <= 4);
		}
		cout << "The towers in case " << cas++ << " can be covered in " << go(0) << " frequencies.\n";
	}
}