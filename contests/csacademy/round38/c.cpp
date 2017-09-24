#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

int a[111111];

bool check(int n, int k){
	fr(i, 0, n-1){
		if(abs(a[i] - a[i+1]) > k){
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	fr(i, 0, n)
		cin >> a[i];
	set<int> st;
	fr(i, 0, n-1){
		if(abs(a[i] - a[i+1]) > k){
			st.insert(i);
			st.insert(i+1);
		}
	}
	if(st.size() == 0){
		cout << "0\n";
		return 0;
	}
	if(st.size() > 10){
		cout << "-1\n";
		return 0;
	}
	for(auto i : st){
		fr(j, 0, n){
			if(j == i)
				continue;
			swap(a[i], a[j]);
			bool ok = 1;
			if((i+1 < n && abs(a[i] - a[i+1]) > k) || (i > 0 && abs(a[i-1] - a[i]) > k)){
				ok = 0;
			}
			if((j+1 < n && abs(a[j] - a[j+1]) > k) || (j > 0 && abs(a[j-1] - a[j]) > k)){
				ok = 0;
			}
			for(auto k : st){
				if(k != i-1 && k != i+1 && k != i && k != j+1 && k != j-1 && k != j)
					ok = 0;
			}
			if(ok){
				cout << min(i, j) + 1 << " " << max(i,j) + 1 << endl;
				return 0;
			}
			swap(a[i], a[j]);
		}
	}
	cout << "-1\n";
	return 0;
}