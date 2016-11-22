/** ###
 * 这个题也是一个递归，只是这个递归与root无关
 * 递归函数的定义为left为root的子树和right为root的子树对称
 * left和right对称要求left->left和right->right,left->right和right->left对称
 */

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
    bool isSymmetricHelper(TreeNode* left,TreeNode* right) {
        if(left==NULL && right==NULL)
            return true;
        return (left!=NULL && right!=NULL && (left->val == right->val) && isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root != NULL)
            return isSymmetricHelper(root->left,root->right);
            
    }
};
