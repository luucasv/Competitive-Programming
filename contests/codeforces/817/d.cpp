#include <bits/stdc++.h>
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 
#define fr(a, b, c) for(int (a) = (b), __ = c; a < __; ++a)
#define X first 
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int > ii;
const int ms = int(1e6) + 10;
const ll inf = ll(1e7);
int v[ms];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fr(i, 0, n)
		cin >> v[i];
	stack<int> st;
	L[0] = 0;
	st.push(0);
	fr(i, 1, n){
		while(st.top() != 0 && v[st.top()] <= v[i])
			st.pop();
		L[i] = st.top();
		st.push(i);
	}
	while(!st.empty())
		st.pop();
	R[n-1] = n-1;
	return 0;
}