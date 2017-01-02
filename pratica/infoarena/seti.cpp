/*
	
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(0) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

struct entry{
	int pre, suf, id;

	entry(){}
	entry(int a, int b, int id): pre(a), suf(b), id(id){}
	bool operator< (entry p) const {
		if(p.pre == pre){
			if(suf == p.suf)
				return id < p.id;

			return suf < p.suf;
		}
		return pre < p.pre;
	}

	bool operator== (entry p) const {
		return pre == p.pre && suf == p.suf;
	}
};

const int ms = 2*100011, ml = 31;
entry L[ms];
int P[ml][ms];
int step, pot;
string A, str;
vector<ii> vet;


void init(){
	int n = A.size();

	fr(i, 0, n){
		P[0][i] = A[i] - 'a';
	}


	for(step = 1, pot = 1; (pot >> 1) < n; ++step, pot <<= 1){
		fr(i, 0, n){
			int s = i + pot >= n ? -1 : P[step-1][i+pot];
			L[i] = entry(P[step-1][i], s, i);
		}
		sort(L, L + n);
		fr(i, 0, n){
			P[step][L[i].id] = (i && L[i-1] == L[i]) ? P[step][L[i-1].id] : i;
		}
	}
}

int comp(int k){
	int i, j;
	for(i = 0, j = vet[k].second; i < str.size() && j < A.size(); ++i, ++j){
		// dbg(A[j] _ str[i])
		if(A[j] < str[i])
			return -1;
		else if(A[j] > str[i])
			return 1;

	}
	if(i < str.size())
		return -1;
	return 0;
}

int lower_bd(){
	int lo = 0, hi = A.size();
	while(hi - lo > 1){
		int m = (lo + hi)/2,c = comp(m);
		if(c == 1)
			hi = m - 1;
		else if(c == -1)
			lo = m + 1;
		else
			hi = m;
	}

	if(comp(lo) == 0)
		return lo;
	return hi;
}

int upper_bd(){
	int lo = 0, hi = A.size();
	while(hi - lo > 1){
		int m = (lo + hi)/2, c = comp(m);
		if(c == 1)
			hi = m;
		else if(c == -1)
			lo = m + 1;
		else
			lo = m + 1;
		// dbg(m _ c)
	}

	if(comp(lo) == 1)
		return lo;
	return hi;
}

int main(){
  	freopen("seti.out", "w", stdout);
  	freopen("seti.in", "r", stdin);
	// ios::sync_with_stdio(0);
	int n;
	cin >> n;
	A = "";
	while(n--){
		cin >> str;
		A += str;
	}

	init();
	dbg(step)
	fr(i, 0, A.size()){
		vet.push_back(ii(P[step-1][i], i));
		dbg(P[step-1][i] _ i)
	}

	sort(vet.begin(), vet.end());
	int m;
	cin >> m;
	while(m--){
		cin >> str;
		cout << upper_bd() - lower_bd() << endl;
	}
	return 0;
}

