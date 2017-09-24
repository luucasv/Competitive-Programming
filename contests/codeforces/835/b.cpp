#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	int k;
	string n;
	cin >> k >> n;
	int sum = 0, ans = 0;
	fr(i, 0, n.size()){
		sum += n[i] - '0';
	}
	sort(n.begin(), n.end());
	fr(i, 0, n.size()){
		if(sum >= k)
			break;
		ans++;
		sum += 9 - (n[i] - '0');
	}
	cout << ans << endl;
	return 0;
}