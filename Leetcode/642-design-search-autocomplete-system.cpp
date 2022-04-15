#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *next[27];
  vector <string> words;
  Node() {
    for (int i = 0; i < 27; i++) {
      next[i] = nullptr;
    }
    words.clear();
  }
} *root;

map <string, int> counter;

int getID(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return ch - 'a';
  }
  return 26;
}

void insert(string word) {
  Node *cur = root;
  for (int i = 0; i < word.size(); i++) {
    int id = getID(word[i]);
    if (cur -> next[id] == nullptr) {
      cur -> next[id] = new Node();
    }
    cur = cur -> next[id];
    cur -> words.push_back(word);
  }
  cout << "inserted: " << word << ", counter: " << counter[word] << endl;
}

Node* search(string word) {
  Node *cur = root;
  for (int i = 0; i < word.size(); i++) {
    int id = getID(word[i]);
    if (cur -> next[id] == nullptr) {
      return nullptr;
    }
    cur = cur -> next[id];
  }
  return cur;
}

void autoCompleteSystem(vector <string> &words, vector <int> &times) {
  for (int i = 0; i < words.size(); i++) {
    counter[words[i]] = times[i];
    insert(words[i]);
  }
}

string word;

vector <string> input(char ch) {
  if (ch == '#') {
    if (!counter.count(word)) {
      insert(word);
    }
    counter[word]++;
    word = "";
    return {};
  }

  word += ch;
  cout << "input: " << ch << ", word: " << word << "\n";

  Node *temp = search(word);
  if (temp == nullptr) {
    return {};
  }
  vector <string> res;
  for (auto w: temp -> words) {
    res.push_back(w);
  }

  auto comp = [&](string &a, string &b) -> bool {
    return counter[a] == counter[b]? a < b: counter[a] > counter[b];
  };
  sort(res.begin(), res.end(), comp);

  return res;
}

int main() {
  root = new Node();
  vector <string> words = {"i love you", "island","ironman", "i love leetcode"};
  vector <int> times = {5, 3, 2 , 2};
  autoCompleteSystem(words, times);

  string inp = "i a#irxy#is#i love yi#";

  for (int i = 0; i < inp.size(); i++) {
    vector <string> res = input(inp[i]);
    if ((int)res.size() == 0) {
      cout << "empty" << "\n";
    } else {
      for (int i = 0; i < min(3, (int)res.size()); i++) {
        cout << res[i] << "\n";
      }
    }
    cout << "----------" << "\n";
  }
  return 0;
}
