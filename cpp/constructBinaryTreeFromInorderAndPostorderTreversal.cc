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
    TreeNode* buildTreeHelper(auto iBegin,auto iEnd,auto pBegin,auto pEnd) {
        if(pBegin == pEnd)
            return NULL;
        
        int val=*(pEnd-1);
        TreeNode* root=new TreeNode(val);
        
        auto it=find(iBegin,iEnd,val);
        int leftSize=it-iBegin;
        root->left=buildTreeHelper(iBegin,iBegin+leftSize,pBegin,pBegin+leftSize);
        root->right=buildTreeHelper(iBegin+leftSize+1,iEnd,pBegin+leftSize,pEnd-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        TreeNode* root=buildTreeHelper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
        return root;
    }
};
