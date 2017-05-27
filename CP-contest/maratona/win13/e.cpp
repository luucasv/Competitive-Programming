#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

#define X first
#define Y second

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = 111, mt = 25111;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

const int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0}; 

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		vector<string> board;
		string line;
		while(getline(cin, line) && line != ""){
			board.push_back(line);
		}
		
		vector<ii> pegs, aux;
		
		fr(i, 0, board.size()){
			fr(j, 0, board[i].size()){
				if(board[i][j] == 'o'){
					pegs.push_back(ii(i, j));
				}
			}
		}
		int q = pegs.size();
		map<vector<ii>, int> mp;
		queue<vector<ii> >fila;
		
		sort(pegs.begin(), pegs.end());
		fila.push(pegs);
		
		int a = pegs.size();
		while(!fila.empty()){
			vector<ii> st = fila.front();
			fila.pop();
			a = min(a, (int) st.size());
			dbg(a)
			fr(i, 0, st.size()){
				fr(k, 0, 4){
					aux = st;
					int x1 = st[i].X + di[k], y1 = st[i].Y + dj[k], x2 = st[i].X + 2*di[k], y2 = st[i].Y + 2*dj[k];
					if(!(x2 >= 0 && x2 < board.size() && y2 >= 0 && y2 < board[0].size())){
						continue;
					}
					if(board[x1][y1] == '#' || board[x2][y2] == '#')
						continue;
					if(!binary_search(st.begin(), st.end(), ii(x1, y1)))
						continue;
						
					if(binary_search(st.begin(), st.end(), ii(x2, y2)))
						continue;
					
					auto it = lower_bound(aux.begin(), aux.end(), ii(x1, y1));
					aux.erase(it);
					sort(aux.begin(), aux.end());
					if(mp[aux] == 0){
						mp[aux] = mp[st] + 1;
						fila.push(aux);
					}
				}
			}
		}
		
		cout << a - 1 << " " << q - a + 1  << endl;
	}
	return 0;
}







