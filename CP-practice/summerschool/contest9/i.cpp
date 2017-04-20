#include<bits/stdc++.h>
#define fr(i, a, b) for(int i = (a); i < (b); ++i)
#define fre(i, u) for(int i = adj[u]; i != -1; i = ant[i])
#define X first
#define Y second
#define pb push_back
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define scs(a) scanf("%s", a)
#define mp make_pair

#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long int ll;
const short int ms = 101, m2 = 10, inf = 200;

short int arr[ms],n;
short int memo[ms][m2][m2][m2][2];
short int way[ms][m2][m2][m2][2];

short int dp(int i, int one, int two, int three, int cnt){
	if(one >= m2 || two >= m2 || three >= m2 || one < 0 || two < 0 || three < 0)
		return inf;

	if(i == n && (one || two || three))
		return inf;

	if(i == n){
		return 0;
	}
	

	short int &ans = memo[i][one][two][three][cnt], &w = way[i][one][two][three][cnt], aux;
	if(ans != -1)
		return ans;

	short int cost = 0;
	if(!cnt)
		cost = ((arr[i] - one - 2*two - 3*three)%4 + 4)%4;

	one += (cost == 1);
	two += (cost == 2);
	three += (cost == 3);


	ans = dp(i+1, one, two, three, 0);
	w = 0;

	aux = dp(i, one-1, two, three, 1);
	if(aux < ans){
		ans = aux;
		w = 1;
	}

	aux = dp(i, one, two-1, three, 1);
	if(aux < ans){
		ans = aux;
		w = 2;
	}

	aux = dp(i, one, two, three-1, 1);
	if(aux < ans){
		ans = aux;
		w = 3;
	}

	ans += (cost > 0);
	return ans;
}

stack<short int> pilha[4];

void get_ans(int i, int one, int two, int three, int cnt){
	if(i == n){
		return;
	}
	short int cost = 0, w = way[i][one][two][three][cnt];
	if(!cnt)
		cost = ((arr[i] - one - 2*two - 3*three)%4 + 4)%4;

	if(cost){
		pilha[cost].push(i+1);
		if(cost == 1)
			one++;
		if(cost == 2)
			two++;
		if(cost == 3)
			three++;
	}


	if(w){
		cout << pilha[w].top() << " " << i+1 << " " << w << endl;
		pilha[w].pop();
		if(w == 1)
			one--;
		if(w == 2)
			two--;
		if(w == 3)
			three--;
		get_ans(i, one, two, three, 1);
	}
	else{
		get_ans(i+1, one, two, three, 0);
	}
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	#endif
	memset(memo, -1, sizeof memo);
	string s,t;
	cin >> s >> t;
	n = s.size();
	map<char,int> mapa;
	mapa['A']=0;
	mapa['C']=1;
	mapa['G']=2;
	mapa['T']=3;
	fr(i,0,n){
		arr[i]=(mapa[t[i]] - mapa[s[i]] + 4)%4;
	}
	cout << dp(0, 0, 0, 0, 0) << endl;
	get_ans(0, 0, 0, 0, 0);
	return 0;
}