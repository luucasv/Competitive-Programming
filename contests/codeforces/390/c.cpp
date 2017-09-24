#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef pair<int, int> ii;

const int ms = 111;

string user[ms], chat[ms];
bitset<ms> bset[ms];
int sender[ms];

bool good(char a){
	return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'));
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		map<string, int> mp;

		int n;
		cin >> n;
		
		fr(i, 1, n+1){
			cin >> user[i];
			mp[user[i]] = i;
		}

		int m;
		cin >> m;
		fr(i, 0, m)
			bset[i].reset();

		cin.ignore();
		fr(i, 0, m){
			getline(cin, chat[i]);

			if(chat[i][0] != '?'){
				int at = 0;
				string str = "";
				while(at < chat[i].size() && good(chat[i][at])) str += chat[i][at++];
				sender[i] = mp[str];

				if(i){
					bset[i-1].set(sender[i]);
				}
				bset[i+1].set(sender[i]);
				continue;
			}

			sender[i] = -1;

			int at = 2;
			while(at < chat[i].size()){
				while(at < chat[i].size() && !good(chat[i][at])) ++at;
				string str = "";
				while(at < chat[i].size() && good(chat[i][at])) str += chat[i][at++];
				if(str.size() && mp.count(str)){
					bset[i].set(mp[str]);
				}
			}
		}

		set<ii> st;

		fr(i, 0, m){
			if(sender[i] == -1){
				st.insert(ii(n - bset[i].count(), i));
			}
		}

		bool ok = 1;

		while(!st.empty()){
			ii fs = *st.begin();
			st.erase(st.begin());

			if(fs.first == 0){
				ok = 0;
				break;
			}

			fr(i, 1, n+1){
				if(bset[fs.second].test(i) == false){
					chat[fs.second] = user[i] + chat[fs.second].substr(1);
					sender[fs.second] = i;
					
					if(fs.second+1 < m && sender[fs.second+1] == -1){
						st.erase(ii(n - bset[fs.second+1].count(), fs.second+1));
						bset[fs.second+1].set(i);
						st.insert(ii(n - bset[fs.second+1].count(), fs.second+1));
					}

					if(fs.second && sender[fs.second-1] == -1){
						st.erase(ii(n - bset[fs.second-1].count(), fs.second-1));
						bset[fs.second-1].set(i);
						st.insert(ii(n - bset[fs.second-1].count(), fs.second-1));
					}

					break;
				}
			}

			if(sender[fs.second] == -1){
				ok = 0;
				break;
			}
		}


		if(!ok){
			cout << "Impossible" << endl;
		}
		else{
			fr(i, 0, m)
				cout << chat[i] << endl;
		}
	}
	return 0 ;
}