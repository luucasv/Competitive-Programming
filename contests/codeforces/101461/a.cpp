#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef unsigned long long ull;

const int ms = int(1e6) + 10;
const ull base = 37;

char str[ms];
ull hs[ms];
int mk[ms], ans[ms], step;

ull pot[ms];

ull elev(ull bas,int e,int len){
	ull y=0;
	while(e){
		if(e&1){
			y *= pot[len];
			y += bas;
		}
		bas = bas * pot[len] + bas;
		len <<= 1;
		e >>= 1;
	}
	return y;
}

int main() {
	freopen ("period.in","r+",stdin);
	freopen ("period.out","w+",stdout);
	int n;
	hs[0] = 0;
	pot[0] = 1;
	int cas = 1;
	fr(i, 0, ms-1){
		pot[i+1] = pot[i] * base;
	}
	while(scanf("%d", &n) > 0 && n){
		++step;
		scanf(" %s", str);
		fr(i, 0, n){
			hs[i+1] = hs[i] * base + ull(str[i] - 'a' + 1);
		}
		printf("Test case #%d\n", cas++);
		fr(i, 1, n+1){
			ull at = hs[i];
			for(int j = i + i, sz = 2; j <= n; j += i, ++sz){
				at = at * pot[i] + hs[i];
				// dbg(i _ j _ at)
				if(hs[j] == at){
					if(mk[j] != step){
						mk[j] = step;
						ans[j] = sz;
					}
					ans[j] = max(ans[j], sz);
				}
			}
			if(mk[i] == step){
				printf("%d %d\n", i, ans[i]);
			}
		}
		puts("");
	}
}