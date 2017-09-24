#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " <<  x << endl;
#define _ << " , " <<

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
const int ms = 16384 + 20;
const __uint128_t um = 1;
struct node{
	__uint128_t a, b;
	node():a(0), b(0){}
	node(__uint128_t a, __uint128_t b):a(a), b(b){}
	bool operator<(node p){
		if(a != p.a)
			return a < p.a;
		return b < p.b;
	}
	
	node operator<<(int q){
		if(q == 0)
			return *this;
		return node((a << q) | (b >> (128 - q)), b << q);	
	}
	
	node operator|(node q){
		return node(a | q.a, b | q.b);
	}
	
	int operator[](int p){
		if(p > 127){
			p -= 128;
			return int((a >> p)&um);
		}
		else{
			return int((b >> p)&um);
		}
	}
	
	void print(){
		int st = 2*128 - 2;
		while(!(*this)[st] && st > 0)
			--st;
		while(st > -1){
			cout << (*this)[st];
			--st;
		}
		cout << endl;
	}
};
const node inf = node((um << 126) - 1, (um << 126) - 1);
const int tam = 127;
__uint128_t all[ms];
int at = 0;
int mk[tam][30][30][2], step;
node memo[tam][30][30][2];

int maskx, p5, p3, q;

void go(__uint128_t v){
	if(v > __uint128_t(1ULL << 63))
		return;
	all[at++] = v;
	go(v * 26);
	go(v * 26 + 1);
}

inline int kthbit(int k){
	if(k > q)
		return 0;
	return (maskx >> k)&1;
}

node dp(int i, int pop5, int pop3, int no){
	if(i == tam)
		return inf;
	if(pop5 == 0 && pop3 == 0 && !no && i >= q)
		return node();
	if(mk[i][pop5][pop3][no] == step)
		return memo[i][pop5][pop3][no];
	mk[i][pop5][pop3][no] = step;
	int newNo = (no || kthbit(i)) ? 1 : 0, newNoAux = (no && kthbit(i));
	int sum = (i%2 == 0) ? 1:(p3 - 1);
	node ans = dp(i+1, pop5, pop3, newNo) << 1;
	node aux = (dp(i+1, (pop5 + 1)%p5, (pop3 + sum)%p3, newNoAux) << 1) | (node(0, um));
	if(aux < ans){
		ans = aux;
	}
	return memo[i][pop5][pop3][no] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	go(1);
	all[at] = 1;
	fr(i, 0, 14)
		all[at] *= 26;
	++at;
	sort(all, all + at);
	int a, b, c;
	ll x;
	int cas = 1;
	while(cin >> a >> b >> c >> x){
		++step;
		p3 = 1;
		fr(i, 0, b)
			p3 *= 3;
		p5 = 1;
		fr(i, 0, c)
			p5 *= 5;
		__uint128_t xlinha = *upper_bound(all, all + at, x);
		q = 0;
		maskx = 0;
		stack<int> pilha;
		while(xlinha > 0){
			++q;
			pilha.push(int(xlinha%26));
			xlinha /= 26;
		}
		while(!pilha.empty()){
			maskx <<= 1;
			maskx += pilha.top();
			pilha.pop();
		}
		// node(0, maskx).print();
		// dbg(q _ x)
		node ans;
		if(a + b + c){
			int no = 0;
			fr(i, 0, a)
				if(kthbit(i))
					no = 1;
			ans = dp(a, 0, 0, no) << a;
		}
		else{
			ans = node(0, maskx);
		}
		cout << "Case " << cas++ << ": ";
		ans.print();
	}
	return 0;
}