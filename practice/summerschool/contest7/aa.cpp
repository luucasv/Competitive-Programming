
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

int vet[10];
int main(){
	ios::sync_with_stdio(0);
	vet[0] = 1;
	vet[1] = 3;
	for(auto i : vet){
		cout << i << endl;
	}
	return 0;
}