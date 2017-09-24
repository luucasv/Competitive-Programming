#include <iostream>
#include <string>
#include <algorithm>

const int SIGMA = 26;

struct Node{
	Node *children[SIGMA];
	bool isEndOfWord;
	int childrenCount; // number of words that has this node in the path
	Node(){
		std::fill(children, children + SIGMA, (Node *) NULL);
		isEndOfWord = false;
		childrenCount = 0;
	}
};

class Trie{
public:
	Node *root;
	Trie(){
		root = new Node;
	}

	~Trie(){
		freeChildren(root);
	}

	void insert(std::string str){
		Node *cur = root;
		root->childrenCount++;
		for(char ch : str){
			int id = getID(ch);
			if(cur->children[id] == NULL)
				cur->children[id] = new Node;
			cur = cur->children[id];
			cur->childrenCount++;
		}
		cur->isEndOfWord = true;
	}

	int countWordsWithPrefix(std::string prefix){
		Node *cur = root;
		for(char ch : prefix){
			int id = getID(ch);
			if(cur->children[id] == NULL)
				return 0;
			cur = cur->children[id];
		}
		return cur->childrenCount;
	}
private:
	int getID(char ch){
		return ch - 'a';
	}

	void freeChildren(Node *cur){
		if(cur == NULL)
			return;
		for(Node* it : cur->children){
			freeChildren(it);
		}
		delete cur;
	}
};

int main(){
	int n;
	std::cin >> n;
	Trie contacts;
	for(int i = 0; i < n; i++){
		std::string op, str;
		std::cin >> op >> str;
		if(op == "add")
			contacts.insert(str);
		else
			std::cout << contacts.countWordsWithPrefix(str) << std::endl;
	}
}