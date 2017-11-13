#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int ms = 4001, mk = 801;

int mat[ms][ms], dp[mk][ms];

int calc(int i, int j) {
	if (i > j) {
		return 16000000 * 9;
	}
	int ans = mat[j][j];
	if (i) {
		ans -= mat[i-1][j];
		ans -= mat[j][i-1];
		ans += mat[i-1][i-1];
	}
	return ans;
}

void solve(int i, int l, int r, int lo, int hi) {
	if (l > r) {
		return;
	}
	int j = (l + r) / 2;
	int ans = dp[i-1][lo] + calc(lo + 1, j);
  int best = lo;
	fr(k, lo+1, hi+1) {
		int at = dp[i-1][k] + calc(k + 1, j);
		if (at < ans) {
			ans = at;
			best = k;
		}
	}
	dp[i][j] = ans;

	solve(i, l, j-1, lo, best);
	solve(i, j+1, r, best, hi);
}

char str[ms];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	fr(i, 0, n) {
    scanf(" %[^\n]", str);
		fr(j, 0, n) {
      mat[i][j] = str[2 * j] - '0';
			if (i) {
				mat[i][j] += mat[i-1][j];
			}
			if (j) {
				mat[i][j] += mat[i][j-1]; 
			} 
			if (i && j) {
				mat[i][j] -= mat[i-1][j-1];
			}
		}
	}
  fr(i, 0, n) {
    dp[0][i] = calc(0, i);
  }
	fr(i, 1, k) {
		solve(i, 0, n-1, 0, n-1);
	}
	cout << dp[k-1][n-1] / 2 << endl;
}