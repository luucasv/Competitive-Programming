#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
const int ms = 32004 + 20;
int bit[ms], cnt[ms];

void add(int p, int v) {
  while (p < ms) {
    bit[p] += v;
    p += p & -p;
  }
}

int sum(int p) {
  int ans = 0;
  while (p > 0) {
    ans += bit[p];
    p -= p & -p;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  fr(i, 0, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    ++x;
    int lvl = sum(x);
    cnt[lvl]++;
    add(x, 1);
  }
  fr(i, 0, n) {
    printf("%d\n", cnt[i]);
  }
	return 0;
}