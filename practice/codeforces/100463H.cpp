#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int mv = int(1e5) + 100, me = mv;
const int A = (1 << 1) + (1 << 3), B = (1 << 2) + (1 << 3);

inline int inter(int a, int b){
	return a & b;
}

inline int sunion(int a, int b){
	return a | b;
}

inline int neg(int a){
	return a ^ ((1 << 4) - 1);
}

inline int go(int ans, int val, int ls){
	if(ls == 0)
		return val;
	else if(ls == 1)
		return inter(ans, val);
	else if(ls == 2)
		return sunion(ans, val);
	else
		assert(0);
}

string str;

int parse(int &i, bool close){
	int ls = 0, ans = 0;
	while(i < str.size() && str[i] != ')'){
		if(str[i] == '*'){
			ls = 1;
			++i;
		}
		else if(str[i] == '+'){
			++i;
			ls = 2;
			ans = go(ans, parse(i, false), ls);
			ls = -1;
		}
		else if(str[i] == '-'){
			assert(str[i+1] == '(');
			i+=2;
			ans = go(ans, neg(parse(i, true)), ls);
			ls = -1;
		}
		else if(str[i] == 'A'){
			i++;
			ans = go(ans, A, ls);
			ls = -1;
		}
		else if(str[i] == 'B'){
			i++;
			ans = go(ans, B, ls);
			ls = -1;
		}
		else if(str[i] == '('){
			i++;
			ans = go(ans, parse(i, true), ls);
			ls = -1;
		}
		else{
			assert(0);
		}
	}
	if(close)
		++i;
	return ans;
}


int main(){
	ios::sync_with_stdio(0);
	int n, m;
	int cas = 1, step = 0;
	while(cin >> n >> m, n+m){
		cout << "Case " << cas++ << ": ";
		vector<int> cnt(n, 0);
		int ca, cb;
		cin >> ca;
		fr(i, 0, ca){
			int v;
			cin >> v;
			cnt[v-1] += 1;
		}
		cin >> cb;
		fr(i, 0, cb){
			int v;
			cin >> v;
			--v;
			cnt[v] += 2;
		}
		cin >> str;	
		int i = 0, c = 0;
		int ans = parse(i, false);
		fr(i, 0, n){
			if((ans >> cnt[i])&1){
				++c;
			}
		}
		cout << c;
		fr(i, 0, n){
			if((ans >> cnt[i])&1){
				cout << " " << i+1;
			}
		}

		cout << endl;
	}	
	return 0;
}
