/*
	Solving icpc archive 2755
	O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

struct entry{
	int pre, suf, id;

	entry(){}
	entry(int a, int b, int id): pre(a), suf(b), id(id){}
	bool operator< (entry p) const {
		if(p.pre == pre)
			return suf < p.suf;
		return pre < p.pre;
	}

	bool operator== (entry p) const {
		return pre == p.pre && suf == p.suf;
	}
};

const int ms = 2*250111, ml = 31;
entry L[ms];
int P[ml][ms];
int step, pot;
string A;
vector<int> ans[ms];

void init(){
	int n = A.size();

	fr(i, 0, n){
		P[0][i] = A[i];
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

int lcp(int x, int y){
	int ret = 0, k;
	for(k = step-1; k > -1 && x < A.size() && y < A.size(); --k){
		if(P[k][x] == P[k][y]){
			x += 1 << k;
			y += 1 << k;
			ret += 1 << k;
		}
	}
	return ret;
}

int check[4];

int main(){
	ios::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	A = a + char(2) + b;
	int i = 0, j = 0, ans = 0, n = A.size();

	init();
	vector<ii> vet;
	fr(k, 0, n){
		vet.push_back(ii(P[step-1][k], k));
	}
	sort(vet.begin(), vet.end());

	dbg(A)

	while(i < n){
		bool ok = 1;
		while(!check[0] || !check[1]){
			if(j == n)
				ok = 0;
			
			check[vet[j++].second <= a.size()]++;
		}

		if(!ok)
			break;

		for(int o = vet[i].second; o < n && A[o] != 2; ++o)
			cout << A[o];
		cout << endl;


		for(int o = vet[j].second; o < n && A[o] != 2; ++o)
			cout << A[o];
		cout << endl;

		dbg(endl)

		ans = max(ans, lcp(vet[i].second, vet[j].second));
		check[vet[i++].second <= a.size()]--;
	}


	cout << ans << endl;
	return 0;
}