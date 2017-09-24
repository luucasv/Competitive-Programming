#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;

typedef long long int ll;
typedef pair<int, int> li;

const int mv = 1e5 + 100, me = 2 * mv, mcolor = 2 * mv + 100;

int at, n;
int size[mcolor];
int color[mv];
set<int> clist[mcolor];

int ant[me], to[me], adj[mv];
int vis[mv];
int z, step;

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

void connect(int a, int b){
	int ca = color[a], cb = color[b];
	if(clist[ca].size() > clist[cb].size()){
		swap(a, b);
		swap(ca, cb);
	}

	add(a, b);
	auto it = clist[ca].begin();
	while(it != clist[ca].end()){
		color[*it] = cb;
		clist[cb].insert(*it);
		clist[ca].erase(it);
		it = clist[ca].begin();
	}
}

void disconnect(int a, int b){
	queue<int> fa, fb;
	set<int> la, lb;

	fa.push(adj[a]);
	fb.push(adj[b]);

	la.insert(a);
	lb.insert(b);

	int c = color[a];
	while(!fa.empty() && !fb.empty()){
		int &tpa = fa.front();
		int &tpb = fb.front();
		if(to[tpa] == b){
			to[tpa] = -1;
			to[tpa^1] = -1;
		}
		else if(to[tpb] == a){
			to[tpb] = -1;
			to[tpb^1] = -1;
		}

		if(to[tpa] != -1 && vis[to[tpa]] != step){
			vis[to[tpa]] = step;
			la.insert(to[tpa]);
			fa.push(adj[to[tpa]]);
		}
		tpa = ant[tpa];

		if(to[tpb] != -1 && vis[to[tpb]] != step){
			vis[to[tpb]] = step;
			lb.insert(to[tpb]);
			fb.push(adj[to[tpb]]);
		}
		tpb = ant[tpb];

		while(!fa.empty() && fa.front() == -1)
			fa.pop();
		while(!fb.empty() && fb.front() == -1)
			fb.pop();
	}

	if(fa.empty()){
		clist[at] =  la;
		for(auto it : la){
			clist[c].erase(it);
			color[it] = at;
		}
	}
	else{
		clist[at] = lb;
		for(auto it : lb){
			clist[c].erase(it);
			color[it] = at;
		}
	}

	++at;
}

int main(){
	ios::sync_with_stdio(0);
	memset(adj, -1, sizeof adj);
	cin >> n;
	fr(i, 0, n){
		size[i] = 1;
		color[i] = i;
		clist[i].insert(i);
	}
	at = n;

	while(1){
		int a, b;
		char ch;
		cin >> ch;
		if(ch == 'E')
			break;

		cin >> a >> b;
		--a, --b;
		if(ch == 'C'){
			connect(a, b);
		}
		else if(ch == 'D'){
			++step;
			disconnect(a, b);
		}
		else{
			cout << (color[a] == color[b] ? "YES" : "NO") << endl;
			cout.flush();
		}
	}
}