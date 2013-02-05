class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int w[m][n];
        
        //init it to all zeros
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                w[i][j] = 0;
        
        //stop when found first obstacle in most right col
        for (int i=m-1;i>=0;i--){
            if (obstacleGrid[i][n-1]==1) break;
            w[i][n-1] = 1;
        }
        
        //stop when found first obstacle in very bottom row
        for (int j=n-1;j>=0;j--){
            if (obstacleGrid[m-1][j]==1) break;
            w[m-1][j] = 1;
        }
        
        for (int i=m-2;i>=0;i--){
            for (int j=n-2;j>=0;j--){
                if (obstacleGrid[i][j]==1){
                    w[i][j] = 0;
                }else {
                    w[i][j] = w[i+1][j] + w[i][j+1];
                }
            }
        }
        return w[0][0];
    }
};
