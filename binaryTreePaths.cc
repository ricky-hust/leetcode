/** ##
 * dfs
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
    vector<string> result;
    //can not use string &s!
    void dfs(TreeNode* root,string s) {
        s+=("->"+to_string(root->val));
        if(root->left==NULL && root->right==NULL) {
            result.push_back(s);
            return;
        }
        if(root->left)
            dfs(root->left,s);
        if(root->right)
            dfs(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return result;
        dfs(root,"");
        for(int i=0;i<result.size();i++)
            result[i].erase(result[i].begin(),result[i].begin()+2);
        return result;
    }
};
