int Set(int N, int pos) {
  return N |= (1 << pos);
}

int Reset(int N, int pos) {
  return N = N & ~(1 << pos);
}

bool Check(int N, int pos) {
  return (bool)(N & (1 << pos));
}

int Toggle(int N, int pos) {
  return (N ^= (1 << pos));
}

class TrieNode {
public:
  bool isWord;
  TrieNode* next[26];
  TrieNode() {
    isWord = false;
    for (int i = 0; i < 26; i++) {
      next[i] = nullptr;
    }
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() {
    root = new TrieNode();
  }
  void insert(int num) {
    TrieNode *temp = root;
    for (int i = 0; i < 26; i++) {
      int idx = Check(num, i)? 1: 0;
      if (temp -> next[idx] == nullptr) {
        temp -> next[idx] = new TrieNode();
      }
      temp = temp -> next[idx];
    }
    temp -> isWord = true;
  }
  bool find(int num) {
    TrieNode *temp = root;
    for (int i = 0; i < 26; i++) {
      int idx = Check(num, i)? 1: 0;
      if (temp -> next[idx] == nullptr) {
        return false;
      }
      temp = temp -> next[idx];
    }
    return temp -> isWord;
  }
};

class Solution {
public:
  int mask(string word) {
    int num = 0;
    for (int i = 0; i < (int) word.size(); i++) {
      num = Set(num, word[i] - 'a');
    }
    return num;
  }

  int wordCount(vector <string> &startWords, vector <string> &targetWords) {
    Trie * trie = new Trie();

    for (auto word: startWords) {
      trie -> insert(mask(word));
    }

    int ans = 0;
    for (auto word: targetWords) {
      for (int i = 0; i < (int) word.size(); i++) {
        string s = word.substr(0, i) + word.substr(i + 1);
        if (trie -> find(mask(s))) {
          ans++;
          break;
        }
      }
    }

    return ans;
  }
};
