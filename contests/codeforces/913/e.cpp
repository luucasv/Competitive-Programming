#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;

const int ms = 2e5 + 20;

string expr[300][3];
int tam[300][3];
int tp[300];

int main() {
  priority_queue<i3, vector<i3>, greater<i3>> pq;
  expr[0b00001111][0] = "x";
  expr[0b00110011][0] = "y";
  expr[0b01010101][0] = "z";
  pq.push(i3(1, ii(0b00001111, 0)));
  pq.push(i3(1, ii(0b00110011, 0)));
  pq.push(i3(1, ii(0b01010101, 0)));
  memset(tam, 0x3f, sizeof tam);
  while (!pq.empty()) {
    int d;
    ii v;
    tie(d, v) = pq.top();
    pq.pop();
    if (d > expr[v.first][v.second].size()) continue;
    for (int i = v.second + 1; i < 3; i++) {
      if (d < tam[v.first][i] ||
          (d == tam[v.first][i] &&  expr[v.first][v.second] < expr[v.first][i])) {
        expr[v.first][i] = expr[v.first][v.second];
        tam[v.first][i] = expr[v.first][i].size();
        pq.push(i3(d, ii(v.first, i)));
      }
    }
    string aux = '(' + expr[v.first][v.second] + ')';
    for (int i = 0; i < v.second; i++) {
      if (d + 2 < tam[v.first][i] ||
          (d + 2 == tam[v.first][i] && aux < expr[v.first][i])) {
        expr[v.first][i] = aux;
        tam[v.first][i] = expr[v.first][i].size();
        pq.push(i3(d + 2, ii(v.first, i)));
      }
    }
    if (v.second == 0) {
      aux = '!' + expr[v.first][v.second];
      int nxt = v.first ^ 255;
      if (d + 1 < tam[nxt][0] ||
          (d + 1 == tam[nxt][0] && aux < expr[nxt][0])) {
        expr[nxt][v.second] = aux;
        tam[nxt][v.second] = aux.size();
        pq.push(i3(aux.size(), ii(nxt, v.second)));
      }
    } else {
      for (int e = 0; e < 256; e++) {
        if (e == v.first) continue;
        if (expr[e][v.second].size() == 0) continue;
        int nxt;
        char ch;
        if (v.second == 1) {
          nxt = e & v.first;
          ch = '&';
        } else {
          nxt = e | v.first;
          ch = '|';
        }
        string ee;
        if (expr[e][v.second] + ch < expr[v.first][v.second] + ch) {
          ee = expr[e][v.second] + ch + expr[v.first][v.second];
        } else {
          ee = expr[v.first][v.second] + ch + expr[e][v.second];
        }
        if (ee.size() < tam[nxt][v.second] ||
            (ee.size() == tam[nxt][v.second] && ee < expr[nxt][v.second])) {
          expr[nxt][v.second] = ee;
          tam[nxt][v.second] = ee.size();
          pq.push(i3(ee.size(), ii(nxt, v.second)));
        }
      }
    }
  }
  for (int i = 0; i < 256; i++) {
    cout << expr[i][2] << '\n';
  }
  // int n;
  // cin >> n;
  // for (int i = 0; i < n; i++) {
  //   string s;
  //   cin >> s;
  //   cout << expr[bitset<8>(s).to_ullong()][2] << '\n';
  // }
}