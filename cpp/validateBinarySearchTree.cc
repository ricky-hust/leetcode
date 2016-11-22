/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//中序遍历加记录pre指针，同时返回值作为状态
class Solution {
public:
    TreeNode *pre;
    bool inOrder(TreeNode* cur) {
        if(!cur)
            return true;
        if(!inOrder(cur->left))
            return false;
        if(pre) {
            if(pre->val >= cur->val)
                return false;
        }
        pre=cur;
        if(!inOrder(cur->right))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }
};

//非递归中序遍历获得遍历结果，然后检查，不是很好的解法
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur != NULL || s.size() > 0) {
            if(cur != NULL) {
                s.push(cur);
                cur=cur->left;
            } else {
                cur=s.top();s.pop();
                v.push_back(cur->val);
                cur=cur->right;
            }
        }
        
        for(int i=0; v.size()>0 && i<v.size()-1; i++){
            if (v[i] >= v[i+1]) {
            return false;
            }
        }
        return true;
    }
};
