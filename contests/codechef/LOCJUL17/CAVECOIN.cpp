#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " <<

using namespace std;

typedef long long ll;
typedef complex<double> Complex;

const int mn = 11111, mv = (1 << 20);
const double pi = acos(-1.0);

struct bat{
	int a, b;
	bool operator<(bat bt){
		if(b != bt.b)
			return b > bt.b;
		return a < bt.a;
	}

	bool in(bat bt){
		return a <= bt.a && bt.b  <= b;
	}
};

void FFT(Complex P[], int n, int oper){
	for(int i = 1, j = 0; i < n - 1; i++){
		for(int s = n; j ^= s >>= 1, ~j & s;);
		if(i < j){
			swap(P[i], P[j]);
		}
	}
	Complex wn, w;
	for(int d = 0; (1 << d) < n; d++){
		int m = 1 << d, m2 = m << 1;
		double p0 = pi / m * oper;
		wn = Complex(cos(p0), sin(p0));
		for(int i = 0; i < n; i += m2){
			w = 1;
			fr(j, 0, m){
				Complex &P1 = P[i + j + m], &P2 = P[i + j];
				Complex t = w * P1;
				P1 = P2 - t;
				P2 = P2 + t;
				w = w * wn;
			}
		}
	}
	if(oper == -1){
		fr(i, 0, n){
			P[i] /= n;
		}
	}
}

void trans(Complex P[], const string &p, int k){
	fr(i, 0, p.size()){
		P[i] = Complex(p[i] == '0' ? 0 : 1);
	}
	fr(i, p.size(), k){
		P[i] = Complex(0);
	}
	FFT(P, k, 1);
}

Complex A[mv], B[mv], C[mv];

int get(Complex a){
	return round(a.real() + 1e-3);
}

void multiply(string &a, string &b){
	dbg(a _ b)
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int n = a.size(), m = b.size();
	int k = 1;
	while(k < n+m)
		k <<= 1;
	trans(A, a, k);
	trans(B, b, k);
	fr(i, 0, k)
		C[i] = A[i] * B[i];
	FFT(C, k, -1);
	stack<int> pilha;
	ll carry = 0;
	for(int i = 0; i < k || carry; i++){
		ll val = carry;
		if(i < k)
			val += get(C[i]);
		pilha.push(val % 2);
		carry = val / 2;
	}
	while(pilha.size() > 1 && pilha.top() == 0)
		pilha.pop();
	while(!pilha.empty()){
		cout << pilha.top();
		pilha.pop();
	}
	cout << endl;
}

bat v[mn];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		fr(i, 0, n)
			cin >> v[i].a >> v[i].b;
		sort(v, v+n);
		string k, mult(v[0].b + 1, '0');
		cin >> k;
		vector<bat> ans;
		ans.push_back(v[0]);
		fr(oi, 1, m){
			bat aqui = ans.back(), a = ans.back();
			fr(i, 0, n){
				if(a.a-1 <= v[i].b && v[i].b <= a.b){
					if(v[i].a < aqui.a){
						aqui = v[i];
					}
				}
			}
			if(!ans.back().in(aqui)){
				ans.push_back(aqui);
				continue;
			}
			aqui.b = -1;
			fr(i, 0, n){
				if(v[i].b < a.a){
					if(v[i].b > aqui.b){
						aqui = v[i];
					}
				}
			}
			if(aqui.b == -1)
				break;
			ans.push_back(aqui);
		}
		assert(ans.size() <= m);
		// dbg(ans.size() _ ans.back().a _ ans.back().b)
		int at = 0;
		int st = v[0].b + 1, sz = v[0].b;
		while(st--){
			while(at < ans.size() && ans[at].a > st)
				++at;
			if(at == ans.size())
				break;
			if(ans[at].b >= st){
				mult[sz - st] = '1';
			}
			else{
				mult[sz - st] = '0';
			}
		}
		multiply(k, mult);
	}
	return 0;
} 