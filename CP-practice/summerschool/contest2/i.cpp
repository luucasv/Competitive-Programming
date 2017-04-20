#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int mod = 13, mv = 201;
int inv[20];

int dist[mv][mv];

map<ii, int> mp;
ii pares[mv];

int preMat[501][mv];
int aux;

struct Vetor{
	vector<int> v;

	Vetor(int sz){
		v = vector<int>(sz, 0);
	}

	Vetor(){}

	int& operator[](int a){
		return v[a];
	}

	Vetor operator*(int val){
		Vetor at(v.size());
		fr(i, 0, v.size()){
			at[i] = v[i]*val;
		}
		return at;
	}

	Vetor operator%(int val){
		Vetor at(v.size());
		fr(i, 0, v.size()){
			at[i] = (v[i]%val + val)%val;
		}
		return at;
	}

	Vetor operator-(Vetor p){
		Vetor at(v.size());
		fr(i, 0, v.size()){
			at[i] = v[i] - p[i];
		}
		return at;
	}
};

Vetor mat[501];

int main(){
	ios::sync_with_stdio(0);
	fr(i, 1, mod){
		inv[i] = 1;
		fr(j, 0, mod-2){
			inv[i] = (inv[i] * i)%mod;
		}
	}

	int n, a, r, t;
	cin >> n >> a >> r >> t;
	--a, --r;
	fr(i, 0, t){
		int p, ls, d;
		cin >> d >> p;
		cin >> ls;
		--ls;
		fr(j, 1, p){
			int at;
			cin >> at;
			--at;
			int a = min(ls, at), b = max(ls, at);
			ii par = ii(a, b);
			if(!mp.count(par)){
				pares[aux] = par;
				mp[par] = aux++;
			}
			preMat[i][mp[par]]++;
			preMat[i][mp[par]] %= mod;
			ls = at;
		}
		preMat[i][mv - 1] = d;
	}

	fr(i, 0, t){
		mat[i] = Vetor(aux+1);
		fr(j, 0, aux){
			mat[i][j] = preMat[i][j];
		}
		mat[i][aux] = preMat[i][mv-1];
	}

	fr(j, 0, aux){
		int i = j;
		while(i < t && mat[i][j] == 0) ++i;
		assert(i < t);
		if(i != j)
			swap(mat[i], mat[j]);
		i = j;
		int iv = inv[mat[i][j]];
		mat[i] = (mat[i]*iv) % mod;
		fr(k, 0, t){
			if(k == i)
				continue;
			int a = mat[k][j];
			mat[k] = (mat[k] - mat[i]*a) % mod;
		}
	}
	memset(dist, 0x3f, sizeof dist);
	fr(i, 0, n)
		dist[i][i] = 0;

	fr(i, 0, aux){
		dist[pares[i].X][pares[i].Y] = dist[pares[i].Y][pares[i].X] = mat[i][aux];
	}

	fr(k, 0, n) fr(i, 0, n) fr(j, 0, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	cout << dist[a][r] << endl;
}