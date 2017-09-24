#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define pb push_back
using namespace std;

typedef unsigned long long ull;
string add(string a,string b){
	int la=a.size(),lb=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string s="";
	int cc=0;
	fr(i,0,max(la,lb)){
		int aa=0,bb=0;
		if(i<la){
			aa=a[i]-'0';
		}
		if(i<lb){
			bb=b[i]-'0';
		}
		int t=aa+bb+cc;
		if(t>10){
			cc=1;
		}else cc=0;
		t%=10;
		s=s+char('0'+t);
	}
	if(cc)s=s+"1";
	reverse(s.begin(),s.end());
	return s;
}
string div2(string s){
	string r="";
	if(s[0]>'1'){
		r=""+char((s[0]-'0')/2+'0');
	}
	int cc=0;
	fr(i,1,s.size()){
		int x=s[i]-'0';
		r=r+char(x/2+cc+'0');
		if(x&1)cc=5;
		else cc=0;
	}
	if(r.size()==0)return "0";
	return r;
}

int aux[1000];

string mul(string a, string b){
	string ans(a.size() + b.size());
	memset(aux, 0, (a.size() + b.size()) * sizeof(int));
	fr(i, 0, a.size()){
		fr(j, 0, b.size()){
			aux[i + j] += (a[i] - '0') * (b[i] - '0')
		}
	}
	int carry = 0;
	fr(i, 0, a.size() + b.size()){
		int val = aux + carry;
		ans[i] = val%10 + '0';
		carry = val / 10;
	}
	if(carry > 0)
		ans += to_string(carry);
}

bool cmp(string a, string b){
	if(a.size() != b.size()){
		return a.size() < b.size()
	}
	return a < b;
}

int main() {
	// freopen ("period.in","r+",stdin);
	// freopen ("period.out","w+",stdout);
	string x, z(10, '0');
	while(cin >> x){
		x += z;
		string lo = "1" + z, hi = x;
		while(cmp(lo, hi)){
			string m = div2(add(lo, hi)), c = mul(m, mul(m, m));
			if(cmp(c, x) || c == x)
				lo = m;
			else
				hi = m;
		}
		int check = 0;
		string ans = "";
		fr(i, 0, hi.size()){
              check += lo[t] - '0';
              if(lo.size() - t == 10)
                  ans += '.'
              ans += lo[t]
              t += 1
        }
	}
}