// Algoritmo Aho-corasick O(z + n + m)
// 10679 - I Love Strings!!

#include <bits/stdc++.h>
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a, b) for(int a = adj[b]; a != -1; a = ant[a])
#define frei(a, b) for(int a = adji[b]; a != -1; a = anti[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf(" %s", s)
#define pri(x) printf("%d\n", x)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define EPS 1e-9

#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int inf = 0x3f3f3f3f;
const int minusinf = -inf;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vii;
typedef std::pair<int, int> pii;

const int msize = 1000100, sigma = 2*26;
int z = 1;
int trie[msize][sigma], fail[msize], nxt[msize], fila[msize];
vi out[msize];
int fnd[1111], step;

void init(int id){
	if(id == 0) z = 1;//se estou limpando a raiz, estou limpandoa trie toda
	cl(trie[id], -1);
	out[id].clear();
	nxt[id] = fail[id] = -1;
}

inline int get_id(const char &a){
	if(a >= 'a' && a <= 'z') return (a - 'a');
	return (a - 'A' + 26);
}

void add(char* str, int idx){ //idx = "pointer" to the string
	int cur = 0;
	for(int i = 0; str[i]; ++i){
		int id = get_id(str[i]);
		if(trie[cur][id] == -1){
			init(z);
			trie[cur][id] = z++;
		}
		cur = trie[cur][id];
	}
	out[cur].pb(idx);
}

void set_fail(){
	int ini = 0, fim = 1;
	int u;
	fr(i, 0, sigma){
		if(~(u = trie[0][i])){
			fail[u] = 0;
			nxt[u] = (out[0].size()) ?  0 : -1;
			fila[fim++] = u;
		}
	}
	while(ini < fim){
		u = fila[ini++];

		rp(i, sigma){
			int v = trie[u][i];
			int f = fail[u];
			if(v == -1) continue;
			fila[fim++] = v;
			while(f && trie[f][i] == -1) f = fail[f];
			if(~trie[f][i]) f = trie[f][i];
			fail[v] = f;
			nxt[v] = (out[f].size()) ? f : nxt[f];
		}
	}
}

void search(char* txt){
	int cur = 0;
	for(int i = 0; txt[i]; i++){
		int id = get_id(txt[i]);
		while(cur && trie[cur][id] == -1) cur = fail[cur];
		if(~trie[cur][id]) cur = trie[cur][id];
		int aux = cur;
		while(~aux){
			rp(k, out[aux].size()) fnd[out[aux][k]] = step;
			aux = nxt[aux];
		}
	}
}

char txt[100010], str[1010];
int main(){
	ios::sync_with_stdio(0);
	cl(fnd, -1);
	int T;
	cin >> T;
	while(T--){
		cin >> txt;
		int q;
		cin >> q;
		init(0);
		fr(i, 0, q){
			cin >> str;
			add(str, i);
		}
		set_fail();
		step++;
		search(txt);
		fr(i, 0, q)
			puts(fnd[i] == step ? "y" : "n");
	}
}
