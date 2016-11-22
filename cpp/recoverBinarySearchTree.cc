/** ####
 * 这个题使用中序遍历过程中来寻找
 * 中序遍历中记录pre这个访问的前一个节点
 * 当检测到乱序记录即可
 * 这个算法使用了递归，空间复杂度非O(1)
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
    TreeNode *fst,*snd,*pre;
    void inOrder(TreeNode* cur) {
        if(!cur)
            return;
        inOrder(cur->left);
        if(pre) {
            if(pre->val > cur->val) {
                if(!fst)
                    fst=pre;
                snd=cur;
            }
        }
        pre=cur;
        inOrder(cur->right);
    }
    void recoverTree(TreeNode* root) {
        fst=snd=pre=NULL;
        inOrder(root);
        if(fst && snd)
            swap(fst->val,snd->val);
    }
};
