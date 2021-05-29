class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map <int, int> have;
        for (int i = 0; i < arr.size(); i++) {
            if (abs(arr[i]) % 2 == 0 && have.count(arr[i] / 2)) {
                return true;
            } 
            if (have.count(arr[i] * 2)) {
                return true;
            }
            have[arr[i]] = true;
        }
        return false;
    }
};
