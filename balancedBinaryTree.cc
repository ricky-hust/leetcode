/**
 * 这个题最直接的方法是计算left和right的高度是否符合要求，
 * 同时检查left和right子树是否也是bst，这样会导致很多冗余计算；
 * 这里选择使用后续遍历，遍历过程中记录深度信息
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
    bool postOrder(TreeNode* root,int &depth) {
        if(root==NULL) {
            depth=0;
            return true;
        }
        int ldepth,rdepth;
        if(postOrder(root->left,ldepth) && postOrder(root->right,rdepth)) {
            int diff=abs(ldepth-rdepth);
            if(diff > 1)
                return false;
            depth=1+(ldepth>rdepth?ldepth:rdepth);
            return true;
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int depth;
        return postOrder(root,depth);
    }
};
