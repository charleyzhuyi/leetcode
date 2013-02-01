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

/* Another way of doing it */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        int w[m][n];
        //Base Case
        w[m-1][n-1] = grid[m-1][n-1];
        for (int i=m-2;i>=0;i--) w[i][n-1] = w[i+1][n-1]+grid[i][n-1];
        for (int j=n-2;j>=0;j--) w[m-1][j] = w[m-1][j+1]+grid[m-1][j];
        for (int i=m-2;i>=0;i--)
            for (int j=n-2;j>=0;j--)
                w[i][j] = min(w[i+1][j],w[i][j+1])+grid[i][j];
           
        return w[0][0];
    }
};
