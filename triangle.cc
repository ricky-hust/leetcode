//采用自底向上的方法用dp来完成，result保存自底向上的最小和
//时间复杂度O(numRows*numRows)，空间复杂度O(numRows)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int numRows=triangle.size();
        vector<int> result(numRows,0);
        for(int i=0;i<numRows;i++) {
            result[i]=triangle[numRows-1][i];
        }
        for(int i=numRows-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                int p=triangle[i][j]+result[j];
                int k=triangle[i][j]+result[j+1];
                result[j]=(p<k) ? p : k;
            }
        }
        return result[0];
    }
};

//自顶向下，和上面类似，注意每行两边的需要不一样的处理
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int numRows=triangle.size();
        for(int i=1;i<numRows;i++) {
            triangle[i][0]+=triangle[i-1][0];
            for(int j=1;j<i;j++) {
                int p=triangle[i][j]+triangle[i-1][j];
                int k=triangle[i][j]+triangle[i-1][j-1];
                triangle[i][j]=p<k ? p : k;
            }
            triangle[i][i]+=triangle[i-1][i-1];
        }
        int min=triangle[numRows-1][0];
        for(int i=1;i<numRows;i++) {
            if(triangle[numRows-1][i]<min)
                min=triangle[numRows-1][i];
        }
        return min;
    }
};
