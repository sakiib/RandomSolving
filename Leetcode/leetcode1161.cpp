class Solution {
public:
    int sum[ 10005 ];

    void solve( TreeNode* cur , int lvl ) {
        if( cur == NULL ) return;
        sum[lvl] += cur -> val;
        if( cur -> left != NULL ) solve( cur -> left , lvl + 1 );
        if( cur -> right != NULL ) solve( cur -> right , lvl + 1 );
    }
    int maxLevelSum(TreeNode* root) {
        solve( root , 1 );
        int mx = -1000000000 , ans = 0;
        for( int i = 1; i <= 10000; i++ ) {
            if( sum[i] > mx ) mx = sum[i] , ans = i;
        }
        return ans;
    }
} s;
