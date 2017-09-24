#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

using namespace std;

typedef long long int ll;
typedef pair<ll, int> li;
typedef complex<double> Complex;

const double pi = acos(-1.0);

void FFT(Complex P[], int n, int oper){
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int s = n; j ^= s >>= 1, ~j & s;);
			if(i < j) swap(P[i], P[j]);
	}
	Complex wn, w;
	for(int d = 0; (1 << d) < n; ++d){
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

	if(oper == -1) 
		fr(i, 0, n)
			P[i] /= n;
}

const int ms = (1 << 18) + 100; 
string A, B;

Complex AA[5][ms], BB[5][ms], CC[5][5][ms];

int main(){
	ios::sync_with_stdio(0);
	cin >> A >> B;
	A += A;
	reverse(A.begin(), A.end());

	fr(i, 0, A.size()){
		A[i] -= 'A';
		
	}

	fr(i, 0, B.size()){
		B[i] -= 'a';
	}

	int k = 1, sz = A.size() + B.size();
	while(k < sz) k <<= 1;

	fr(i, 0, 5){
		fr(j, 0, A.size())
			AA[i][j] = A[j] == i ? 1 : 0;

		fr(j, 0, B.size())
			BB[i][j] = B[j] == i ? 1 : 0;

		FFT(AA[i], k, 1);
		FFT(BB[i], k, 1);
	}
	fr(i, 0, 5)
		fr(j, 0, 5){
			fr(l, 0, k)
				CC[i][j][l] = AA[i][l] * BB[j][l];
			
			FFT(CC[i][j], k, -1);
		}



	int v[5] = {0, 1, 2, 3, 4};
	int best = 0;  

	do{	
		fr(j, int(B.size()) - 1, 2*int(B.size()) - 1){
			int at = 0;
			fr(i, 0, 5)
				at += int(round(CC[i][v[i]][j].real() + 1e-7));
			best = max(best, at);
		}
	}while(next_permutation(v, v+5));

	cout << B.size() - best << endl;
	return 0;
}