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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int low,int high) {
        if(low>high)
            return NULL;
        if(low==high) {
            TreeNode* root=new TreeNode(nums[low]);
            return root;
        }
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBSTHelper(nums,low,mid-1);
        root->right=sortedArrayToBSTHelper(nums,mid+1,high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }
};
