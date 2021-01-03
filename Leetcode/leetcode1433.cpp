class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end()); 
        sort(s2.begin(), s2.end());
        int l = s1.size(), x = 0, y = 0;
        for (int i = 0; i < l; i++) {
            if(s1[i] >= s2[i]) x++;
            if(s1[i] <= s2[i]) y++;
        }
        if(x == l || y == l) return true;
        return false;
    }
};
