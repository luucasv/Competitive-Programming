// Solving Spoj COT
// O((N + M) * log(N))

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

struct Node{
	Node *left, *right;
	int sum;
	Node(){}
	Node(int val){
		left = right = NULL;
		sum = val;
	}
};
// no nosso caso o número de segtrees é igual ao número de nós no vetor.
// a segtree n é vazia
class PersistentSegTree{
public:
	PersistentSegTree(){}
	PersistentSegTree(int n):n(n){
		roots.assign(n+1, (Node *) NULL);
		roots[n] = build(0, n-1);
	}
	void createTree(int newId, int pos, int val){
		updateTree(newId, pos, val, n);
	}
	void updateTree(int newId, int pos, int val, int treeId){
		assert(roots[treeId] != NULL);
		roots[newId] = updateTree(roots[treeId], 0, n-1, pos, val);
	}

	Node* getRoot(int id){
		return roots[id];
	}

private:
	vector<Node*> roots;
	int n;

	Node *build(int l, int r){
		if(l == r)
			return new Node(0);
		Node *cur = new Node();
		int mid = (l+r)/2;
		cur->left = build(l, mid);
		cur->right = build(mid+1, r);
		cur->sum = cur->left->sum + cur->right->sum;
		return cur;
	}

	Node *updateTree(Node* at,int l, int r, int pos, int val){
		if(pos < l || pos > r)
			return at;
		if(l == r){
			return new Node(at->sum + val);
		}
		Node *cur = new Node();
		int mid = (l+r)/2;
		cur->left = updateTree(at->left, l, mid, pos, val);
		cur->right = updateTree(at->right, mid+1, r, pos, val);
		cur->sum = cur->left->sum + cur->right->sum;
		return cur;
	}
};
 

// graph
const int mv = 100011, me = 2*mv, mlog = 19;
int adj[mv], w[mv], P[mlog][mv], level[mv];
int to[me], ant[me], z;

void init(int n){
	memset(adj, -1, n * sizeof(int));
	z = 0;
}

inline void add(int a, int b){
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
	swap(a, b);
	ant[z] = adj[a], to[z] = b, adj[a] = z++;
}

void dfs(int v, int par){
	P[0][v] = par;
	level[v] = level[par] + 1;
	for(int i = adj[v]; i != -1; i = ant[i]){
		if(to[i] != par)
			dfs(to[i], v);
	}
}

void preprocesLCA(int n){
	dfs(0, 0);
	fr(l, 1, mlog){
		fr(i, 0, n){
			P[l][i] = P[l-1][P[l-1][i]];
		}
	}
}

int lca(int u, int v){
	if(level[v] < level[u])
		swap(u, v);
	int diff = level[v] - level[u];
	fr(i, 0, mlog){
		if(diff & (1 << i))
			v = P[i][v];
	}
	if(u == v)
		return u;
	for(int l = mlog - 1; l > -1; l--){
		if(P[l][u] != P[l][v]){
			u = P[l][u];
			v = P[l][v];
		}
	}
	return P[0][v];
}

PersistentSegTree segs;
map<int, int> mp;
int reverseMap[mv];

void createTrees(int v){
	segs.updateTree(v, w[v], 1, P[0][v]);
	for(int i = adj[v]; i != -1; i = ant[i]){
		if(to[i] != P[0][v]){
			createTrees(to[i]);
		}
	}
}

inline int calc(Node *u, Node *v, Node *l, Node *p){
	return u->left->sum + v->left->sum - l->left->sum - p->left->sum;
}

int solve(int u, int v, int k, int n){
	int l = lca(u, v), p = P[0][l];
	Node *sl = segs.getRoot(l), 
	*sp = segs.getRoot(p),
	*su = segs.getRoot(u),
	*sv = segs.getRoot(v);
	int left = 0, right = n-1;
	while(left != right){
		int mid = (left + right)/2;
		if(calc(su, sv, sl, sp) >= k){
			su = su->left;
			sv = sv->left;
			sl = sl->left;
			sp = sp->left;
			right = mid;
		}
		else{
			k -= calc(su, sv, sl, sp);
			su = su->right;
			sv = sv->right;
			sl = sl->right;
			sp = sp->right;
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	fr(i, 0, n){
		scanf("%d", w + i);
		mp[w[i]];
	}
	int aux = 0;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
		it->second = aux;
		reverseMap[aux++] = it->first;
	}
	fr(i, 0, n){
		w[i] = mp[w[i]];
	}

	init(n);
	fr(i, 1, n){
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		add(a, b);
	}
	preprocesLCA(n);
	P[0][0] = n;
	segs = PersistentSegTree(n);
	createTrees(0);
	while(m--){
		int u, v, k;
		scanf("%d %d %d", &u, &v, &k);
		--u, --v;
		printf("%d\n", reverseMap[solve(u, v, k, n)]);
	}
}