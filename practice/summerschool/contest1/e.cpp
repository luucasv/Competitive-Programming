#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;

typedef long long int ll;
typedef pair<int, int> li;

int gen(int p, int k){
	if(k == 0){
		return 0;
	}
	if(k == 1){
		return p;
	}
	int at = p >> 1, c = gen(at, k-1);
	
	if(at&1){
		if(at << 1 == p)
			return (1 << k) - 1 - c;
		else
			return c;
	}
	else{
		if(at << 1 != p)
			return (1 << k) - 1 - c;
		else
			return c;
	}
}

int main(){
	ios::sync_with_stdio(0);
	int k, m, l, r, a, b, c, h = 0;
	
	scanf("%d %d %d %d %d %d %d", &k, &m, &l, &r, &a, &b, &c);
	int n = (1 << k);
	while(m--){
		int ans = 0;
		if(l&1){
			int sz = (r - l) / 2;
			ans = (n - 1)*sz;

			ans += gen(l, k);
			if(!(r&1)){
				ans += gen(r, k);
			}

		}
		else{
			ans = 0;
			int sz = (r - l + 1) / 2;
			if(sz&1){
				ans = n - 1;
			}
			if(!(r&1)){
				ans ^= gen(r, k);
			}

		}

		h = ((h ^ l ^ r ^ ans) + c) % 1000000007;
		l = ((l ^ a ^ h)  % (n + 1)) % n;
		r = ((r ^ b ^ h) % (n - l)) + l;
	}

	printf("%d\n", h);
}