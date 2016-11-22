/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//dfs
class Solution {
public:
    vector<vector<int>> vv;
    void DFS(TreeNode* ptn,vector<int> v) {
        v.push_back(ptn->val);
        if(ptn->left == NULL && ptn->right == NULL) {
            int s=0;
            for(auto it=v.begin();it!=v.end();it++) {
                s+=*it;
            }
            if(s==su)
                vv.push_back(v);
            return;
        }
        if(ptn->left != NULL)
            DFS(ptn->left,v);
        if(ptn->right != NULL)
            DFS(ptn->right,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        su=sum;
        if(root != NULL)
            DFS(root,{});
        return vv;
    }
private:
    int su;
};
