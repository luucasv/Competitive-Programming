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
	fr(i, 0, n)
		cin >> a[i];
	fr(i, 0, n)
		cin >> b[i];
	int front = 0, back = 0;
	dp[0] = Sol(0, b[0]);
	dequee[back++] = dp[0];
	fr(i, 1, n) {
		while (front + 1 < back &&
					 dequee[front].calc(a[i]) >= dequee[front+1].calc(a[i])) {
			++front;
		}
		dp[i] = Sol(dequee[front].calc(a[i]), b[i]);
		while (back - front >= 2 && dequee[back-1].over(dequee[back-2]) >= dp[i].over(dequee[back-2])) {
			--back;
		}
		dequee[back++] = dp[i];
	}
	cout << dp[n-1].sum << endl;
	return 0;
}