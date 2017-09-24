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

const int INF = 1e8;
const int ms = 110;

int dp[ms];

int main() {
  int q;
  std::cin >> q;
  while(q--)
  {
    int n;
    std::cin >> n;
    for(int i = 0; i < ms; i++)
      dp[i] = -INF;
    dp[0] = 0;
    while(n--)
    {
      int power, weight;
      std::cin >> power >> weight;
      for(int i = ms - weight - 1; i >= 0; i--)
        dp[i + weight] = std::max(dp[i + weight], dp[i] + power);
    }
    int cap, res;
    std::cin >> cap >> res;
    int ans = -1;
    for(int i = 0; i <= cap; i++)
    {
      if(dp[i] >= res)
      {
        if(dp[i] > ans)
          ans = dp[i];
      }
    }
    if(ans == -1)
      std::cout << "Missao falhou\n";
    else
      std::cout << "A resistencia do castelo " << res << " nao suportou o ataque da missao " << ans << "\n";
  }
}