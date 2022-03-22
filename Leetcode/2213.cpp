const int N = 1e5 + 5;

struct Node {
  int mx;
  int st, en;
  int leftMostIdx, rightMostIdx;
  Node() {
    mx = 0;
    st = -1, en = -1;
    leftMostIdx = -1, rightMostIdx = -1;
  }
}
tree[4 * N];

Node combine(Node l, Node r, string & s) {
  Node ret = Node();
  if (s[l.en] == s[r.st]) {
    ret.mx = max(l.mx, max(r.mx, r.leftMostIdx - l.rightMostIdx + 1));

    if (l.leftMostIdx == l.en) {
      ret.leftMostIdx = r.leftMostIdx;
    } else {
      ret.leftMostIdx = l.leftMostIdx;
    }

    if (r.leftMostIdx == r.en) {
      ret.rightMostIdx = l.rightMostIdx;
    } else {
      ret.rightMostIdx = r.rightMostIdx;
    }

    ret.st = l.st;
    ret.en = r.en;

  } else {
    ret.mx = max(l.mx, r.mx);
    ret.leftMostIdx = l.leftMostIdx;
    ret.rightMostIdx = r.rightMostIdx;
    ret.st = l.st;
    ret.en = r.en;
  }

  return ret;
}

void build(int node, int b, int e, string & s) {
  if (b == e) {
    tree[node].mx = 1;
    tree[node].st = b, tree[node].en = b;
    tree[node].leftMostIdx = b, tree[node].rightMostIdx = b;
    return;
  }
  int l = node << 1, r = l | 1, m = (b + e) >> 1;
  build(l, b, m, s);
  build(r, m + 1, e, s);
  tree[node] = combine(tree[l], tree[r], s);
}

void update(int node, int b, int e, int pos, char ch, string & s) {
  if (pos > e || pos < b || b > e) {
    return;
  }
  if (pos == b && b == e) {
    s[pos] = ch;
    tree[node].mx = 1;
    tree[node].st = b, tree[node].en = b;
    tree[node].leftMostIdx = b, tree[node].rightMostIdx = b;
    return;
  }
  int l = node << 1, r = l | 1, m = (b + e) >> 1;
  update(l, b, m, pos, ch, s);
  update(r, m + 1, e, pos, ch, s);
  tree[node] = combine(tree[l], tree[r], s);
}

class Solution {
  public:
    vector < int > longestRepeating(string s, string queryCharacters, vector < int > & queryIndices) {
      int len = s.size();
      s = "#" + s;
      build(1, 1, len, s);
      vector < int > ans;
      for (int i = 0; i < queryCharacters.size(); i++) {
        update(1, 1, len, queryIndices[i] + 1, queryCharacters[i], s);
        ans.push_back(tree[1].mx);
      }
      return ans;
    }
};
