class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[ 100005 ];
        memset( dp , false , sizeof( dp ) );
        dp[0] = true;
        for( int i = 0; i < nums.size(); i++ ) {
            if( !dp[i] ) continue;
            for( int l = 1; l <= nums[i]; l++ ) {
                dp[i + l] = true;
            }
        }
        return dp[nums.size() - 1];
    }
};
