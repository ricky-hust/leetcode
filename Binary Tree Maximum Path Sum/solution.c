/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 #define max(a,b) (((a)>(b))?(a):(b))
 
 int maxPathSumHelper(struct TreeNode *root,int *maxSum)
 {
    if(NULL==root)
        return 0;
    int lsum=maxPathSumHelper(root->left,maxSum);
    int rsum=maxPathSumHelper(root->right,maxSum);
    int sum = max(root->val, max(root->val+lsum, root->val+rsum));
    *maxSum = max(*maxSum, max(root->val+lsum+rsum, sum));
    return sum;
 }
 
int maxPathSum(struct TreeNode *root) {
    int maxSum=INT_MIN;
    maxPathSumHelper(root,&maxSum);
    return maxSum;
}