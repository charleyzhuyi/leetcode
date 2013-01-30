class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size()+s2.size() != s3.size()) return false;
        int n=s1.size();
        int m=s2.size();
        int z=s3.size();
        int w[n+1][m+1];
        for (int i=0;i<=n;i++){
            if (s1.substr(n-i) == s3.substr(z-i)) w[i][0] = true;
            else w[i][0] = false;
        }
        for (int j=0;j<=m;j++){
            if ( s2.substr(m-j) == s3.substr(z-j)) w[0][j] = true;
            else  w[0][j] = false;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s1[n-i] != s3[z-i-j] && s2[m-j] != s3[z-i-j]) w[i][j] = false;
                else if (s1[n-i] == s3[z-i-j] && s2[m-j] == s3[z-i-j])  w[i][j] =  w[i-1][j] || w[i][j-1];
                else if (s1[n-i] == s3[z-i-j])  w[i][j] = w[i-1][j];
                else  w[i][j] = w[i][j-1]; 
            }
        }
        return w[n][m];
    }
};
