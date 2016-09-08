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
    bool dfs(TreeNode* root,int add_sum,int sum) {
        add_sum+=root->val;
        if(root->left==NULL && root->right==NULL) {
            if(add_sum == sum)
                return true;
            else
                return false;
        }
        if((root->left && dfs(root->left,add_sum,sum)) || (root->right && dfs(root->right,add_sum,sum)))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return dfs(root,0,sum);
    }
};

//bfs
//使用TreeNode中的val字段来记录bfs过程中的状态，略tricky
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode*> s;
        if(root != NULL)
            s.push(root);
        while(!s.empty()) {
            TreeNode* cur=s.top();s.pop();
            if(cur->left ==  NULL && cur->right == NULL) {
                if(cur->val == sum)
                    return true;
            }
            if(cur->left != NULL) {
                cur->left->val += cur->val;
                s.push(cur->left);
            }
            if(cur->right != NULL) {
                cur->right->val += cur->val;
                s.push(cur->right);
            }
        }
        return false;
    }
};
