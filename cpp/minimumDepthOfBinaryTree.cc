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
    int min;
    void DFS(TreeNode* root,int level) {
        if(root->left == NULL && root->right == NULL) {
            if(level<min)
                min=level;
        }
        if(root->left != NULL)
            DFS(root->left,level+1);
        if(root->right != NULL) 
            DFS(root->right,level+1);
    }
    int minDepth(TreeNode* root) {
        min=INT_MAX;
        if(root != NULL) 
            DFS(root,1);
        else
            min=0;
        return min;
    }
};
