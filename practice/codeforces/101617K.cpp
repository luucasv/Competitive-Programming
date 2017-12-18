#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>> " << x << endl;
#define _ << " , " << 
#define get_id(ch) (ch == 'T' ? 1 : 0)
using namespace std;
const int mv = 4010, me = 2 * mv;

int ant[me], to[me], adj[mv], z;
int rant[me], rto[me], radj[mv];
int n;

inline void add(int a, int b) {
	if (a > 0) {
		a--;
	} else {
		a = -a + n - 1;
	}
	if (b > 0) {
		b--;
	} else {
		b = -b + n - 1;
	}
	ant[z] = adj[a], to[z] = b, adj[a] = z;
	swap(a, b);
	rant[z] = radj[a], rto[z] = b, radj[a] = z++;
}


int step;
void dfs(int mk[], int u) {
	mk[u] = step;
	for (int i = adj[u]; i > -1; i = ant[i]) {
		if(mk[to[i]] != step) dfs(mk, to[i]);
	}
}

void rdfs(int mk[], int u) {
	mk[u] = step;
	for (int i = radj[u]; i > -1; i = rant[i]) {
		if(mk[rto[i]] != step) rdfs(mk, rto[i]);
	}
}

int m1[mv], m2[mv], m3[mv], m4[mv];

int main() {
	memset(adj, -1, sizeof adj);
	memset(radj, -1, sizeof radj);
	int m;
	cin >> n >> m;
	fr(i, 0, m) {
		int a, b;
		cin >> a >> b;
		add(-a, b);
		add(-b, a);
	}
	
	// cout << "eae\n";
	
	int ans = 10;
	
	fr(x, 0, n) {
		++step;
		dfs(m1, x);
		dfs(m2, x + n);
		rdfs(m3, x + n);
		rdfs(m4, x);
		
		int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
		fr(y, 0, n) {
			if (m1[y + n] == step) c1++;
			if (m2[y + n] == step) c2++;
			if (m3[y] == step) c3++;
			if (m4[y] == step) c4++;
		}
		if (m1[x + n] == step && m2[x] == step) {
			ans = 0;
		}
		
		if (m1[x + n] == step && c2 && c4) {
			ans = min(ans, 1);
		}
		
		if (m2[x] == step && c1 && c3) {
			ans = min(ans, 1);
		}
		
		if (c1 && c2 && c3 && c4) {
			ans = min(ans, 2);
		}
		
	}
	
	if (ans == 10)
		ans = -1;
	
	cout << ans << endl;
}