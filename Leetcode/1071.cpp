class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int val = str1.size();
        vector <int> d;
        
        for (int i = 1; i * i <= val; i++) {
            if (val % i == 0) {
                d.push_back(i);
                if (val / i != i) d.push_back(val / i);
            }
        }
        
        auto ok = [&](string s) {
            int len = s.size();
            if ((int)str2.size() % len != 0) return false;
            
            for (int i = 0; i < str1.size(); i += len) {
                if (str1.substr(i, len) != s) return false;
            }
            
            for (int i = 0; i < str2.size(); i += len) {
                if (str2.substr(i, len) != s) return false;
            }
            
            return true;
        };
        
        sort(d.begin(), d.end());
        
        string ans = "";
        for (auto x: d) {
            string s = str1.substr(0, x);
            if (ok(s)) ans = s;
        }
        
        return ans;
    }
};
