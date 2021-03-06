#include <bits/stdc++.h>
using namespace std;

struct Node {
	bool IsWord;
	Node *Next[26];
	Node() {
		IsWord = false;
		for (int i = 0; i < 26; i++) {
			Next[i] = nullptr;
		}
	}
};

struct Trie {
	Node* Root;
	Trie() {
		Root = new Node();
	}

	void addWord(string &s) {
		Node* current = Root;
		for (int i = 0; i < (int)s.size(); i++) {
			int id = s[i] - 'a';
			if (current -> Next[id] == nullptr) {
				current -> Next[id] = new Node();
			}
			current = current -> Next[id];
		}
		current -> IsWord = true;
	}

	void deleteWord(string &word) {
		Node* current = Root;
		for (int i = 0; i < (int)s.size(); i++) {
			int id = s[i] - 'a';
			if (current -> Next[id] == nullptr) {
				return;
			}
			current = current -> Next[id];
		}
		current -> IsWord = false;
	}

	bool isFound(string &s) {
		Node* current = Root;
		for (int i = 0; i < (int)s.size(); i++) {
			int id = s[i] - 'a';
			if (current -> Next[id] == nullptr) {
				return false;
			}
			current = current -> Next[id];
		}
		return current -> IsWord;
	}
};

int main() {
	Trie* trie = new Trie();

	vector <string> words = {"sakib", "nova", "alamin", "jack", "lol", "okay"};
	for (auto &word: words) {
		trie -> addWord(word);
	}

	vector <string> findWords = {"sakib", "nov", "min", "nova", "who", "saki"};
	for (auto &word: findWords) {
		cout << word << ", " << (trie -> isFound(word)? "found" : "not found") << "\n";
	}
	return 0;
}
