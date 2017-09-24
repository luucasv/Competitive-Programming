#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int at = 1;
	stack<int> pilha;
	int ans = 0;
	fr(i, 0, 2*n){
		string s;
		cin >> s;
		if(s == "add"){
			int x;
			cin >> x;
			pilha.push(x);
		}
		else{
			if(!(pilha.empty() || pilha.top() == at)){
				while(!pilha.empty())
					pilha.pop();
				++ans;
			}
			++at;
		}
	}
	cout << ans << endl;
	return 0;
}