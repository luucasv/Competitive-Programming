#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)

using namespace std;
typedef long long ll;

const int ms = 50*20 + 100, sigma = 2*26 + 10, mod = int(1e6) + 3;

struct node{
	int adj[26], fail;
	ll mask;
	void init(){
		memset(adj, -1, sizeof adj);
		mask = 0;
		fail = 0;
	}
};

node trie[ms];
int sz;
int A[ms][26];

void add(int idx, char str[]){
	int at = 0, id;
	for(int i = 0; str[i]; ++i){
		id = str[i] - 'a';
		if(trie[at].adj[id] == -1){
			trie[sz].init();
			trie[at].adj[id] = sz++;
		}
		at = trie[at].adj[id];
	}
	trie[at].mask |= (1 << idx);
}

void failure(){
	queue<int> fila;
	fr(i, 0, 26){
		if(trie[0].adj[i] != -1){
			fila.push(trie[0].adj[i]);
		}
	}
	while(!fila.empty()){
		int at = fila.front();
		fila.pop();

		fr(i, 0, 26){
			int nd = trie[at].adj[i];
			int fail = trie[at].fail;
			if(nd == -1)
				continue;

			while(fail && trie[fail].adj[i] == -1)
				fail = trie[fail].fail;
			if(trie[fail].adj[i] != -1)
				fail = trie[fail].adj[i];
			trie[nd].fail = fail;
			trie[nd].mask |= trie[fail].mask;
			fila.push(nd);
		}
	}
}

void process(){
	queue<int> fila;
	fila.push(0);
	while(!fila.empty()){
		int at = fila.front();
		fila.pop();
		fr(i, 0, 26){
			int nd = trie[at].adj[i];
			int fail = trie[at].fail;

			if(nd == -1){
				nd = at;
				while(nd && trie[nd].adj[i] == -1)
					nd = trie[nd].fail;
				if(trie[nd].adj[i] != -1)
					nd = trie[nd].adj[i];
			}
			else{
				fila.push(nd);	
			}

			A[at][i] = nd;
		}
	}
}

int memo[ms][20][2][2][2];
int mp[10];
int a, b;

int dp(int at, int sz, int up, int low, int dig){
	if(sz > b || trie[at].mask)
		return 0;
	if(sz == b && up && low && dig)
		return 1;
	if(sz == b)
		return 0;

	int &ans = memo[at][sz][up][low][dig]; 
	if(~ans)
		return ans;

	ans = (sz >= a && up && low && dig);
	fr(i, 0, 26){
		ans = (ans + dp(A[at][i], sz+1, 1, low, dig)) % mod;
		ans = (ans + dp(A[at][i], sz+1, up, 1, dig)) % mod;
	}
	fr(i, 0, 10){
		if(mp[i] == -1)
			ans = (ans + dp(0, sz+1, up, low, 1)) % mod;
		else
			ans = (ans + dp(A[at][mp[i]], sz+1, up, low, 1)) % mod;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	memset(mp, -1, sizeof mp);
	memset(memo, -1, sizeof memo);
	mp[0] = 'o' - 'a';
	mp[1] = 'i' - 'a';
	mp[3] = 'e' - 'a';
	mp[5] = 's' - 'a';
	mp[7] = 't' - 'a';
	trie[sz++].init();

	cin >> a >> b;

	int n;
	char str[30];
	
	cin >> n;
	fr(i, 0, n){
		cin >> str;
		add(i, str);
	}

	failure();
	process();

	cout << dp(0, 0, 0, 0, 0) << endl;
}