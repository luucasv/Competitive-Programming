#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 1111;
int rt[1111];

int root(int x){
	if(rt[x] == x)
		return x;
	return rt[x] = root(rt[x]);
}

void conn(int i, int j){
	i = root(i), j = root(j);
	if(i == j)
		return;
	rt[i] = j;
}

int mk[ms];
int ma[ms][ms];
vector<int> primes;
int maxprime(int a, int b){
	int g = __gcd(a, b);
	return mk[g];
}

int main(){
	ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	primes.push_back(1);
	fr(i, 2, ms){
		if(mk[i])
			continue;
		for(int j = i; j < ms; j+=i){
			mk[j] = i;
		}
	}
	fr(i, 1, ms)
		fr(j, i+1, ms)
			ma[i][j] = maxprime(i, j);
	while(t--){
		int a, b, p;
		cin >> a >> b >> p;
		fr(i, a, b+1)
			rt[i] = i;
		fr(i, a, b+1){
			fr(j, i+1, b+1){
				if(ma[i][j] >= p){
					conn(i, j);
				}
			}
		}
		set<int> st;
		fr(i, a, b+1){
			st.insert(root(i));
		}
		cout << "Case #" << cas++ << ": " << st.size() << endl;
	}
	return 0;
}
