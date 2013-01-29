//dynamic programming O(nm) 

class Solution {
public:
    int numDistinct(string s, string t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int m = t.size();
        int w[n+1][m+1];
        
        for (int j=1;j<=m;j++) w[0][j] = 0;
        for (int i=0;i<=n;i++) w[i][0] = 1;
        
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (s[n-i] == t[m-j]){
                    w[i][j] = w[i-1][j]+w[i-1][j-1];
                } else {
                    w[i][j] = w[i-1][j];
                }
            }
        }
        return w[n][m];
    }
};
