/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBSTHelper(ListNode* head,int len) {
        if(len == 0)
            return NULL;
        if(len == 1) {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* mid=head;
        for(int i=0;i<(len/2);i++) {
            mid=mid->next;   
        }
        TreeNode* root=new TreeNode(mid->val);
        root->left=sortedListToBSTHelper(head,len/2);
        root->right=sortedListToBSTHelper(mid->next,(len-1)/2);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size=0;
        ListNode* cur=head;
        while(cur!=NULL) {
            size++;
            cur=cur->next;
        }
        return sortedListToBSTHelper(head,size);
    }
};
