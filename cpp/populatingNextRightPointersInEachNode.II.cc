/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//使用bfs来完成，关键需要记录每一层次的最后一个节点
//prev记录当前cur的前驱节点，对于第一个节点有冗余操作
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> Q;
        TreeLinkNode *prev,*last,*cur;
        Q.push(root);
        prev=last=root;
        while(!Q.empty()) {
            cur=Q.front(); Q.pop();
            if(cur->left != NULL)
                Q.push(cur->left);
            if(cur->right != NULL)
                Q.push(cur->right);
            prev->next=cur;
            if(cur==last) {
                cur->next=NULL;
                prev=Q.front();
                last=Q.back();
            } else {
                prev=cur;
            }
        }
    }
};
