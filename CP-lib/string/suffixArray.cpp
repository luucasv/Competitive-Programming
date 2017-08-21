/*
	Solving icpc archive 2755
	O(nlog^2(n))
*/

#include <string>
#include <vector>

struct Entry{
	int prefix, suffix, id;

	Entry(){}
	Entry(int prefix, int suffix, int id): prefix(prefix), suffix(suffix), id(id){}
	bool operator<(Entry p) const {
		if(p.prefix == this->prefix)
			return this->suffix < p.suffix;
		return this->prefix < p.prefix;
	}

	bool operator==(Entry p) const {
		return this->prefix == p.prefix && this->suffix == p.suffix;
	}

	bool operator!=(Entry p) const {
		return !(*this == p);
	}
};

class SuffixArray{
public:
	const int maxSteps;
	std::vector<int> SA; // the suffix array 
	std::vector<std::vector<int>> auxSA; // stores suffix array to every step
	std::string T;
	SuffixArray(std::string T):T(T), maxSteps( myLog2(T.size()) + 1 ){
		auxSA = std::vector<std::vector<int>>(maxSteps, vector<int>(T.size()));
		buildArray();
	}

private:
	std::vector<Entry> countingSort(const std::vector<Entry>& vet){

	}

	void buildAuxVector(std::vector<Entry> &auxVector, const std::vector<int>& lastSA, int blockSize){
		for(int i = 0; i < auxVector.size(); ++i){
			int prefix = lastSA[i],
			suffix = -1;
			if(i + blockSize < lastSA.size())
				suffix = lastSA[i + blockSize];

			auxVector[i] = Entry(prefix, suffix, i);
		}
	}

	void fillSAVector(std::vector<int>& curSA, const std::vector<Entry> &auxVector){
		int rank = 0;
		curSA[auxVector[i].id] = 0;
		for(int i = 1; i < auxVector.size()){
			if(auxVector[i] != auxVector[i-1])
				rank++;
			curSA[auxVector[i].id] = rank;
		}
	}

	void buildArray(){
		std::vector<Entry> auxVector(T.size());

		for(int i = 0; i < T.size(); ++i){
			auxSA[0][i] = T[i];
		}

		for(int step = 1; step < maxSteps; ++step){
			int blockSize = pot2(step - 1);
			buildAuxVector(auxVector, auxSA[step-1], blockSize);
			auxVector = countingSort(auxVector);
			fillSAVector(auxSA[step], auxVector);
		}

		SA = std::vector<int>(T.size());
		for(int i = 0; i < T.size(); ++i){
			SA[auxSA[maxSteps - 1][i]] = i;
		}
	}
};



const int ms = 2*100011, ml = 31;
entry L[ms];
int P[ml][ms];
int step, pot;
string A;
vector<int> ans[ms];

void init(){
	int n = A.size();

	fr(i, 0, n){
		P[0][i] = A[i] - 'a';
	}


	for(step = 1, pot = 1; (pot >> 1) < n; ++step, pot <<= 1){
		fr(i, 0, n){
			int s = i + pot >= n ? -1 : P[step-1][i+pot];
			L[i] = entry(P[step-1][i], s, i);
		}
		sort(L, L + n);
		fr(i, 0, n){
			P[step][L[i].id] = (i && L[i-1] == L[i]) ? P[step][L[i-1].id] : i;
		}
	}
}

int lcp(int x, int y){
	int ret = 0;
	for(k = step-1; k > -1 && x < A.size() && y < A.size(); --k){
		if(P[k][x] == P[k][y]){
			x += 1 << k;
			y += 1 << k;
			ret += 1 << k;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n >> A;
		A += A;
		init();
		fr(i, 0, n){
			ans[i].clear();
			int at = i;
			fr(k, 0, ml){
				if(n & (1 << k)){
					ans[i].push_back(P[k][at]);
					at += 1 << k;
				}
			}
			ans[i].push_back(i);
		}

		sort(ans, ans + n);
		cout << ans[0][ans[0].size() - 1] << endl;
	}
	return 0;
}