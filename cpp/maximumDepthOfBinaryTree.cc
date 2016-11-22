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
    int max;
    void DFS(TreeNode* root,int level) {
        if(root->left==NULL && root->right==NULL) {
            if(level>max)
                max=level;
        }
        if(root->left!= NULL)
            DFS(root->left,level+1);
        if(root->right != NULL)
            DFS(root->right,level+1);
    }
    int maxDepth(TreeNode* root) {
        max=INT_MIN;
        if(root != NULL)
            DFS(root,1);
        else
            max=0;
        return max;
    }
};
