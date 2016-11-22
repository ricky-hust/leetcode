class Solution {
private:
    int step[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0} };
    int t;
public:
    void dfs(vector<vector<int>> &result,vector<vector<int>> &visited,int n,int x,int y,int dir) {
        result[x][y]=t++;
        visited[x][y]=1;
        for(int i=0;i<4;i++) {
            int ndir=(dir+i)%4;
            int nx=x+step[ndir][0],ny=y+step[ndir][1];
            if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]==0) {
                dfs(result,visited,n,nx,ny,ndir);
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n<=0) return result;
        vector<vector<int>> visited(n,vector<int>(n,0));
        result=visited;
        t=1;
        dfs(result,visited,n,0,0,0);
        return result;
    }
};
