class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int  m = grid.size();
        int n = grid[0].size();
        
        int f[m][n];
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i == 0 && j == 0) {
                    f[i][j] = grid[i][j];
                }else if (i == 0 && j != 0) {
                    f[i][j] = f[i][j-1]+grid[i][j];
                } else if ( i != 0 && j == 0) {
                    f[i][j] = f[i-1][j]+grid[i][j];
                } else {
                    f[i][j] = min(f[i][j-1],f[i-1][j])+grid[i][j];
                }
                
            }
        }
        
        return f[m-1][n-1];
    }
};
