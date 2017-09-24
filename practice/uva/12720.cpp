#include <bits/stdc++.h>
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 
using namespace std;
typedef long long ll;
const ll mod = ll(1e9) + 7;

int main(){
    ios::sync_with_stdio(0);
	int t, cas = 1;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll ans = 0;
		int n = s.size();
		int i = (n-1)/2, j = n/2;
		if(i == j){
			ans = s[i] - '0';
			++j;
			--i;
		}
		while(i >= 0 || j < n){
			int cnt = i+1 + n - j;
			if(i == -1){
				ans = (2*ans + s[j++] - '0')%mod;
			}
			else if (j == n){
				ans = (2*ans + s[i--] - '0')%mod;
			}
			else if(cnt&1){
				if(cnt/2 == i)
					ans = (2*ans + s[i--] - '0')%mod;
				else
					ans = (2*ans + s[j++] - '0')%mod;
			}
			else{
				if(s[i] > s[j])
					ans = (2*ans + s[i--] - '0')%mod;
				else
					ans = (2*ans + s[j++] - '0')%mod;
			}
		}
		
		cout << "Case #" << cas++ << ": " << ans << endl;
	}
	return 0;
}