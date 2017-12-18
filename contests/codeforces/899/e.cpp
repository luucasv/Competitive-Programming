#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int ms = 2e5 + 20;

struct comp {
  bool operator()(const ii a, const ii b) const {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  }
};

int a[ms], le[ms], ri[ms];
int cnt[ms];

int main() {
  set<ii, comp> st;
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }

  int i = 1;
  int ls = 0;
  while (i <= n) {
    int fs = i;
    while (i <= n && a[i] == a[fs]) {
      i++;
    }
    
    le[fs] = ls;
    ri[fs] = i;
    ls = fs;
    cnt[fs] = i - fs;
    st.insert(ii(cnt[fs], fs));
  }

  ri[0] = 1;
  le[n+1] = ls;

  a[0] = -1;
  a[n+1] = -2;
  
  int ans = 0;
  
  while (!st.empty()) {
    ans++;
    ii tp = *st.begin();
    st.erase(st.begin());
    int ant = le[tp.second], dps = ri[tp.second];
    assert(ri[ant] == tp.second && le[dps] == tp.second);
    ri[ant] = dps;
    le[dps] = ant;
    if (a[ant] == a[dps]) {
      st.erase(ii(cnt[dps], dps));
      st.erase(ii(cnt[ant], ant));
      cnt[ant] += cnt[dps];
      ri[ant] = ri[dps];
      le[ri[dps]] = ant;
      st.insert(ii(cnt[ant], ant));
    }
  }
  cout << ans << endl;
}