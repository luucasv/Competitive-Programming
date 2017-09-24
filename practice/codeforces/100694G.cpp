/*
	Codeforces: 319C. Kalila and Dimna in the Logging Industry
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int ms = 1e5 + 20;
struct Sol {
	ll sum, cost;
	Sol(){}
	Sol(ll sum, ll cost) :sum(sum), cost(cost){}
	ll calc(ll x) {
		return sum + x * cost;
	}

	ll over(Sol s) {
		ll num = sum - s.sum, den = s.cost - cost;
		return (num + den - 1) / den;
	}
};

int a[ms], b[ms];
Sol dp[ms], dequee[ms];

int main(){
	int n;
	cin >> n;
	stack<int> pilha;
	fr(i, 0, 2*n) {
		string cmd;
		int v;
		cin >> cmd >> v;
		if (cmd == "in") {
			if (!pilha.empty()) {
				cout << pilha.top() << ' ' << v << endl;
			}
			pilha.push(v);
		} else {
			assert(v == pilha.top());
			pilha.pop();
		}
	}
	return 0;
}