//典型的分治递归解决一个看似复杂的问题
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSumHelper(struct TreeNode *root,int &maxSum)
    {
        if(NULL==root)
            return 0;
        int lsum=maxPathSumHelper(root->left,maxSum);
        int rsum=maxPathSumHelper(root->right,maxSum);
        int sum = max(root->val, max(root->val+lsum, root->val+rsum));
        maxSum = max(maxSum, max(root->val+lsum+rsum, sum));
        return sum;
    }
 
    int maxPathSum(struct TreeNode *root) {
        int maxSum=INT_MIN;
        maxPathSumHelper(root,maxSum);
        return maxSum;
    }
};
