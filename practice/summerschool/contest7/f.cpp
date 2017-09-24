
#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < (b); i++)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define X first
#define Y second
#define pb push_back
#define sc(a) scanf("%d", &a)
#define mp make_pair

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> i4;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;


const int inf = 0x3f3f3f3f;
const ll mod = ll(1e9) + 9;

const int ms = 1111, mk = 11111;

int FM[ms][mk];
ll MM[ms][mk];
int A[ms][2], pi[ms];


int n;

int F(int i, int j){
	if(j < 0)
		return 0;
	if(j == 0)
		return i;
	if(j <= 2)
		return A[i][j-1];
	
	if(FM[i][j] !=  -1)
		return FM[i][j];
	
	int x = F(i, j-2);
	return FM[i][j] = F(x, j-1);
}

ll M(int i, int j){
	if(j == 0)
		return 0;
	
	if(j <= 2)
		return ll(A[i][j-1] == n);
	
	if(MM[i][j] != -1)
		return MM[i][j];
	
	int x = F(i, j- 2);
	return MM[i][j] = (M(i, j-2) +  M(x, j-1))%mod;
}


int main(){
	ios::sync_with_stdio(0);
	string a;
	cin >> a;
	fr(i, 0, a.size())
		a[i] -= 'a';
	
	fr(i, 0, 2)
		A[0][i] = (a[0] == i);
	
	n = a.size();

	a += "#";
	
	fr(i, 2, a.size()){
		pi[i] = pi[i-1];
		while(pi[i] > 0 && a[pi[i]] != a[i-1])
			pi[i] = pi[pi[i]];
		if(a[pi[i]] == a[i-1])
			pi[i]++;
	}
	
	
	fr(i, 1, a.size()){
		fr(c, 0, 2){
			if(c == a[i])
				A[i][c] = i+1;
			else
				A[i][c] = A[pi[i]][c];
		}
	}
	int k;
	cin >> k;
	memset(MM, -1, sizeof MM);
	memset(FM, -1, sizeof FM);
	
	/*fr(i, 0, n+1)
		fr(j, 0, k+1)
			dbg("m" _ i _ j _ M(i, j))
	
	fr(i, 0, n+1)
		fr(j, 0, k+1)
			dbg("f" _ i _ j _ F(i, j))/**/
	
	cout << M(0, k) << endl;
	return 0;
}