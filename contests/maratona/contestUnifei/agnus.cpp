#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define X first
#define Y second
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

map<string, vector<string> >mp;

void show(string s) {
  cout << s << ":\n";
  for (string a : mp[s]) {
    cout << a << endl;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  fr(i, 0, n) {
    string name, cha;
    getline(cin, name);
    getline(cin, cha);
    mp[cha].push_back(name);
  }
  for (auto &c : mp) {
    sort(c.second.begin(), c.second.end());
  }
  show("Slytherin");
  show("Hufflepuff");
  show("Gryffindor");
  show("Ravenclaw");
}