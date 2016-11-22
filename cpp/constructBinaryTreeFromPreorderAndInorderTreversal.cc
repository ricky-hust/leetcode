/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//简单的递归即可解决
class Solution {
public:
    TreeNode* buildTreeHelper(auto pFirst , auto pLast , auto iFirst , auto iLast) {
        if(pFirst == pLast) return NULL;
        if(iFirst == iLast) return NULL;
        
        int val = *pFirst;
        auto iRoot = find(iFirst , iLast , val);
        
        TreeNode* root = new TreeNode(*iRoot);
        
        int leftSize = iRoot - iFirst;
        root -> left = buildTreeHelper(pFirst+1 , pFirst+leftSize+1 , iFirst , iRoot);
        root -> right = buildTreeHelper(pFirst+leftSize+1 , pLast , iRoot + 1 , iLast);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = inorder.size();
        if(size == 0) return NULL;
        return buildTreeHelper(preorder.begin() , preorder.end() , inorder.begin() , inorder.end());
    }
};
