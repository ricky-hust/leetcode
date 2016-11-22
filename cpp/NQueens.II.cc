class Solution {
public:
    int num;
    bool isAttack(vector<vector<int>>& sol,int row,int col) {
        for(int i=0;i<row;i++) {
            if(sol[i][col])
                return true;
        }
        for(int i=row-1,j=col-1;(i>=0) && (j>=0);i--,j--) {
            if(sol[i][j])
                return true;
        }
        int n=sol.size();
        for(int i=row-1,j=col+1;(i>=0) && (j<n);i--,j++) {
            if(sol[i][j])
                return true;
        }
        return false;
    }
    void totalNQueensHelper(int n, int k, vector<vector<int>>& sol) {
        if(k == n) {
            num++;
            return;
        }
        for(int i=0;i<n;i++) {
            sol[k][i]=1;
            if(!isAttack(sol,k,i))
                totalNQueensHelper(n,k+1,sol);
            sol[k][i]=0;
        }
    }
    int totalNQueens(int n) {
        num=0;
        vector<vector<int>> sol(n,vector<int>(n,0));
        totalNQueensHelper(n,0,sol);
        return num;
    }
};
