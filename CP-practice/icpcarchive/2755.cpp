/*
	Solving icpc archive 2755
	O(nlog^2(n))
*/

#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

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

const int ms = 2*100011, ml = 31;
entry L[ms];
int P[ml][ms];
int step, pot;
string A;
vector<int> ans[ms];

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

int lcp(int x, int y){
	int ret = 0;
	for(k = step-1; k > -1 && x < A.size() && y < A.size(); --k){
		if(P[k][x] == P[k][y]){
			x += 1 << k;
			y += 1 << k;
			ret += 1 << k;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n >> A;
		A += A;
		init();
		fr(i, 0, n){
			ans[i].clear();
			int at = i;
			fr(k, 0, ml){
				if(n & (1 << k)){
					ans[i].push_back(P[k][at]);
					at += 1 << k;
				}
			}
			ans[i].push_back(i);
		}

		sort(ans, ans + n);
		cout << ans[0][ans[0].size() - 1] << endl;
	}
	return 0;
}