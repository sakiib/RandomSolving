class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto val: bills) {
            if (val == 5) {
                five++;
            } else if (val == 10) {
                if (five) {
                    ten++;
                    five--;
                } else {
                    return false;
                }
            } else {
                if (ten && five) {
                    twenty++;
                    ten--;
                    five--;
                } else if (five >= 3) {
                    twenty++;
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
