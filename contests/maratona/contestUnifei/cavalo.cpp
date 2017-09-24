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

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int INF = 12894;

int dist[8][8];
string board[20];

int main() {
  while(std::cin >> board[0])
  {
    memset(dist, 0x3f, sizeof dist);
    queue<ii> q;
    for(int i = 0; i < 8; i++)
    {
      if (i) {
        cin >> board[i];
      }
      for(int j = 0; j < 8; j++)
      {
        if(board[i][j] == 'I')
        {
          q.push(ii(i, j));
          dist[i][j] = 0;
        }
        else
        {
          dist[i][j] = INF;
        }
      }
    }
    while(!q.empty())
    {
      ii cur = q.front();
      q.pop();
      for(int i = 0; i < 8; i++)
      {
        ii to = ii(cur.X + dx[i], cur.Y + dy[i]);
        if(to.X < 0 || to.X >= 8 || to.Y < 0 || to.Y >= 8 || board[to.X][to.Y] == 'X')
          continue;
        if(dist[cur.X][cur.Y] + 1 < dist[to.X][to.Y])
        {
          dist[to.X][to.Y] = dist[cur.X][cur.Y] + 1;
          q.push(to);
        }
      }
    }
    int ans = INF;
    for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 8; j++)
      {
        if(board[i][j] == 'F')
          ans = std::min(dist[i][j], ans);
      }
    }
    if(ans >= INF)
      std::cout << "Impossivel ir de I a F\n";
    else
      std::cout << "Numero minimo de movimentos: " << ans << "\n";
  }
}