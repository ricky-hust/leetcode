//DFS+回溯
//DFS一般用来解决状态空间内的搜索问题
//回溯一般是根据具体问题需要进行回到最初的状态才会需要
class Solution {
public:
    vector<vector<string>> vv;
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
    void solveNQueensHelper(int n,int k,vector<vector<int>>& sol) {
        if(k == n) {
            vector<string> vs;
            for(int i=0;i<n;i++) {
                string s;
                for(int j=0;j<n;j++) {
                    s+=((sol[i][j]) ? "Q" : ".");
                }
                vs.push_back(s);
            }
            vv.push_back(vs);
            return;
        }
        for(int i=0;i<n;i++) {
            sol[k][i]=1;
            if(!isAttack(sol,k,i))
                solveNQueensHelper(n,k+1,sol); //dfs
            sol[k][i]=0; //backtracking
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> sol(n,vector<int>(n,0)); //初始化
        solveNQueensHelper(n,0,sol);
        return vv;
    }
};
