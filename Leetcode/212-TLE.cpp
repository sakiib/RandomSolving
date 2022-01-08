
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)), v.erase(unique(ALL(v)), v.end())

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
  TrieNode* getRoot() {
    return root;
  }
  void insert(string word) {
    int len = word.size();
    TrieNode *temp = root;
    for (int i = 0; i < len; i++) {
      int idx = word[i] - 'a';
      if (temp -> next[idx] == nullptr) {
        temp -> next[idx] = new TrieNode();
      }
      temp = temp -> next[idx];
    }
    temp -> isWord = true;
  }
  bool find(string word) {
    int len = word.size();
    TrieNode *temp = root;
    for (int i = 0; i < len; i++) {
      int idx = word[i] - 'a';
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
  vector <string> res;

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie *trie = new Trie();
    for (auto word: words) {
      trie -> insert(word);
    }
    TrieNode *root = trie -> getRoot();

    int row = board.size(), col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        findWords(i, j, row, col, board, "", root);
      }
    }

    UNIQUE(res);
    return res;
  }

private:
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  void findWords(int r, int c, int row, int col, vector<vector<char>>& board, string word, TrieNode *root) {
    if (root -> next[board[r][c] - 'a'] != nullptr) {
      word += board[r][c];
      root = root -> next[board[r][c] - 'a'];
      if (root -> isWord) {
        res.push_back(word);
      }

      char cur = board[r][c];
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if (nr >= 0 && nc >= 0 && nr < row && nc < col && board[nr][nc] != '#' && root -> next[board[nr][nc] - 'a']) {
          board[r][c] = '#';
          findWords(nr, nc, row, col, board, word, root);
        }
      }
      board[r][c] = cur;
    }
  }
};
