class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int w[m][n];
        for (int i=0;i<m;i++){
            w[i][n-1] = 1;
        }
        for (int j=0;j<n;j++){
            w[m-1][j] = 1;
        }
        
        for (int i=m-2;i>=0;i--){
            for (int j=n-2;j>=0;j--){
                w[i][j] = w[i+1][j]+w[i][j+1];
            }
        }
        return w[0][0];
    }
};
