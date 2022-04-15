#include <bits/stdc++.h>
using namespace std;

const int k = 3;

struct Node {
  Node *next[27];
  set <pair <string, int> > words;
  Node() {
    for (int i = 0; i < 27; i++) {
      next[i] = nullptr;
    }
    words.clear();
  }
} *root;

int getID(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return ch - 'a';
  }
  return 26;
}

void insert(string word, int cnt) {
  Node *cur = root;
  for (int i = 0; i < word.size(); i++) {
    int id = getID(word[i]);
    if (cur -> next[id] == nullptr) {
      cur -> next[id] = new Node();
    }
    cur = cur -> next[id];
    cur -> words.insert({word, -cnt});
    if ((int)cur -> words.size() > k) {
      auto it = cur -> words.end(); --it;
      cur -> words.erase(it);
    }
  }
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
    insert(words[i], times[i]);
  }
}

string word;

vector <string> input(char ch) {
  if (ch == '#') {
    Node *temp = search(word);
    if (temp == nullptr) {
      insert(word, -1);
    } else {
      int cnt = 0;
      for (auto x: temp -> words) {
        if (x.first == word) {
          cnt = x.second;
          break;
        }
      }
      temp -> words.erase({word, cnt});
      temp -> words.insert({word, cnt - 1});
    }
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
    res.push_back(w.first);
  }

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
      for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << "\n";
      }
    }
    cout << "----------" << "\n";
  }
  return 0;
}
