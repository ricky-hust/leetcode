/** #####
 * 这个题是一个递归的题，需要好好理解 
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
    vector<TreeNode*> generateTrees(int low, int high) {
        vector<TreeNode*> result;
        if(low>high || high<low) {
            result.push_back(NULL);
            return result;
        }
        if(low==high) {
            TreeNode* ptn=new TreeNode(low);
            result.push_back(ptn);
            return result;
        }
        for(int t=low;t<=high;t++) {
            vector<TreeNode*> vleft=generateTrees(low,t-1);
            vector<TreeNode*> vright=generateTrees(t+1,high);
            for(int i=0;i<vleft.size();i++) {
                for(int j=0;j<vright.size();j++) {
                    TreeNode* root=new TreeNode(t);
                    root->left=vleft[i];
                    root->right=vright[j];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n<=0)
            return result;
        result=generateTrees(1,n);
        return result;
    }
};
