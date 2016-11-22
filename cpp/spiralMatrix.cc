//比较tricky的dfs应用场景
class Solution {
private:
    int step[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0} };
    int row,col;
public:
    void dfs(vector<vector<int>> &matrix, vector<int> &result, vector<vector<int>> &visited, int x, int y, int dir) {
        result.push_back(matrix[x][y]);
        visited[x][y]=1;
        for(int i=0;i<4;i++) {
            int ndir=(dir+i)%4;
            int nx=x+step[ndir][0],ny=y+step[ndir][1];
            if(nx>=0 && nx<row && ny>=0 && ny<col && visited[nx][ny]==0) {
                dfs(matrix,result,visited,nx,ny,ndir);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        row=matrix.size(),col=matrix[0].size();
        cout<<row<<col<<endl;
        vector<vector<int>> visited(row,vector<int>(col,0));
        dfs(matrix,result,visited,0,0,0);
        return result;
    }
};
