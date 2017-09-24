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
		double n, m;
		int a, b;
		cin >> n >> m >> a >> b;
		double sum = a*n, total = m*(a + b), need = (total - sum) / b;
		cout << "Case #" << cas++ << ": ";
		if(need < 0 || need > 10)
			cout << "Impossible\n";
		else
		 	cout << setprecision(2) << fixed << need << endl;
	}
	return 0;
}