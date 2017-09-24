/*
  Codeforces: 853B. Jury Meeting
*/
#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int mv = 1e5 + 20, md = 2e6;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int inf_int = 0x3f3f3f3f;

ll befAcc[md], befCnt[md], leAcc[md], leCnt[md];
int minComing[mv], minLeaving[mv];

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<iii> leaving, coming;
  fr(i, 0, m) {
    int d, f, t, c;
    cin >> d >> f >> t >> c;
    if (f == 0) {
      leaving.push_back(iii(d, ii(t, c)));
    } else {
      coming.push_back(iii(d, ii(f, c)));
    }
  }
  sort(coming.begin(), coming.end());
  memset(minComing, 0x3f, sizeof minComing);
  for (iii c : coming) {
    if (minComing[c.Y.X] >= inf_int) {
      befCnt[c.X]++;
      befAcc[c.X] += c.Y.Y;
      minComing[c.Y.X] = c.Y.Y;
    } else if (minComing[c.Y.X] > c.Y.Y) {
      befAcc[c.X] += c.Y.Y - minComing[c.Y.X];
      minComing[c.Y.X] = c.Y.Y;
    }
  }
  fr(i, 1, md) {
    befAcc[i] += befAcc[i-1];
    befCnt[i] += befCnt[i-1];
  }

  sort(leaving.begin(), leaving.end(), greater<iii>());
  memset(minLeaving, 0x3f, sizeof minLeaving);
  for (iii l : leaving) {
    if (minLeaving[l.Y.X] >= inf_int) {
      leCnt[l.X]++;
      leAcc[l.X] += l.Y.Y;
      minLeaving[l.Y.X] = l.Y.Y;
    } else if (minLeaving[l.Y.X] > l.Y.Y) {
      leAcc[l.X] += l.Y.Y - minLeaving[l.Y.X];
      minLeaving[l.Y.X] = l.Y.Y;
    }
  }
  for (int i = md - 2; i > -1; i--) {
    leCnt[i] += leCnt[i+1];
    leAcc[i] += leAcc[i+1];
  }
  ll ans = inf;
  fr(i, 0, md - k - 1) {
    if (befCnt[i] < n){
      continue;
    } else if (leCnt[i+k+1] < n) {
      break;
    }
    ans = min(ans, leAcc[i+k+1] + befAcc[i]);
  }
  if (ans >= inf) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}