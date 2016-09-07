/*************************
* 这是一个一维DP问题
* result[i]表示有i个节点的BST的个数
* result[i]可以通过分别有0,1,2...(i-1)个child来获得
*************************/

class Solution {
public:
    int numTrees(int n) {
        if(n < 2)
            return 1;
        vector<int> result(n+1,0);
        result[0]=1;
        result[1]=1;
        for(int i=2;i<=n;i++) {
            for(int j=0;j<i;j++) {
                result[i] += result[j]*result[i-j-1];
            }
        }
        return result[n];
    }
};
