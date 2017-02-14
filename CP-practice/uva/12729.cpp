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
		int n, m;
		cin >> n >> m;
		int c = m / 2, l = n / 2;
		int quant = c * l;
		int ana, bob;
		ana = bob = (quant / 2)*4;
		if(quant&1)
			ana += 4;
		bob += n*m - quant*4;
		cout << "Case #" << cas++ << ": ";
		if(ana > bob)
			cout << "Ana\n";
		else if(bob > ana)
			cout << "Bob\n";
		else
			cout << "Draw\n";
	}
	return 0;
}