//dfs
class Solution {
public:
    int rows,cols;
    void dfs(int m,int n,vector<vector<char>>& grid) {
        if(m<0 || m>=rows || n<0 || n>=cols || grid[m][n]=='0')
            return;
        grid[m][n]='0';
        //up down left right
        dfs(m-1,n,grid);
        dfs(m+1,n,grid);
        dfs(m,n-1,grid);
        dfs(m,n+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        rows=grid.size();
        cols=grid[0].size();
        int result=0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]=='1') {
                    result++;
                    dfs(i,j,grid);
                }
            }
        }
        return result;
    }
};
