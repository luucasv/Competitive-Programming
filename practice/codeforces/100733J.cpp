#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int ms = 1e3 + 20;

struct event {
  int pos, sprayer, type, dir;
  event(){}
  event(int pos, int sprayer, int type, int dir):pos(pos), sprayer(sprayer), type(type), dir(dir){}
  bool operator< (const event &e) const {
    if (this->pos != e.pos){
      return this->pos < e.pos; 
    }
    return this->type < e.type;
  }
};

int cnt[ms][2];

int main() {
  int n, m;
  cin >> n >> m;
  vector<event> events;
  vector<pair<int, int>> sprayers(n);
  fr(i, 0, n) {
    cin >> sprayers[i].second >> sprayers[i].first;
  }
  fr(i, 0, m) {
    int y, x1, x2;
    cin >> y >> x1 >> x2;
    fr(j, 0, n) {
      events.push_back(event(sprayers[j].first - x1, j, 1, y > sprayers[j].second));
      events.push_back(event(sprayers[j].first - x2, j, 0, y > sprayers[j].second));
    }
  }
  sort(events.begin(), events.end());
  int cur_ans = 0, ans = 0;
  for (auto e : events) {
    if (e.type == 0) {
      cnt[e.sprayer][e.dir]++;
      if (cnt[e.sprayer][1 - e.dir] != 0 && cnt[e.sprayer][e.dir] == 1) {
        cur_ans++;
      }
    } else {
      cnt[e.sprayer][e.dir]--;
      if (cnt[e.sprayer][1 - e.dir] != 0 && cnt[e.sprayer][e.dir] == 0) {
        cur_ans--;
      }
    }
    ans = max(ans, cur_ans);
  }
  cout << ans << endl;
}