#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>> "  << x << endl;
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
entry L[ms], temp[ms];
int P[ml][ms];
int step, pot;
int cnt[ms];

string A;
int n;
ii vet[ms];

int main(){
	ios::sync_with_stdio(0);
	string suf, pref, mid;
	cin >> suf;
	pref = mid = suf;
	reverse(suf.begin(), suf.end());

	mid.pop_front();
	mid.pop_back();
	A = pref + char(2) + suf + char(3) + mid;




	return 0;
}