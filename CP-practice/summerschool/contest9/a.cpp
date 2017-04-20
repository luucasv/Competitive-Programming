#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; ++a)
#define dbg(x) if(1) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;

istringstream strm;

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

struct refe{
	vector< vector<string> > authors;
	string title;
	string publisher;
	int type;
	int year, volume, number, from, to;

	refe():year(0), volume(0), number(0), from(0), to(0), type(0){
		title = "";
		publisher = "";
		authors.clear();
	}

	void init(){
		title = "";
		publisher = "";
		authors.clear();
		year = volume = number = from = to = type = 0;	
	}

	bool operator<(refe a) const {
		if(authors != a.authors)
			return authors < a.authors;
		if(title != a.title)
			return title < a.title;
		return volume < a.volume;
	}

	void show(){
		fr(j, 0, authors.size()){
			if(j)
				cout << ", ";
			cout << authors[j][0];
			fr(k, 1, authors[j].size()){
				cout << " " << authors[j][k][0] << ".";
			}
		}
		
		cout << " " << title;
		if(type){
			cout << " // " << publisher;
			if(volume)
				cout << ", " << volume;
			if(number)
				cout << " (" << number << ")";

			cout << " -- " << year;
			if(from){
				cout << " -- ";
				if(to)
					cout << "pp. " << from << "--" << to;
				else
					cout << "p. " << from;
			}
		}
		else{
			if(volume)
				cout << ", Vol. " << volume;
			cout << " -- " << publisher << ", " << year;
		}
		cout << endl;
	}

	void add_field(string name, string value){
		if(name == "author"){
			vector<string> names;
			istringstream mine;
			mine.str(value);
			string word;

			while(mine >> word){
				if(word == "and"){
					word = names[int(names.size()) - 1];
					for(int i = int(names.size()) - 1; i > 0; --i){
						names[i] = names[i-1];
					}
					names[0] = word;
					authors.push_back(names);
					names.clear();
				}
				else{
					names.push_back(word);
				}
			}
			word = names[int(names.size()) - 1];
			for(int i = int(names.size()) - 1; i > 0; --i){
				names[i] = names[i-1];
			}
			names[0] = word;

			authors.push_back(names);
			sort(authors.begin(), authors.end());
		}
		else if(name == "title"){
			title = value;
		}
		else if(name == "journal" || name == "publisher"){
			publisher = value;
		}
		else if(name == "year"){
			year = stoi(value);
		}
		else if(name == "volume"){
			volume = stoi(value);
		}
		else if(name == "number"){
			number = stoi(value);
		}
		else if(name == "pages"){
			istringstream mine;
			mine.str(value);
			int i = 0;
			while(i < value.size() && value[i] != '-') ++i;
			if(i < value.size()){
				mine >> from;
				mine.ignore(2);
				mine >> to;
			}
			else{
				mine >> from;
				to = 0;
			}
		}
	}
};

int main(){
	#ifdef ONLINE_JUDGE
		freopen("bibtex.in", "r", stdin);
		freopen("bibtex.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	vector<refe> vet;
	string aux, str = "";
	while(cin >> aux){
		if(aux[0] != '}')
			str += ' ';
		str += aux;
	}

	trim(str);
	// dbg(str)
	strm.str(str);

	while(strm >> aux){
		assert(aux[0] == '@');

		assert(aux == "@article" || aux == "@book");
		refe at;
		at.init();
		at.type = int(aux == "@article");
		strm >> aux;
		// assert(aux[0] == '{');
		string a, value;
		do{
			strm >> aux;
			strm >> a;
			strm >> value;
			while(value[int(value.size()) - 1] != '}' && value[int(value.size()) - 1] != ','){
				strm >> a;
				value += " " + a;
			}
			at.add_field(aux, value.substr(1, int(value.size()) - 3));
		}while(value[int(value.size()) - 1] == ',');
		vet.push_back(at);
	}

	sort(vet.begin(), vet.end());

	fr(i, 0, vet.size()){
		cout << "[" << i+1 << "] ";
		vet[i].show();
	}
}